#include "planes.h"
#include <conio.h>

//#define WIRE
//#define LIGHTING

dVector getHorizontalAngleDVec(dVector vec)
{
    dVector angle;

    f32 tmp = atan2(vec.m_x, vec.m_z) * 180.0f / 3.1416;//3.1416 é o Pi;
	angle.m_y = tmp;

	if (angle.m_y < 0)
        angle.m_y += 360;
    if (angle.m_y >= 360)
        angle.m_y -= 360;

    f32 z1 = sqrt(vec.m_x * vec.m_x + vec.m_z * vec.m_z);
    angle.m_x = atan2(z1, vec.m_y) * 180.0f / 3.1416 - 90.0;

    if (angle.m_x < 0)
        angle.m_x += 360;
    if (angle.m_x >= 360)
        angle.m_x -= 360;

    return angle;
};

void SEngineFighter::updateScene (const NewtonBody* body, const dFloat * timestep, int thread)
{
	float matrix[16];
    SEngineFighter * player;
	player = (SEngineFighter*) NewtonBodyGetUserData(body);

    IMeshSceneNode * node = player->gra_sPieces[player->fuselageIndex];

	NewtonBodyGetMatrix(body, matrix);

	CMatrix4<float> mat;
	memcpy(mat.pointer(), matrix, sizeof(float) * 16);

	node->setPosition(mat.getTranslation());
	node->setRotation(mat.getRotationDegrees());
};

void SEngineFighter::applyForce (const NewtonBody* body, dFloat timestep, int thread)
{
    SEngineFighter * player;
	player = (SEngineFighter*) NewtonBodyGetUserData(body);
	stringw *nome;
	nome = player->recName;

    dMatrix matrix = GetIdentityMatrix();

    dFloat mass;
    dFloat Ixx;
    dFloat Iyy;
    dFloat Izz;

    dVector force (0.0f, 0.0f, 0.0f);
    dVector torque (0.0f, 0.0f, 0.0f);
    dVector speed (0.0f, 0.0f, 0.0f);
    dVector speedRotated (0.0f, 0.0f, 0.0f);
    dVector omega (0.0f, 0.0f, 0.0f);
    dVector drag (0.0f, 0.0f, 0.0f);

    f32 forceUp = 0.0f;
    f32 gearTorque = 0.0f;
    f32 mGearTorque = 0.0f;
    f32 pitchForce = 0.0f;
    f32 landPitchForce = 0.0f;
    f32 engineForce = 0.0f;
    f32 liftForce = 0.0f;
    f32 rollForce = 0.0f;
    f32 yawForce = 0.0f;
    f32 landYawForce = 0.0f;
    f32 flapForce = 0.0f;
    f32 onlandTorque = 0.0f;
    f32 lateralGrip = 0.0f;

 	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);
    NewtonBodyGetVelocity(body,&speed.m_x);
    NewtonBodyGetOmega(body,&omega.m_x);
    NewtonBodyGetMatrix(body,&matrix[0][0]);

    speedRotated = matrix.UnrotateVector(speed);
    omega = matrix.UnrotateVector(omega);
    player->getSpeedRot.X = speedRotated.m_x;
    player->getSpeedRot.Y = speedRotated.m_y;
    player->getSpeedRot.Z = speedRotated.m_z;

    ///FORÇA DE PROPULSÃO DO MOTOR
    engineForce = player->accell * player->enginePower;

    ///FORÇA DOS TRENS DE POUSO NO CHÃO
    //FORÇA DOS TRENS PRINCIPAIS
    for (u16 i = 0; i < player->lGear.size(); i++)
    {
        if(player->lGearHeight[i])
        {
            if (player->gearFunc[i] != 'A')
            {
                forceUp += player->lGearHeight[i] * 350000 - speed.m_y * 30000;
                mGearTorque += speed.m_z - 200;
                drag.m_z += -speedRotated.m_z * 500;
                //drag.m_z += -speedRotated.m_z * 50;
                landPitchForce = -speedRotated.m_y * 100 - omega.m_x * 2000;
                onlandTorque += player->lGear[i].end.X * 10000 / speedRotated.m_z - omega.m_z * 1000;
                //onlandTorque += player->lGear[i].end.X * 10000 / speedRotated.m_z - omega.m_z * 1000;
                lateralGrip = -speedRotated.m_x * 500;
            }
            else
            {
                ///Gambiarra para tirar o pau que o avião fica grudado no chão!!

                if(*nome == "thunderbolt")
                {
                    if(!player->motorLig || speedRotated.m_z<20)
                        forceUp = 90000.0f;
                }
                else if(*nome == "160C" && !player->acabouGasolina)
                {
                    if(!player->motorLig || speedRotated.m_z<20)
                        forceUp = 50000.0f;
                }
                else if(*nome == "747" && !player->acabouGasolina)
                {
                    if(!player->motorLig || speedRotated.m_z<20)
                        forceUp = 250000.0f;
                };

                    ///Coloquei a velocidade, para garantir que o avião saiu da inercia;
                gearTorque = player->lGearHeight[i] * 4000 - omega.m_x * 6000;
                if(player->motorLig && speedRotated.m_z>20 || player->acabouGasolina)
                    landYawForce = yawForce = player->yaw * speedRotated.m_z * 5.0f - omega.m_y * 10000;
            }
        }
    }

    ///FLAPES
    flapForce = player->flap * speedRotated.m_z;

    ///FORÇA DOS PROFUNDORES (PITCH)
    //pitchForce = player->pitch * speedRotated.m_z - omega.m_x * 3500 - speedRotated.m_y * 10;
    if(*nome == "747")
        pitchForce = player->pitch * speedRotated.m_z - omega.m_x * 3500 - speedRotated.m_y * 0.8;
    else
        pitchForce = player->pitch * speedRotated.m_z - omega.m_x * 3500 - speedRotated.m_y * 2;

    ///FORÇA DOS AILERONS (ROLL)
    if(player->motorLig && speedRotated.m_z>20 || player->acabouGasolina)
    {
        rollForce = player->roll * speedRotated.m_z * 1.5f - omega.m_z * 1000;


        ///FORÇA DO LEME VERTICAL (YAW)
        yawForce = player->yaw * speedRotated.m_z * 0.05f - omega.m_y * 1000;
    };

    ///FORÇA DE LIFTING (parece bom)
    dVector speedAngle = getHorizontalAngleDVec(speed);
    vector3df planeAngle = player->gra_sPieces[player->fuselageIndex]->getRotation();
    f32 attackAngle = speedAngle.m_x - planeAngle.X;
    //liftForce =  speedRotated.m_z * 800 + speedRotated.m_y * 500 * sin(attackAngle * 3.1416/180) * cos(attackAngle * 3.1416/180);
    if(*nome == "thunderbolt")
        liftForce =  speedRotated.m_z * 800 + speedRotated.m_y * 900 * sin(attackAngle * 3.1416/180) * cos(attackAngle * 3.1416/180);
    else if(*nome == "160C")
        liftForce =  speedRotated.m_z * 750 + speedRotated.m_y * 5000 * sin(attackAngle * 3.1416/180) * cos(attackAngle * 3.1416/180);
    else if(*nome == "747")
        liftForce =  speedRotated.m_z * 800 + speedRotated.m_y * 3000 * sin(attackAngle * 3.1416/180) * cos(attackAngle * 3.1416/180);
    ///ARRASTO
    drag.m_x = speedRotated.m_x * -1000;
    drag.m_y = speedRotated.m_y * -4000;
    drag.m_z += speedRotated.m_z * -100 - liftForce/10 - flapForce;
    ///CÔMPUTO DAS FORÇAS
    //FORÇAS DO AVIÃO
    force.m_z += engineForce + drag.m_z;
    force.m_y += liftForce + drag.m_y + flapForce;
    force.m_x += drag.m_x;
    torque.m_x += gearTorque + mGearTorque + pitchForce + landPitchForce;
    torque.m_y += yawForce + landYawForce + onlandTorque;
    torque.m_z += rollForce + onlandTorque + lateralGrip;
    force = matrix.RotateVector(force);
    torque = matrix.RotateVector(torque);

    //FORÇAS DE FONTES EXTERNAS
    force.m_y += GRAVITY * mass + forceUp;

    NewtonBodySetTorque (body, &torque.m_x);
    NewtonBodySetForce (body, &force.m_x);
    player->pontAc = speedRotated.m_z;




};

int SEngineFighter::readPlaneName(IReadFile * file, stringw name)
{
    while (file->getPos() < file->getSize())//IReadFile getPos ->Get the current position in the file.(Obter a posição atual no arquivo.
    {  //Enquanto a posição atual for menor q o tamanho do arquivo...    //getSiza -> Get size of file.  Recebe o tamanho do arquivo.
        char c = 0;
        stringw planeName;
        u16 i = 0;

        while (c != '{') //procura por um avião //Lê um byte do arquivo e armazena na variavel c;
            file->read(&c,1);//virtual s32 	read (void *buffer, u32 sizeToRead)=0  ->Reads an amount of bytes from the file. (Lê a quantidade de bytes do arquivo

        c = 0;

        while (c < 30) //pula caracteres de controle
            file->read(&c,1);

        file->seek(-1,true);//seek (long finalPos, bool relativeMovement=false)=0 ->Changes position in file.

        while (i < name.size())
        {
            file->read(&c,1);
            planeName.append(c);//Appends a string to this string.
            i++;
        };
        ///i = 11 (Já testado)
        if (planeName == name)
            return (file->getPos());///Retorna 15 (Testado)
        else
        {
            file->seek(-1 * name.size(),true); //rebobina a leitura do nome
            while (c != '}') //vai até o final desse avião
                file->read(&c,1);

            file->read(&c,1); //verifica se acabou o arquivo
            if (c == ';')
                return 0;
        };
    };
    return 0;
};

int SEngineFighter::findBlock(IReadFile * file)//EncontraBloco(findBlock)
{
    char c = 0;

    while (c < 30) //pula caracteres de controle
        file->read(&c,1);
    file->seek(-1,true);

    stringw block;
    for (int i = 0; i < 4; i++)//Creio que é 4 porque os nomes dos tipos possuem 4 letras (ENDB,STPI,WEAP...
    {
        file->read(&c,1);
        if (c == '}')
            return 100;
        block.append(c);
    };

    if (block == L"ENDB")
        return 1;
    else if (block == L"STPI")
        return 2;
    else if (block == L"WEAP") //se tem armas, não é civil.
    {
        civilian = false;
        return 3;
    }
    else if (block == L"MOBI")
        return 4;
    else if (block == L"COMM")
        return 5;
    else if (block == L"DATA")
        return 6;
    else
    {
        file->seek(-3,true);
        return 0;
    };
};

void SEngineFighter::readData(IReadFile * file)
{
    bool load = true;
    while (load)
    {
        //pula caracteres de controle
        char c = 0;
        while (c < 30)
            file->read(&c,1);
        file->seek(-1,true);

        stringw block;
        for (int i = 0; i < 4; i++)
        {
            file->read(&c,1);
            block.append(c);
        };
        file->seek(-4,true);

        if (block == L"ENDB")
        {
            load = false;
            break;
        }
        if (block == L"GEAR")
        {
            printf("GEAR \n");
            file->seek(4,true);
            readLGear(file);
        }
        if (block == L"MASS")
        {
            printf("MASS \n");
            file->seek(4,true);
            mass = readFloat(file);
        };
        if (block == L"INRT")
        {
            printf("INERTIAL MATRIX \n");
            file->seek(5,true);
            vector3df inert = readVec(file);
            Ixx = inert.X;
            Iyy = inert.Y;
            Izz = inert.Z;
        };
        if (block == L"ENGN")
        {
            printf("ENGINE \n");
            file->seek(4,true);
            enginePower = (u16)readFloat(file);
        };
    };
}

void SEngineFighter::readLGear(IReadFile * file)
{
    //pula caracteres de controle
    char c = 0;
    while (c < 30 || c==' ')
        file->read(&c,1);
    file->seek(-1,true);

    line3df lGearLine;
    lGearLine.end = readVec(file);
    lGearLine.start = vector3df(lGearLine.end.X, 0.0f, lGearLine.end.Z);
    lGear.push_back(lGearLine);
    lGearHeight.push_back(0.0f);

    c = 0;
    while (c < 30 || c==' ')
        file->read(&c,1);
    gearFunc.push_back(c);
};

void SEngineFighter::addMobilePart(IReadFile * file)
{
    printf("\n\n\n ----> PARTES MÓVEIS \n");
    bool load = true;

    while (load)
    {
        //pula caracteres de controle
        char c = 0;
        while (c < 30)
            file->read(&c,1);
        file->seek(-1,true);

        //verifica se acabou o bloco
        stringw block;
        for (int i = 0; i < 4; i++)
        {
            file->read(&c,1);
            block.append(c);
        };

        file->seek(-4,true);

        if (block == "ENDB")
        {
            load = false;
            break;
        }

        //monta a string de carga da peça
        stringw partLWO (L"models/");
        stringw mobPart (L"");

        partLWO.append (planeName);
        partLWO.append (L"/mob_");

        c = 0;
        while (c!= ' ')
        {
            file->read(&c,1);
            if(c!=' ')
                mobPart.append(c);
        }

        partLWO.append(mobPart);
        partLWO.append (L".x");

        mobIndex.push_back(mobPart);

        //carrega a peça
        ISceneManager * smgr = device->getSceneManager();
        u32 piece = mob_pieces.size();
        mob_pieces.push_back(smgr->addMeshSceneNode(smgr->getMesh(partLWO)));

         //aplica a posição e rotação
        mob_defPos.push_back(readVec(file));
        mob_defRot.push_back(readVec(file));
        mob_pieces[piece] -> setPosition(mob_defPos[piece]);
        mob_pieces[piece] -> setRotation(mob_defRot[piece]);
#ifdef WIRE
        mob_pieces[piece] -> setMaterialFlag(EMF_WIREFRAME,true);
#endif

#ifdef LIGHTING
    mob_pieces[piece] -> setMaterialFlag(EMF_LIGHTING,false);
#endif

        //saber quem é o parent
        stringw planePart (L"");
        c = 0;

        printf("PARTE MOVEL ");

        while (c != 13)
        {
            file->read(&c,1);
            if (c >= 30)
                planePart.append(c);
        }

        u16 i = 0;
        bool nFound = false;
        bool staticParent = true;

        //procurar nas partes estáticas
        while(planePart != pieceIndex[i])
        {
            i ++;
            if (i == pieceIndex.size())
            {
                nFound = true;
                staticParent = false;
                break;
            }
        };
        //se não encontrou nas estáticas, procurar nas móveis

        if (nFound)
        {
            nFound = false;
            i = 0;
            while(planePart != mobIndex[i])
            {
                i ++;
                if (i == mobIndex.size())
                {
                    nFound = true;
                    break;
                }
            };
        }

        if (!nFound && staticParent)
            mob_pieces[piece]->setParent(gra_sPieces[i]);
        else if (!nFound && !staticParent)
            mob_pieces[piece]->setParent(mob_pieces[i]);
        else
            printf("OBJETO PAI NÃO ENCONTRADO");

        //colocar posição e rotação 0 para todas as partes.
        line3df line;
        line.start = vector3df(0.0f,0.0f,0.0f);
        line.end = vector3df(0.0f,0.0f,0.0f);
        movVect[0].push_back(line);
        movVect[1].push_back(line);
    };
};

void SEngineFighter::buildPhysicalAirplane()
{
    stringw *nome;
    nome = recName;
    NewtonCollision * airplane = NewtonCreateCompoundCollision(nWorld, ncl_sPieces.size(),&ncl_sPieces[0], 30);

    //encontrar a fuselagem
    u16 i = 0;
    bool found = false;
    while (i < funcIndex.size())
    {
        if (funcIndex[i] == L"FUSELAGE")
        {
            found = true;
            break;
        }
        i ++;
    };

    if(found)
    {
        fuselageIndex = i;
        //fazer todas as gráficas estáticas parent da fuselagem
        for (u16 p=0; p < gra_sPieces.size(); p++)
        {
            if (p != i) //se não for a própria fuselagem
                gra_sPieces[p]->setParent(gra_sPieces[i]);
        };

        dMatrix matrix = GetIdentityMatrix();
        if(*nome == "747")
            matrix.m_posit = dVector (0.0f, 7.0f, 0.0f);//É a posição em que o avião inicia;
        else if(*nome == "160C")
            matrix.m_posit = dVector (0.0f, 1.4f, 0.0f);
        else
            matrix.m_posit = dVector (0.0f, 2.7f, 0.0f);

        NewtonBody * plane = NewtonCreateBody(nWorld, airplane);
        NewtonBodySetUserData (plane, this);
        NewtonBodySetMatrix(plane,&matrix[0][0]);
        NewtonBodySetMassMatrix (plane, mass, Ixx, Iyy, Izz);
        NewtonBodySetTransformCallback (plane, updateScene);
        NewtonBodySetForceAndTorqueCallback (plane, applyForce);//Atribuir uma função de evento para a
        //aplicação de força externa e torque de um corpo rígido.(applyForce é uma função) ir pra ela....
        NewtonBodySetLinearDamping(plane,mass/1000000); //tentar...

    }
    else
    {
        printf("E NECESSARIO ESPECIFICAR UMA FUSELAGEM");
        stopLoad = true;
    };


    for (int i = 0; i < ncl_sPieces.size(); i++)
        NewtonReleaseCollision(nWorld,ncl_sPieces[i]);

    NewtonReleaseCollision(nWorld, airplane);
}

void SEngineFighter::addStaticPart(IReadFile * file)
{
    printf("PARTES ESTATICAS \n");
    bool load = true;

    while (load)
    {
        //pula caracteres de controle
        char c = 0;
        while (c < 30)
            file->read(&c,1);
        file->seek(-1,true);

        //verifica se acabou o bloco
        stringw block;
        for (int i = 0; i < 4; i++)
        {
            file->read(&c,1);
            block.append(c);
        };

        file->seek(-4,true);

        if (block == "ENDB")
        {
            load = false;
            break;
        }

        //monta a string de carga da peça
        stringw partLWO (L"models/");
        stringw partName(L"");
        partLWO.append (planeName);
        partLWO.append (L"/gra_");//gra_ é a peça grafica, assim como tem col_ que é  peça para colisão.
        c = 0;
        while (c!= ' ')
        {
            file->read(&c,1);
            if(c!=' ')
                partName.append(c);
        }
        partLWO.append (partName);
        partLWO.append (L".x");

        //carrega a peça
        ISceneManager * smgr = device->getSceneManager();//Provides access to the scene manager.Returns:Pointer to the scene manager.
        u32 piece = gra_sPieces.size();
        gra_sPieces.push_back(smgr->addMeshSceneNode(smgr->getMesh(partLWO)));

        //aplica a posição e rotação
        pieceIndex.push_back(partName);
        vector3df pos = readVec(file);//vai pra tools.cpp
        vector3df rot = readVec(file);
        gra_sPieces[piece] -> setPosition(pos);
        gra_sPieces[piece] -> setRotation(rot);
#ifdef WIRE
        gra_sPieces[piece] -> setMaterialFlag(EMF_WIREFRAME,true);
#endif

#ifdef LIGHTING
        gra_sPieces[piece] -> setMaterialFlag(EMF_LIGHTING,false);
#endif

        //seta a colisão da peça
        stringw partCol (L"models/"); ///append ->Appends a string of the length l to this string.(Acrescenta uma seqüência de comprimento a esta string.
        partCol.append (planeName);
        partCol.append ("/col_");//E  a peça q não aparece no gráfico. Ela é mais simples e é onde irá receber as forças do newton;
        partCol.append (partName);
        partCol.append (L".x");

        //convertendo as colisões para objetos com um ponto por vértice (desambiguação)
        IMesh * collisionPart = smgr->getMesh(partCol);
        IMeshBuffer * mb = collisionPart->getMeshBuffer(0);
        S3DVertex * vertices = (S3DVertex *)mb->getVertices();//S3DVertex é classe do Irrilicht
        for (u16 i = 0; i < mb->getVertexCount(); i++)
        {
            vertices[i].Normal = vector3df(1.0f, 0.0f ,0.0f);
            vertices[i].Color = SColor(0);
            vertices[i].TCoords = vector2df(0);
        };
        collisionPart = smgr->getMeshManipulator()->createMeshWelded(collisionPart,0.0f);

        NewtonCollision * collision = addHullCollision(collisionPart,device->getVideoDriver(),nWorld,dVector(0.0f,0.0f,0.0f),piece);
        NewtonCollision * modifier = NewtonCreateConvexHullModifier(nWorld,collision,piece);
        dMatrix colMat (rot.X * 3.1416 / 180,rot.Y * 3.1416 / 180,rot.Z * 3.1416 / 180,conVecI2N(pos));
        NewtonConvexHullModifierSetMatrix(modifier,&colMat[0][0]);
        ncl_sPieces.push_back(modifier);
        NewtonReleaseCollision(nWorld,collision);

        //saber a que parte pertence
        stringw planePart;
        c = 0;
        while (c != 13)
        {
            file->read(&c,1);
            if (c > 30)
                planePart.append(c);
        }
        funcIndex.push_back(planePart);

        if(planePart == L"PROPELLER")
        {
            IVideoDriver * driver = device->getVideoDriver();
            stringw propTex = L"models/";
            propTex.append(planeName);
            propTex.append(L"/propeller_hi.png");
            gra_sPieces[piece] -> getMaterial(1).TextureLayer[0].Texture = driver->getTexture(propTex);
            gra_sPieces[piece] -> setMaterialType (EMT_TRANSPARENT_ALPHA_CHANNEL);
        };
        printf("\nAte aqui...\n");
    };
    //printf("\nAte aqui...\n");
};

void SEngineFighter::readCommands(IReadFile * file)
{
    printf ("COMANDOS ... \n\n");

    bool load = true;

    while (load)
    {
        //pula caracteres de controle
        char c = 0;
        while (c < 30)
            file->read(&c,1);
        file->seek(-1,true);

        //verifica se acabou o bloco
        stringw block;
        for (int i = 0; i < 4; i++)
        {
            file->read(&c,1);
            block.append(c);
        };
        file->seek(-4,true);

        if (block == "ENDB")
        {
            load = false;
            break;
        }

        //ler a parte que recebe o comando
        stringw part (L"");
        c = 0;
        while (c != ' ')
        {
            file->read(&c,1);
            if (c!=' ' && c != 13)
                part.append(c);
        };

        //encontrar a parte no vetor de índice
        u16 i = 0;
        bool nFound = false;
        if(part != L"NULL") //se for parte 'NULL', não procura no vetor de partes.
        {
            while(part != mobIndex[i])
            {
                i ++;
                if (i == mobIndex.size())
                {
                    nFound = true;
                    break;
                }
            };
        }
        else
            i = 999;

        printf("Parte: %ls ",part.c_str());

        if (!nFound)
        {
            //ler o comando referente a essa parte
            stringw command(L"");
            c = 0;
            while (c!=' ' && c != 13 && c != 10)
            {
                file->read(&c,1);
                if (c!=' ' && c != 13 && c != 10)
                    command.append(c);
            };

            //atribuir o indice ao comando
            if (command == L"FLAP")
                comm[FLAP].push_back(i);
            else if (command == L"ROLL")
                comm[ROLL].push_back(i);
            else if (command == L"YAW")
                comm[YAW].push_back(i);
            else if (command == L"PITCH")
                comm[PITCH].push_back(i);
            else if (command == L"GEAR")
                comm[GEAR].push_back(i);
            else if (command == L"GEARCOVER")
                comm[GEARCOVER].push_back(i);
            else if (command == L"LIGHT")
                comm[LIGHT].push_back(i);
            else if (command == L"EJECT")
                comm[EJECT].push_back(i);
            else if (command == L"SHOT")
                comm[SHOT].push_back(i);
            else if (command == L"SELWEAP")
                comm[SELWEAP].push_back(i);
            else if (command == L"ACCELL")
                comm[ACCELL].push_back(i);
            else if (command == L"DECCELL")
                comm[DECCELL].push_back(i);
            else if (command == L"ENGINEON")
                comm[ENGINEON].push_back(i);
            else
                printf("CNR! %ls ",command.c_str());

            printf("(cmd: %ls, ",command.c_str());
        }
        else
            printf("PARTE NAO ENCONTRADA %ls \n",part.c_str());

        //ler tipo (por enquanto, não estou mexendo com isso)
        if(part != L"NULL") //se a parte não for nula adiciona
        {
            stringw type(L"");
            c = 0;
            while (c != ' ')
            {
                file->read(&c,1);
                if (c!=' ')
                    type.append(c);
            };

            //ler vetores
            line3df line;
            line.start = vector3df(readVec(file));
            line.end = vector3df(readVec(file));

            if (type == "ROT")
                movVect[0][i] = line;
            else if (type == "MOV")
                movVect[1][i] = line;

            printf("%ls (%4.1f, %4.1f, %4.1f) a (%4.1f, %4.1f, %4.1f))\n",type.c_str(),
                   line.start.X, line.start.Y, line.start.Z, line.end.X, line.end.Y, line.end.Z);
        }
        else
            printf("COMANDO NULO: PROSSEGUIR)\n");
    };
};

void SEngineFighter::installWeapon(IReadFile * weap, stringw weaponName, vector3df position, IMeshSceneNode * parent, bool light)
{
    printf("INSTALANDO ARMAMENTOS \n");
    char c = 0;

    while (c != '{')
        weap->read(&c,1);

    c = 0;

    while (c < 33) //pula caracteres de controle
        weap->read(&c,1);
    weap->seek(-1,true);

    //ler o nome da arma e comparar com a que veio
    stringw nameLoaded = L"";
    do
    {
        weap->read(&c,1);
        if (c > 33)
            nameLoaded.append(c);
    }while (c > 33);

    if(nameLoaded == weaponName)
    {
        while (c < 33) //pula caracteres de controle
            weap->read(&c,1);
        weap->seek(-1,true);

        stringw type = L"";
        for (u16 i = 0; i < 4; i++)
        {
            weap->read(&c,1);
            type.append(c);
        }

        if(type==L"MGUN")
        {
           //defaults
            f32 bore = 0.40f;
            u16 fireRate = 500;
            u16 ammo = 300;
            u16 range = 2000;

            c = 0;

            while (c != '}')
            {
                stringw item=L"";

                c = 0;

                while (c < 33) //pula caracteres de controle
                    weap->read(&c,1);
                weap->seek(-1,true);

                if(c == '}')
                    break;

                for (u16 i = 0; i < 4; i++)
                {
                    weap->read(&c,1);
                    if(c > 33)
                        item.append(c);
                }

                c = 0;

                while (c < 33) //pula caracteres de controle
                    weap->read(&c,1);
                weap->seek(-1,true);

                if(item == L"BORE")
                    bore = readFloat(weap);
                if(item == L"FRAT")
                    fireRate = (u16)(readFloat(weap));
                if(item == L"RNGE")
                    range = (u16)(readFloat(weap));
                if(item == L"AMMO")
                    ammo = (u16)(readFloat(weap));
            }
            machineGun * mgun = new machineGun(bore,ammo,position,device);
            mgun->setRange(range);
            mgun->setFireRate(fireRate);
            mgun->setParent(parent);
            mgun->flashLight(light);

            guns.push_back(mgun);

            printf("INSTALADO: ");
            printStringw(weaponName);
            printf(" metralhadora: ");
            printf("calibre %4.2f mm, razao de fogo %d tiros por minuto, alcance %d metros com %d tiros\n", bore, fireRate, range, ammo);
            weap->seek(0,false);
        };
    }
    else
        printf("->ignorado\n");
}

void SEngineFighter::addWeapon(IReadFile * file)
{
    IReadFile * weap;
    IFileSystem * fs = device->getFileSystem();
    weap = fs->createAndOpenFile("models/weaponlist.dat");
    if (!weap)
    {
        printf("ERRO: NAO FOI POSSIVEL ABRIR A LISTA DE ARMAMENTOS (models//weaponlist.dat) \n");
        return;
    };
    printf("CARREGANDO ARMAMENTOS: \n");

    while (file->getPos() < file->getSize())
    {
        char c = 0;

        while (c < 33) //pula caracteres de controle
            file->read(&c,1);
        file->seek(-1,true);

        //verificar se acabou o bloco de armamentos
        stringw block;
        for (int i = 0; i < 4; i++)
        {
            file->read(&c,1);
            block.append(c);
        };
        file->seek(-4,true);

        if (block == "ENDB")
            break;

        //procura pelo nome do armamento na lista do avião
        c = 0;
        stringw weaponName = L"";
        while (c != ' ')
        {
            file->read(&c,1);
            if (c > 33)
                weaponName.append(c);
        };

        vector3df position = readVec(file);

        c = 0;
        stringw parentName = L"";
        while (c != 13)
        {
            file->read(&c,1);
            if (c > 33)
                parentName.append(c);
        };

        //procurar o indice do parent nos estaticos
        u16 prIndex = 32;
        for (u16 i = 0; i < pieceIndex.size(); i++)
        {
            if (pieceIndex[i] == parentName)
                prIndex = i;
        };

        if(prIndex == 32)
        {
            printf("ERRO: 'PARENT' DA ARMA NAO LOCALIZADO \n");
            return;
        };

        //verificar se depois disso tem a marca da luz
        c = 0;
        bool light = false;

        while (c != 13) //pula caracteres de controle
        {
            if (c == 'L')
                light = true;
            file->read(&c,1);
        };
        file->seek(-1,true);

        //carregar a arma encontrada
        if(!civilian)
            installWeapon(weap,weaponName,position,gra_sPieces[prIndex],light);
        printf("PRONTO \n");
    };
}

void SEngineFighter::readPlanePart(IReadFile * file)
{
    bool done = false;
    while (!done)
    {
        int block = findBlock(file);//ir pra linha 199
        switch (block)
        {
            case 1:
                printf("FIM DO BLOCO \n");
                break;
            case 2:
                addStaticPart(file);//Partes estáticas ->ir para linha 492
                break;
            case 3:
                addWeapon(file);//Armamentos-> ir pra linha 840;
                break;
            case 4:
                addMobilePart(file);//Partes movéis -> ir pra linha 312
                break;
            case 5:
                readCommands(file);//Ler os comandos -> ir pra linha 604
                break;
            case 6:
                readData(file);
                break;
            case 100: //blocos lidos
            {
                printf("AVIAO LIDO \n");
                done = true;
                break;
            }
            default:
                break;
        }
    };
};

void SEngineFighter::setCommand(u16 part, u16 state, u16 command)
{
    stringw *nome;
    nome = recName;
    if(*nome == "747")
    {
        switch (command)
        {
        case ROLL:
        {
            if (state == 1) //giro à esquerda
            {
                if (roll < 15)
                    roll += 0.01f;
            }
            else if(state == 2) //giro à direita
            {
                if (roll > -15)
                    roll -= 0.01f;
            }
            else //manche solto
            {

                if (roll > 1)
                    roll -= 0.02f;
                else if (roll < -1)
                    roll += 0.02f;
                else
                    roll = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * roll/15 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * roll/15 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case PITCH:
        {
            if (state == 1) //giro à esquerda
            {
                if (pitch < 20)
                pitch += 0.01f;

            }
            else if(state == 2) //giro à direita
            {
                if (pitch > -20)
                    pitch -= 0.01f;
            }
            else //manche solto
            {
                if (pitch > 1)
                    pitch -= 0.5f;
                else if (pitch < -1)
                    pitch += 0.5f;
                else
                    pitch = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * pitch/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * pitch/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case YAW:
        {
            if (state == 1) //giro à esquerda
            {
                 if (yaw < 20)
                    yaw += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (yaw > -20)
                    yaw -= 0.5f;
            }
            else //manche solto
            {
                if (yaw > 1)
                    yaw -= 0.5f;
                else if (yaw < -1)
                    yaw += 0.5f;
                else
                    yaw = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * yaw/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * yaw/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case FLAP:
        {
            static bool flapMove = false;
            static bool flapDown = false;

            if (state == 1) //se for 0, não vem comando
                flapMove = true;

            if(flapMove)
            {
                if (!flapDown)
                    flap += 0.25f;
                else
                    flap -= 0.25f;

                if (part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * flap/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * flap/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!flapDown)
                {
                    if (flap >= 30)
                    {
                        flapDown = true;
                        flapMove = false;
                    };
                }
                else
                {
                    if (flap == 0)
                    {
                        flapDown = false;
                        flapMove = false;
                    };
                };
            };
            break;
        };
        case EJECT:
        {
            static bool ejectMove = false;
            static bool ejectOpen = false;
            static f32 eject = 0;

            if (state == 1) //se for 0, não vem comando
                ejectMove = true;

            if(ejectMove)
            {
                if (!ejectOpen)
                    eject += 1.0f;
                else
                    eject -= 1.0f;

                if(part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * eject/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * eject/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!ejectOpen)
                {
                    if (eject >= 30)
                    {
                        ejectOpen = true;
                        ejectMove = false;
                    };
                }
                else
                {
                    if (eject == 0)
                    {
                        ejectOpen = false;
                        ejectMove = false;
                    };
                };
            };

            break;
        };
        case GEARCOVER:
        {
            static bool coverMove = false;
            static bool coverOpen = false;
            static f32 cover = 0;

            if (coverMove || coverOpen)
                mob_pieces[part] -> setVisible(true);
            else
                mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                coverMove = true;

            if(coverMove)
            {
                if (!coverOpen)
                    cover += 0.25f;
                else
                    cover -= 0.25f;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * cover/50 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * cover/50 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!coverOpen)
                {
                    if (cover >= 50)
                    {
                        coverOpen = true;
                        coverMove = false;
                    };
                }
                else
                {
                    if (cover == 0)
                    {
                        coverOpen = false;
                        coverMove = false;
                    };
                };
            };

            break;
        };
        case GEAR:
        {
            //static bool gearMove = false;
            //static bool gearDown = false;

            if (gearMove || gearDown)
                mob_pieces[part] -> setVisible(true);
            else
                mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                gearMove = true;

            static u16 pulse = 0;
            for (u16 i = 0; i < comm[GEARCOVER].size(); i++)
                setCommand(comm[GEARCOVER][i],pulse,GEARCOVER);

            if(gearMove)
            {
                if (!gearDown)
                    gear += 1.0f;
                else
                    gear -= 1.0f;

                if (gear > 10 && gear < 12) //intervalo do GEARCOVER
                    pulse = 1;
                else
                    pulse = 0;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * gear/300 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * gear/300 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!gearDown)
                {
                    if (gear >= 300)
                    {
                        gearDown = true;
                        gearMove = false;
                    };
                }
                else
                {
                    if (gear == 0)
                    {
                        gearDown = false;
                        gearMove = false;
                    };
                };
            };
            break;
        };
        default:
            break;
    };

    };
    if(*nome == "160C")
    {
        switch (command)
    {
        case ROLL:
        {
            if (state == 1) //giro à esquerda
            {
                 if (roll < 15)
                    roll += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (roll > -15)
                    roll -= 0.5f;
            }
            else //manche solto
            {
                if (roll > 1)
                    roll -= 0.5f;
                else if (roll < -1)
                    roll += 0.5f;
                else
                    roll = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * roll/15 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * roll/15 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case PITCH:
        {
            if (state == 1) //giro à esquerda
            {
                 if (pitch < 20)
                    pitch += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (pitch > -20)
                    pitch -= 0.5f;
            }
            else //manche solto
            {
                if (pitch > 1)
                    pitch -= 0.5f;
                else if (pitch < -1)
                    pitch += 0.5f;
                else
                    pitch = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * pitch/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * pitch/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case YAW:
        {
            if (state == 1) //giro à esquerda
            {
                 if (yaw < 20)
                    yaw += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (yaw > -20)
                    yaw -= 0.5f;
            }
            else //manche solto
            {
                if (yaw > 1)
                    yaw -= 0.5f;
                else if (yaw < -1)
                    yaw += 0.5f;
                else
                    yaw = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * yaw/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * yaw/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case FLAP:
        {
            static bool flapMove = false;
            static bool flapDown = false;

            if (state == 1) //se for 0, não vem comando
                flapMove = true;

            if(flapMove)
            {
                if (!flapDown)
                    flap += 0.25f;
                else
                    flap -= 0.25f;

                if (part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * flap/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * flap/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!flapDown)
                {
                    if (flap >= 30)
                    {
                        flapDown = true;
                        flapMove = false;
                    };
                }
                else
                {
                    if (flap == 0)
                    {
                        flapDown = false;
                        flapMove = false;
                    };
                };
            };
            break;
        };
        case EJECT:
        {
            static bool ejectMove = false;
            static bool ejectOpen = false;
            static f32 eject = 0;

            if (state == 1) //se for 0, não vem comando
                ejectMove = true;

            if(ejectMove)
            {
                if (!ejectOpen)
                    eject += 1.0f;
                else
                    eject -= 1.0f;

                if(part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * eject/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * eject/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!ejectOpen)
                {
                    if (eject >= 30)
                    {
                        ejectOpen = true;
                        ejectMove = false;
                    };
                }
                else
                {
                    if (eject == 0)
                    {
                        ejectOpen = false;
                        ejectMove = false;
                    };
                };
            };

            break;
        };
        case GEARCOVER:
        {
            static bool coverMove = false;
            static bool coverOpen = false;
            static f32 cover = 0;

            if (coverMove || coverOpen)
                mob_pieces[part] -> setVisible(true);
            else
                mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                coverMove = true;

            if(coverMove)
            {
                if (!coverOpen)
                    cover += 0.25f;
                else
                    cover -= 0.25f;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * cover/50 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * cover/50 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!coverOpen)
                {
                    if (cover >= 50)
                    {
                        coverOpen = true;
                        coverMove = false;
                    };
                }
                else
                {
                    if (cover == 0)
                    {
                        coverOpen = false;
                        coverMove = false;
                    };
                };
            };


            break;
        };
        case GEAR:
        {
            //static bool gearMove = false;
            //gearDown = true;
            if (gearMove || gearDown)
                mob_pieces[part] -> setVisible(true);
            else
               mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                gearMove = true;

            static u16 pulse = 0;
            for (u16 i = 0; i < comm[GEARCOVER].size(); i++)
                setCommand(comm[GEARCOVER][i],pulse,GEARCOVER);

            if(gearMove)
            {
                if (!gearDown)
                    gear += 1.0f;
                else
                    gear -= 1.0f;

                if (gear > 10 && gear < 12) //intervalo do GEARCOVER
                    pulse = 1;
                else
                    pulse = 0;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * gear/300 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * gear/300 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!gearDown)
                {
                    if (gear >= 300)
                    {
                        gearDown = true;
                        gearMove = false;
                    };
                }
                else
                {
                    if (gear == 0)
                    {
                        gearDown = false;
                        gearMove = false;
                    };
                };
            };
            break;
        };
        default:
            break;
    };
    };
        if(*nome == "thunderbolt")
    {
        switch (command)
    {
        case ROLL:
        {
            if (state == 1) //giro à esquerda
            {
                 if (roll < 15)
                    roll += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (roll > -15)
                    roll -= 0.5f;
            }
            else //manche solto
            {
                if (roll > 1)
                    roll -= 0.5f;
                else if (roll < -1)
                    roll += 0.5f;
                else
                    roll = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * roll/15 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * roll/15 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case PITCH:
        {
            if (state == 1) //giro à esquerda
            {
                 if (pitch < 20)
                    pitch += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (pitch > -20)
                    pitch -= 0.5f;
            }
            else //manche solto
            {
                if (pitch > 1)
                    pitch -= 0.5f;
                else if (pitch < -1)
                    pitch += 0.5f;
                else
                    pitch = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * pitch/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * pitch/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case YAW:
        {
            if (state == 1) //giro à esquerda
            {
                 if (yaw < 20)
                    yaw += 0.5f;
            }
            else if(state == 2) //giro à direita
            {
                if (yaw > -20)
                    yaw -= 0.5f;
            }
            else //manche solto
            {
                if (yaw > 1)
                    yaw -= 0.5f;
                else if (yaw < -1)
                    yaw += 0.5f;
                else
                    yaw = 0.0f;
            };

            if(part == 999) //parte nula (só tem comando, não tem parte)
                break;

            vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * yaw/20 + mob_defRot[part]);
            vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * yaw/20 + mob_defPos[part]);
            mob_pieces[part] -> setRotation(vecRot);
            mob_pieces[part] -> setPosition(vecPos);
            break;
        };
        case FLAP:
        {
            static bool flapMove = false;
            static bool flapDown = false;

            if (state == 1) //se for 0, não vem comando
                flapMove = true;

            if(flapMove)
            {
                if (!flapDown)
                    flap += 0.25f;
                else
                    flap -= 0.25f;

                if (part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * flap/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * flap/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!flapDown)
                {
                    if (flap >= 30)
                    {
                        flapDown = true;
                        flapMove = false;
                    };
                }
                else
                {
                    if (flap == 0)
                    {
                        flapDown = false;
                        flapMove = false;
                    };
                };
            };
            break;
        };
        case EJECT:
        {
            static bool ejectMove = false;
            static bool ejectOpen = false;
            static f32 eject = 0;

            if (state == 1) //se for 0, não vem comando
                ejectMove = true;

            if(ejectMove)
            {
                if (!ejectOpen)
                    eject += 1.0f;
                else
                    eject -= 1.0f;

                if(part != 999)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * eject/30 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * eject/30 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!ejectOpen)
                {
                    if (eject >= 30)
                    {
                        ejectOpen = true;
                        ejectMove = false;
                    };
                }
                else
                {
                    if (eject == 0)
                    {
                        ejectOpen = false;
                        ejectMove = false;
                    };
                };
            };

            break;
        };
        case GEARCOVER:
        {
            static bool coverMove = false;
            static bool coverOpen = false;
            static f32 cover = 0;

            if (coverMove || coverOpen)
                mob_pieces[part] -> setVisible(true);
            else
                mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                coverMove = true;

            if(coverMove)
            {
                if (!coverOpen)
                    cover += 0.25f;
                else
                    cover -= 0.25f;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * cover/50 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * cover/50 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!coverOpen)
                {
                    if (cover >= 50)
                    {
                        coverOpen = true;
                        coverMove = false;
                    };
                }
                else
                {
                    if (cover == 0)
                    {
                        coverOpen = false;
                        coverMove = false;
                    };
                };
            };


            break;
        };
        case GEAR:
        {
            //static bool gearMove = false;
            //static bool gearDown = false;

            if (gearMove || gearDown)
                mob_pieces[part] -> setVisible(true);
            else
                mob_pieces[part] -> setVisible(false);

            if (state == 1) //se for 0, não vem comando
                gearMove = true;

            static u16 pulse = 0;
            for (u16 i = 0; i < comm[GEARCOVER].size(); i++)
                setCommand(comm[GEARCOVER][i],pulse,GEARCOVER);

            if(gearMove)
            {
                if (!gearDown)
                    gear += 1.0f;
                else
                    gear -= 1.0f;

                if (gear > 10 && gear < 12) //intervalo do GEARCOVER
                    pulse = 1;
                else
                    pulse = 0;

                if(part != 999) //parte nula (só tem comando, não tem parte)
                {
                    vector3df vecRot = vector3df((movVect[0][part].start - movVect[0][part].end) * gear/300 + mob_defRot[part]);
                    vector3df vecPos = vector3df((movVect[1][part].start - movVect[1][part].end) * gear/300 + mob_defPos[part]);
                    mob_pieces[part] -> setRotation(vecRot);
                    mob_pieces[part] -> setPosition(vecPos);
                };

                if (!gearDown)
                {
                    if (gear >= 300)
                    {
                        gearDown = true;
                        gearMove = false;
                    };
                }
                else
                {
                    if (gear == 0)
                    {
                        gearDown = false;
                        gearMove = false;
                    };
                };
            };
            break;
        };
        default:
            break;
    };
    };
};

void SEngineFighter::setGearDown()
{
    for (u16 i = 0; i < getCommandArray()[GEARCOVER].size(); i++)
        setCommand(getCommandArray()[GEARCOVER][i],1,GEARCOVER);

    gear = 270;

    for (u16 i = 0; i < getCommandArray()[GEAR].size(); i++)
        setCommand(getCommandArray()[GEAR][i],1,GEAR);

}

vector3df SEngineFighter::getPosition()
{
    return (gra_sPieces[fuselageIndex]->getPosition());
};

array<u16>  * SEngineFighter::getCommandArray()
{
    return (comm);
};

array <machineGun *> SEngineFighter::getGunArray()
{
    return guns;
};

void SEngineFighter::checkLanding()
{
    if (gear < 300)
        return;
    else
    {
        ISceneManager * smgr = device->getSceneManager();
        CMatrix4<f32> matrix = gra_sPieces[fuselageIndex]->getAbsoluteTransformation();
        ISceneNode * chao = 0;

        for (u16 i = 0; i < lGear.size(); i++)
        {
            lGearHeight[i] = 0.0f;
            line3df ray = lGear[i];
            matrix.transformVect(ray.start);
            matrix.transformVect(ray.end);
            vector3df ponto;
            triangle3df triangulo;
            chao = smgr->getSceneCollisionManager()->getSceneNodeAndCollisionPointFromRay(ray, ponto, triangulo, 0, 0, 0);
            if (chao)
                lGearHeight[i] += lGear[i].getLength() - (ray.start - ponto).getLength();
            chao = 0;
            ponto = vector3df(0.0f,0.0f,0.0f);
        };
    };
};

bool SEngineFighter::getEngineState()
{
    return engine;
};

void SEngineFighter::startEngine(bool start)
{
    engine = start;
    motorLig = start;///Não peguei o engine porque ela é private, então resolvi criar outra variavel!
};

void SEngineFighter::accelerate(u16 acce, bool acelerando)
{
    //procurar pelas hélices (uma única vez)
    stringw * nomeAm;
    nomeAm = recName;
    runOnce = true;
    if (runOnce)
    {
        for (u16 i=0; i < funcIndex.size(); i++)
        {
            if (funcIndex[i] == L"PROPELLER")
                propellers.push_back(i);
        };
        runOnce = false;
    };

    if(engine&& acelerando)
        accell += acce-1;
    else if(engine && !acelerando)///Se não estiver acelerando o avião, a Rotação do Motor vai caindo...
    {
        if (*nomeAm == "160C" && accell >18)
            accell += acce -1.08;
        else if(accell>40)///...Até o limite estabelicido aqui neste if
            accell += acce -1.04;
        else
        accell += acce -1;
    }
    else
        accell = 0;

    if (accell < 0)
        accell = 0;

        if (accell > 100.0f)//É a força de aceleração do avião;
            accell = 100.0f;


    for (u16 i=0; i < propellers.size(); i++)
    {
        vector3df rot = gra_sPieces[propellers[i]]->getRotation();
        gra_sPieces[propellers[i]]->setRotation(vector3df(rot.X, rot.Y, rot.Z + accell));
    }
};

void SEngineFighter::setShot(bool fire)
{
    if(civilian)
        return;

    static u16 selGun = 0;
    if (fire)
    {
        guns[selGun] -> shot();
        selGun ++;
        if (selGun >= guns.size())
            selGun = 0;
    };
};

bool SEngineFighter::isCivilian()
{
    return civilian;
};

SEngineFighter::SEngineFighter (IrrlichtDevice * IrrDevice, NewtonWorld * newtWorld, stringw name)
{
    //inicializar estado do avião
    acabouGasolina = false;
    gearDown = false;
    gearMove = false;
    roll = 0;
    pitch = 0;
    yaw = 0;
    flap = 0;
    gear = 0;
    engine = false;
    stopLoad = false;
    civilian = true;
    dVector lGearForce = dVector(0.0f, 0.0f, 0.0f);

    nWorld = newtWorld;//Não esquecer-> nWorld é o mundo, do tipo NewtonWorld;
    device = IrrDevice;
    planeName = name;
    vai = name;
    recName = &vai;
    IFileSystem * fs = device->getFileSystem();//getFileSystem->Provides access to the virtual file system.
    IReadFile * file = fs->createAndOpenFile("models/planelist.dat");//createAnd....->Opens a file for read access.(abre um arquivo para acesso de leitura)
    if (!file)//arquivo não pode ser aberto
    {
        printf("ERRO FATAL: LISTA DE AVIOES NAO ENCONTRADA \n");
        return;
    }

    //pesquisar pelo avião solicitado
    int cursorPosition = readPlaneName(file, name);//ir pra linha 158;
    if(cursorPosition == 0) //avião solicitado não tem na lista
    {
        printf("ERRO! AVIAO SOLICITADO NAO EXISTE NA LISTA");
        return;
    };

    //pesquisar pelas partes
    readPlanePart(file);//ver linha 926;
    printf("AVIAO LIDO COM SUCESSO: IMPLEMENTANDO FISICAS ...");
    buildPhysicalAirplane();//ir pra linha 440
    printf("IMPLEMENTADO\n");
    //printf("\n\n\n*****%d*****\n\n\n",cursorPosition);//Imprime o retorno da função realPlaneName
    //printf("\n\n**** %c ***\n\n",*pontChar);
};

IMeshSceneNode * SEngineFighter::getFuselage()
{
    return(gra_sPieces[fuselageIndex]);
};

float SEngineFighter :: getVeloc(stringw name)//Ajuste do ponteiro de Velocidade;
{
    if(name =="747")
        return pontAc * 0.5f;
    if(name == "160C")
        return pontAc * 1.2f;
    else
        return pontAc * 1.2f;

};

float SEngineFighter :: getAccell(stringw name)//Ajuste do ponteiro de RPM
{
    if(name =="747")
        return accell * 3.0f;//3.0 está OK
    else
        return accell * 3.25;//3.25 está bom para o thunderbolt e 160C

};

bool SEngineFighter :: verifCol()//Verifica se o avião bateu em alguma coisa;
{
    explode = false;
   // printf("\n%0.2f - %0.2f - %0.2f", getSpeedRot.X, getSpeedRot.Y, getSpeedRot.Z);

    varIni = getSpeedRot;

    if(varIni.X - varFim.X>12 || varIni.Y - varFim.Y > 12)
    {
        printf("\nBooom");
        explode = true;
    };

    varFim = varIni;

    return explode;
};
//buildPhysicalAirplane
///posição inicial do avião por volta da linha 469

SEngineFighter :: ~SEngineFighter()
{
    moveType.clear();
    gearFunc.clear();
    commPart.clear();
    comm[12].clear();
    lGearHeight.clear();
    pieceIndex.clear();
    funcIndex.clear();
    mobIndex.clear();
    weapon_pos.clear();
    mob_defPos.clear();
    mob_defRot.clear();
    movVect[2].clear();
    lGear.clear();
    gra_sPieces.clear();
    col_sPieces.clear();
    mob_pieces.clear();
    ncl_sPieces.clear();
    phy_sPieces.clear();
    guns.clear();
    stopLoad = false;
    fuselageIndex = 0;
    propellers.clear();
    runOnce = true;
    gearDown = false;
    gearMove = false;

};


