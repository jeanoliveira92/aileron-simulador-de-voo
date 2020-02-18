#include "tools.h"
#include <conio.h>
///Ver linha 518
///FUNÇÕES PARA FÍSICA (NEWTON GAME DYNAMICS)

NewtonCollision* addHullCollision (IMesh* source, IVideoDriver* driver, NewtonWorld * nWorld, dVector offset, int ID)
{
    printf("ADICIONANDO COLISAO: ..");
	int vCount = 0;
	int mbCount = 0;
	int tmpCount =0;
	int i = 0;

	NewtonCollision* collision;
	mbCount=source->getMeshBufferCount();

	for (i=0; i<mbCount; i++)
	{
		tmpCount = source->getMeshBuffer(i)->getVertexCount();
		vCount += tmpCount;
	}

	array<float> vArray;
	int v1i = 0;
	int v2i = 0;
	int v3i = 0;
	int k = 0;
	u16 j = 0;

	for (k=0;  k < mbCount; k++)
	{
		IMeshBuffer* mb = source->getMeshBuffer(k);
	   	S3DVertex* mb_vertices = (S3DVertex*)mb->getVertices();
		u16* mb_indices  = mb->getIndices();

        for (j=0; j<mb->getIndexCount(); j+=3)
	    {
            v1i = mb_indices[j];
            v2i = mb_indices[j+1];
            v3i = mb_indices[j+2];

            vArray.push_back(mb_vertices[v1i].Pos.X + offset.m_x);
            vArray.push_back(mb_vertices[v1i].Pos.Y + offset.m_y);
            vArray.push_back(mb_vertices[v1i].Pos.Z + offset.m_z);
            vArray.push_back(mb_vertices[v2i].Pos.X + offset.m_x);
            vArray.push_back(mb_vertices[v2i].Pos.Y + offset.m_y);
            vArray.push_back(mb_vertices[v2i].Pos.Z + offset.m_z);
            vArray.push_back(mb_vertices[v3i].Pos.X + offset.m_x);
            vArray.push_back(mb_vertices[v3i].Pos.Y + offset.m_y);
            vArray.push_back(mb_vertices[v3i].Pos.Z + offset.m_z);
		};
	}
	collision = NewtonCreateConvexHull (nWorld, vCount, &vArray[0], 12, 0.0001, 1, NULL);
	printf(".... feito \n");

	return collision;
}

dVector calculateTorqueAt(dVector force, dVector position, const NewtonBody * body)
{
    dMatrix matrix;
    dVector COM;
    dVector tempTorque;
    dVector torque;

    NewtonBodyGetMatrix(body,&matrix[0][0]);
    position = matrix.TransformVector(position);
    NewtonBodyGetCentreOfMass(body,&COM.m_x);
    torque = (position-COM) * force;
    return torque;
};

void updateGenericScene (const NewtonBody* body, const dFloat * timestep, int thread)
{
	float matrix[16];

    IMeshSceneNode * node;
	node = (IMeshSceneNode*) NewtonBodyGetUserData(body);

	NewtonBodyGetMatrix(body, matrix);

	CMatrix4<float> mat;
	memcpy(mat.pointer(), matrix, sizeof(float) * 16);

	node->setPosition(mat.getTranslation());
	node->setRotation(mat.getRotationDegrees());
};

void applyGenericForce (const NewtonBody* body, dFloat timestep, int thread)
{
    dFloat mass;
    dFloat Ixx;
    dFloat Iyy;
    dFloat Izz;

	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);

    dVector force (0.0f, GRAVITY * mass, 0.0f);
    dVector torque (0.0f, 0.0f, 0.0f);

    NewtonBodySetTorque (body, &torque.m_x);
    NewtonBodySetForce (body, &force.m_x);
}

dVector conVecI2N (vector3df vector)
{
    dVector vec;
    vec.m_x = vector.X;
    vec.m_y = vector.Y;
    vec.m_z = vector.Z;
    return vec;
}

vector3df conVecN2I (dVector vector)
{
    return vector3df(vector.m_x, vector.m_y, vector.m_z);
}

vector3df readVec(IReadFile * file)
{
    bool startDec = false;
    char c = 0;
    int cont = 0;
    int mult = 1;
    f32 contDec = 0;
    vector3df vec(0.0f,0.0f,0.0f);
    while (cont < 3)
    {
        file->read(&c,1);
        if (c == '-')
            mult = -1;
        else if (c == '.')
            startDec = true;
        else if (c == ' ' || c < 30)
        {
            if (cont == 0)
                vec.X *= mult/pow(10.0f,contDec);
            else if (cont == 1)
                vec.Y *= mult/pow(10.0f,contDec);
            else
                vec.Z *= mult/pow(10.0f,contDec);

            startDec = false;
            mult = 1;
            contDec = 0;
            cont ++;
        }
        else
        {
            if (cont == 0)
            {
                vec.X *= 10.0f;
                vec.X += (f32)(c - 48);
            }
            else if (cont == 1)
            {
                vec.Y *= 10.0f;
                vec.Y += (f32)(c - 48);
            }
            else
            {
                vec.Z *= 10.0f;
                vec.Z += (f32)(c - 48);
            }
            if (startDec)
                contDec ++;
        };
    };
    return vec;
};

f32 readFloat(IReadFile * file)
{
    bool startDec = false;
    char c = 0;
    int mult = 1;
    f32 contDec = 0;
    f32 readFloat = 0;

    while (c < 30) //pula caracteres de controle
        file->read(&c,1);
    file->seek(-1,true);

    while (c > 30)
    {
        file->read(&c,1);
        if (c == '-')
            mult = -1;
        else if (c == '.')
            startDec = true;
        else if (c == ' ' || c < 30)
        {
            readFloat *= mult/pow(10.0f,contDec);
            startDec = false;
            mult = 1;
            contDec = 0;
        }
        else
        {
            readFloat *= 10.0f;
            readFloat += (f32)(c - 48);
            if (startDec)
                contDec ++;
        };
    }
    return readFloat;
};

void printStringw(stringw string)
{
    for (u16 i = 0; i < string.size();i++)
        printf("%c",string[i]);
};

int joy(array<SJoystickInfo> * joystickInfo, IrrlichtDevice * device){

	if(device->activateJoysticks(*joystickInfo)){

		printf("\nJoystick support is enabled. %d joystick(s) are present\n",joystickInfo->size());

		for(u32 joystick = 0; joystick < joystickInfo->size(); joystick++){

			printf("\n\tJoystick: %d", joystick+1);
        }
	}

    else
		printf("Joystick support is not enabled.\n");

    return (joystickInfo->size());
}

///FUNÇÕES LIMITED FPS
double CStopWatch::LIToSecs( LARGE_INTEGER & L)
{
	return ((double)L.QuadPart /(double)frequency.QuadPart);
}

CStopWatch::CStopWatch()
{
	timer.start.QuadPart=0;
	timer.stop.QuadPart=0;
	QueryPerformanceFrequency( &frequency );
}

void CStopWatch::startTimer( )
{
    QueryPerformanceCounter(&timer.start);
}

void CStopWatch::stopTimer( )
{
    QueryPerformanceCounter(&timer.stop);
}

double CStopWatch::getElapsedTime()
{
	LARGE_INTEGER time;
	time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
    return LIToSecs( time) ;
}


///REFLEXO DO SOL
sol :: sol(IrrlichtDevice * deviceQvem, ISceneManager * smgrQvem,IGUIEnvironment * guienV, IVideoDriver * driveR)
{
    guienv= guienV;
    driver = driveR;
    device = deviceQvem;
    smgr = smgrQvem;
    mult = (f32)driver->getScreenSize().Height / 600.0f;
    rect<s32>nullRect (0,0,0,0);
    flare = guienv->addImage(nullRect,0,0,0);
    flareOp = guienv->addImage(nullRect,0,0,0);
    flareIn = guienv->addImage(nullRect,0,0,0);
    flarePq = guienv->addImage(nullRect,0,0,0);
    flarePq2 = guienv->addImage(nullRect,0,0,0);
    runOnce = true;
};
void sol :: reflexoSol (ILightSceneNode * luzSol)
{
    if(runOnce) //carregar as imagens
    {
        flare->setImage(driver->getTexture("fx/sol_flare.png"));
        flare->setUseAlphaChannel(true);
        flare->setScaleImage(true);

        flareOp->setImage(driver->getTexture("fx/grande_flare.png"));
        flareOp->setUseAlphaChannel(true);
        flareOp->setScaleImage(true);

        flareIn->setImage(driver->getTexture("fx/medio_flare.png"));
        flareIn->setUseAlphaChannel(true);
        flareIn->setScaleImage(true);

        flarePq->setImage(driver->getTexture("fx/pequeno_flare.png"));
        flarePq->setUseAlphaChannel(true);
        flarePq->setScaleImage(true);

        flarePq2->setImage(driver->getTexture("fx/pequeno_flare.png"));
        flarePq2->setUseAlphaChannel(true);
        flarePq2->setScaleImage(true);

        runOnce = false;
    };

    ICameraSceneNode * camera = device->getSceneManager()->getActiveCamera();
    vector3df solPos = luzSol->getAbsolutePosition();

    position2d<s32> flareCentro = smgr->getSceneCollisionManager()->getScreenCoordinatesFrom3DPosition(solPos,camera);

    if(flareCentro.X > 800 * mult or flareCentro.Y > 600 * mult or flareCentro.X < 0 or flareCentro.Y < 0)
    {
        flare->setVisible(false);
        flareOp->setVisible(false);
        flareIn->setVisible(false);
        flarePq->setVisible(false);
        flarePq2->setVisible(false);
        return;
    }

    ISceneNode * node = 0;
    vector3df point;
    triangle3df triangle;
    node = smgr->getSceneCollisionManager()->getSceneNodeAndCollisionPointFromRay(
                smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(flareCentro,camera),
                point, triangle, 0, 0, false);
    if (node)
    {
        flare->setVisible(false);
        flareOp->setVisible(false);
        flareIn->setVisible(false);
        flarePq->setVisible(false);
        flarePq2->setVisible(false);
        return;
    }

    flare->setVisible(true);
    flareOp->setVisible(true);
    flareIn->setVisible(true);
    flarePq->setVisible(true);
    flarePq2->setVisible(true);

    //posicao do sol
    rect<s32> flareRect((s32)(flareCentro.X - 128 * mult),
                        (s32)(flareCentro.Y - 132 * mult),
                        (s32)(flareCentro.X + 128 * mult),
                        (s32)(flareCentro.Y + 380 * mult));
    flare->setRelativePosition(flareRect);

    //flare oposto
    position2d<s32> opFlareCentro = position2d<s32>((s32)(800 * mult - flareCentro.X),
                                                    (s32)(600 * mult - flareCentro.Y));
    rect<s32> opFlare(  (s32)(opFlareCentro.X - 128 * mult),
                        (s32)(opFlareCentro.Y - 128 * mult),
                        (s32)(opFlareCentro.X + 128 * mult),
                        (s32)(opFlareCentro.Y + 128 * mult));

    flareOp->setRelativePosition(opFlare);


    //flare intermediario
    position2d<s32> inFlareCentro = position2d<s32>((s32)flareCentro.X - (flareCentro.X - opFlareCentro.X) / 2,
                                                    (s32)flareCentro.Y - (flareCentro.Y - opFlareCentro.Y) / 2);
    rect<s32> inFlare(  (s32)(inFlareCentro.X - 64 * mult),
                        (s32)(inFlareCentro.Y - 64 * mult),
                        (s32)(inFlareCentro.X + 64 * mult),
                        (s32)(inFlareCentro.Y + 64 * mult));

    flareIn->setRelativePosition(inFlare);


    //flare pequeno
    position2d<s32> pqFlareCentro = position2d<s32>((s32)flareCentro.X - (flareCentro.X - opFlareCentro.X) / 3,
                                                    (s32)flareCentro.Y - (flareCentro.Y - opFlareCentro.Y) / 3);
    rect<s32> pqFlare(  (s32)(pqFlareCentro.X - 16 * mult),
                        (s32)(pqFlareCentro.Y - 16 * mult),
                        (s32)(pqFlareCentro.X + 16 * mult),
                        (s32)(pqFlareCentro.Y + 16 * mult));

    flarePq->setRelativePosition(pqFlare);


    //flare pequeno 2
    position2d<s32> pqFlareCentro2 = position2d<s32>((s32)flareCentro.X - (flareCentro.X - opFlareCentro.X) / 1.5f,
                                                     (s32)flareCentro.Y - (flareCentro.Y - opFlareCentro.Y) / 1.5f);
    rect<s32> pqFlare2( (s32)(pqFlareCentro2.X - 16 * mult),
                        (s32)(pqFlareCentro2.Y - 16 * mult),
                        (s32)(pqFlareCentro2.X + 16 * mult),
                        (s32)(pqFlareCentro2.Y + 16 * mult));

    flarePq2->setRelativePosition(pqFlare2);

};

bool MyEventReceiver::OnEvent(const SEvent& event)
{

    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0)
        JoystickState = event.JoystickEvent;

    if (event.EventType == irr::EET_KEY_INPUT_EVENT) // tecla pressionada
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    else if (event.EventType == EET_GUI_EVENT)
	{
        s32 id = event.GUIEvent.Caller->getID();
        IGUIEnvironment* env = Context.device->getGUIEnvironment();

		switch(event.GUIEvent.EventType)
		{
            case EGET_BUTTON_CLICKED:
            {
                switch(id)
				{
                    case CAMPANHA:
                        Context.selecao = 1;
                        break;

                    case INICIO:
                        Context.selecao =0;
                        break;

                    case FECHAR:
                        Context.fechar = true;
                        Context.selecao =0;
                        break;

                    case PLUS:
                            if(Context.rotate<2)
                                Context.rotate++;
                        printf("%d\n",Context.rotate);
                        break;

                    case MINUS:
                        if(Context.rotate>=1)
                            Context.rotate--;
                        printf("%d\n",Context.rotate);
                        break;

                    case INICIAR:
                        Context.selecao =2;
                        break;

                    case CONFIGURACAO:
                        Context.selecao =3;
                        break;

                    case CHANGE:
                        Context.selecao =0;
                        break;

                    case SAIR:
                        Context.selecao = 1024;
                        break;
                    };
            };

            case EGET_SCROLL_BAR_CHANGED:{
                s32 pos = ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos();
                switch(id){
                    case RESOLUCAO:{
                        array <vector2df> temp;

                        if(Context.windowType == 0){
                            temp.push_back(vector2df(800,600));
                            temp.push_back(vector2df(1024,768));
                            temp.push_back(vector2df(1280,1024));
                            temp.push_back(vector2df(1600,1200));
                        }
                        else{
                            temp.push_back(vector2df(1280,800));
                            temp.push_back(vector2df(1440,900));
                            temp.push_back(vector2df(1680,1050));
                            temp.push_back(vector2df(1920,1200));
                        }

                        Context.resolucao = dimension2d<u32>(temp[pos].X,temp[pos].Y);

                        printf("(%d) - %0.0f %0.0f /n",pos,Context.X,Context.Y);
                        break;
                    }

                    case VSYNC:
                        if(pos==0)
                            Context.Vsync = false;
                        else
                            Context.Vsync = true;

                        printf("Vsync %b",Context.Vsync?1:0);
                        break;

                    case FULLSCREEN:
                        if(pos==0)
                            Context.FullScreen = false;
                        else
                            Context.FullScreen = true;
                            printf("Fullscreen %b",Context.FullScreen?1:0);
                        break;
                }
            };

            default:
                break;
        }
		return false;
    }
    return false;
};

IrrlichtDevice * SAppContext::deviceRestart(){

    return(createDevice(EDT_OPENGL, dimension2d<u32>(resolucao),BITS,FullScreen,StencilBuffer,Vsync, 0));
}

SAppContext::SAppContext(){

    fechar = false; ///fechar a janela
    selecao =0;/// qual sera o primeiro menu no incio
    rotate = 0;
    name = "EMPTY"; /// nome do aviao
    windowType = 0; /// tipo de tela 4:3 16:9 ainda nao ativo

    ///Propriedades da tela. todos funcinando
    FullScreen = true;
    X=800;
    Y=600;
    //X=1366;
    //Y=768;
    //X=1280;
    //Y=720;
    resolucao= dimension2d<u32>(X,Y);
    BITS=32;
    StencilBuffer = false;
    Vsync=false;

    bSizeY = Y/25; /// tamanho do botao em Y
    bSizeX = X/5; /// tamanho dos botoes em X
};

///FUNCOES DO MENU
void  mainMenu(IVideoDriver * driver,IGUIEnvironment * guienv, ISceneManager* smgr, SAppContext * context,IAnimatedMeshSceneNode* node){

    guienv->addImage(driver->getTexture("media/logo.png"),
            position2d<int>((context->X/2)-300,(context->Y/2)-201));

    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("scene/menu/scene.x"));
    node->setMaterialFlag(EMF_LIGHTING, false);
    node->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
    node->setPosition(vector3df(0.0f));
    node->setFrameLoop(0,400);

    smgr->addCameraSceneNode(0, vector3df(0.0f,99.99f,-0.1f), vector3df(0.0f,100.0f,0.0f));

    IGUIButton * campanha = guienv->addButton(rect<s32>(((context->X/7)*2-(context->bSizeX/2)), ((context->Y/4)*3-(context->bSizeY/2)), ((context->X/7)*2+(context->bSizeX/2)), ((context->Y/4)*3+(context->bSizeY/2))),0,CAMPANHA,L"CAMPANHA");
    //campanha->setImage(driver->getTexture("campanha.png"));
    //campanha->setUseAlphaChannel(true);
    //campanha->setDrawBorder(false);

    IGUIButton * conf = guienv->addButton(rect<s32>(((context->X/7)*3.5-(context->bSizeX/2)), ((context->Y/4)*3-(context->bSizeY/2)), ((context->X/7)*3.5+(context->bSizeX/2)), ((context->Y/4)*3+(context->bSizeY/2))),0,CONFIGURACAO,L"CONFIGURACAO");
    //conf->setImage(driver->getTexture("conf.png"));
    //conf->setUseAlphaChannel(true);
    //conf->setDrawBorder(false);

    IGUIButton * sair = guienv->addButton(rect<s32>(((context->X/7)*5-(context->bSizeX/2)), ((context->Y/4)*3-(context->bSizeY/2)), ((context->X/7)*5+(context->bSizeX/2)), ((context->Y/4)*3+(context->bSizeY/2))),0,SAIR,L"SAIR");
    //sair->setImage(driver->getTexture("sair.png"));
    //sair->setUseAlphaChannel(true);
    //sair->setDrawBorder(false);

}

void endGame(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context){

    IGUIButton * sair = guienv->addButton(rect<s32>(((context->X/6)*2-(context->bSizeX/2)), ((context->Y/2)-(context->bSizeY/2)), ((context->X/6)*2+(context->bSizeX/2)), ((context->Y/2)+(context->bSizeY/2))),0,FECHAR,L"FECHAR");

    IGUIButton * voltar = guienv->addButton(rect<s32>(((context->X/6)*4-(context->bSizeX/2)), ((context->Y/2)-(context->bSizeY/2)), ((context->X/6)*4+(context->bSizeX/2)), ((context->Y/2)+(context->bSizeY/2))),0,INICIO,L"VOLTAR");
}

void loading(IVideoDriver * driver,IGUIEnvironment * guienv, SAppContext * context){
    srand(time (NULL));
    int choice=rand()%5;

    switch (choice){

        case 0:
            guienv->addImage(driver->getTexture("media/load1.jpg"),position2d<int>((context->X/2-400),(context->Y/2)-225));
            break;
        case 1:
            guienv->addImage(driver->getTexture("media/load2.jpg"),position2d<int>((context->X/2-400),(context->Y/2)-225));
            break;
        case 2:
            guienv->addImage(driver->getTexture("media/load3.jpg"),position2d<int>((context->X/2-400),(context->Y/2)-225));
            break;
        case 3:
            guienv->addImage(driver->getTexture("media/load4.jpg"),position2d<int>((context->X/2-400),(context->Y/2)-225));
            break;
        case 4:
            guienv->addImage(driver->getTexture("media/load5.jpg"),position2d<int>((context->X/2-400),(context->Y/2)-225));
            break;
    }

    driver->beginScene(true, true, SColor(0,0,0,0));
    guienv->drawAll();
    driver->endScene();
}

void escolhaMenu(IrrlichtDevice *device, IVideoDriver * driver, IGUIEnvironment * guienv, ISceneManager* smgr, SAppContext * context,
                 MyEventReceiver * receiver, controles botoes){

    int sessao=0;
    ISceneNode * node = smgr->addEmptySceneNode();
    array <IMeshSceneNode *> planes;
    array <stringw> nomes;
    while(device->run() && driver)
    {
        SEvent::SJoystickEvent joystickData = receiver->GetJoystickState();
        //IGUIButton * espelhostart;
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, SColor(0,0,0,0));
            //static boll entrar = false;
            //if(joystickData.IsButtonPressed(botoes.xX))
              //  espelhostart->setPressed(true);

            switch(sessao){

                case 0:
                    loading(driver,guienv,context);
                    sessao++;
                    break;

                default:

                    if(sessao==1){

                        guienv->addImage(driver->getTexture("media/airport.jpg"),
                                position2d<int>(0,0));

                        IGUIButton * minus = guienv->addButton(rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*7-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/8)*7+(context->bSizeY/2))),0,MINUS,L"<<");
                          //  botao1->setImage(butPressed);
                        IGUIButton * plus = guienv->addButton(rect<s32>(((context->X/6)*5-(context->bSizeX/2)), ((context->Y/8)*7-(context->bSizeY/2)), ((context->X/6)*5+(context->bSizeX/2)), (((context->Y/8)*7+(context->bSizeY/2)))),0,PLUS,L">>");

                        IGUIButton * start = guienv->addButton(rect<s32>(((context->X/6)*3-(context->bSizeX/2)), ((context->Y/8)*7.5-(context->bSizeY/2)), ((context->X/6)*3+(context->bSizeX/2)), (((context->Y/8)*7.5+(context->bSizeY/2)))),0,INICIAR,L"INICIAR JOGO");
                        //espelhostart = start;
                        smgr->addCameraSceneNode(0, vector3df(0,10,35), vector3df(0.0f));

                        planes.push_back(smgr->addMeshSceneNode(smgr->getMesh("models/747/747.x")));
                        planes.push_back(smgr->addMeshSceneNode(smgr->getMesh("models/160C/160C.x")));
                        planes.push_back(smgr->addMeshSceneNode(smgr->getMesh("models/thunderbolt/p47.x")));

                        planes[1]->setScale(vector3df(3.5));
                        planes[2]->setScale(vector3df(2.5));

                        for(int i=0; i<=2;i++){
                            planes[i]->setParent(node);
                            planes[i]->setPosition(vector3df(-i*120.0f,0.0f,0.0f));
                            planes[i]->setRotation(vector3df(0.0f,30.0f,0.0f));
                            planes[i]->setMaterialFlag(EMF_LIGHTING, false);
                        }

                        nomes.push_back("747");
                        nomes.push_back("160C");
                        nomes.push_back("thunderbolt");
                        sessao++;

                        node->setPosition(vector3df((context->rotate*120.0f),0.0f,0.0f));
                        sessao++;

                    }

                    else
                        node->setPosition(vector3df((context->rotate*120.0f),0.0f,0.0f));



            }

            if(context->selecao==2){
                context->name = nomes[context->rotate];
                break;
            }
            guienv->drawAll();
            smgr->drawAll();

            driver->endScene();
        }
    };


}

void configuracao(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context){

    guienv->addStaticText(L"CONFIGURACOES:", rect<s32>(((context->X/2)-(context->bSizeX/2)), ((context->Y/8)*0.5-(context->bSizeY/2)), ((context->X/2)+(context->bSizeX/2)), ((context->Y/8)*0.5+(context->bSizeY/2))), false);
    guienv->addStaticText(L"Modo:",         rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*1-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/8)*1+(context->bSizeY/2))), false);
    guienv->addStaticText(L"RESOLUCAO:",    rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*2-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/8)*2+(context->bSizeY/2))), false);
    guienv->addStaticText(L"FULLSCREEN:",   rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*3-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/3)*3+(context->bSizeY/2))), false);
    guienv->addStaticText(L"VSYNC: ",       rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*4-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/3)*4+(context->bSizeY/2))), false);

    IGUIScrollBar* modo = guienv->addScrollBar(true,
        rect<s32>(((context->X/6)*2-(context->bSizeX/2)), ((context->Y/8)*1-(context->bSizeY/3)), ((context->X/6)*2+(context->bSizeX/16)), ((context->Y/8)*1+(context->bSizeY/3))),0, FULLSCREEN);
	modo->setMax(1);

    IGUIScrollBar* resolucao = guienv->addScrollBar(true,
        rect<s32>(((context->X/6)*2-(context->bSizeX/2)), ((context->Y/8)*2-(context->bSizeY/3)), ((context->X/6)*2+(context->bSizeX/2)), ((context->Y/8)*2+(context->bSizeY/3))),0, RESOLUCAO);
	resolucao->setMax(3);
	resolucao->setPos(guienv->getSkin()->getColor(EGDC_WINDOW).getAlpha());

    IGUIScrollBar* fullscreen = guienv->addScrollBar(true, rect<s32>(((context->X/6)*2-(context->bSizeX/2)), ((context->Y/8)*3-(context->bSizeY/3)), ((context->X/6)*2+(context->bSizeX/16)), ((context->Y/8)*3+(context->bSizeY/3))),0, FULLSCREEN);
	fullscreen->setMax(1);
	fullscreen->setPos(guienv->getSkin()->getColor(EGDC_WINDOW).getAlpha());

    IGUIScrollBar* vsync = guienv->addScrollBar(true, rect<s32>(((context->X/6)*2-(context->bSizeX/2)), ((context->Y/8)*4-(context->bSizeY/3)), ((context->X/6)*2+(context->bSizeX/16)), ((context->Y/8)*4+(context->bSizeY/3))),0, VSYNC);
	vsync->setMax(1);
	vsync->setPos(guienv->getSkin()->getColor(EGDC_WINDOW).getAlpha());

    IGUIButton * voltar =    guienv->addButton(rect<s32>(((context->X/6)*1-(context->bSizeX/2)), ((context->Y/8)*7-(context->bSizeY/2)), ((context->X/6)*1+(context->bSizeX/2)), ((context->Y/8)*7+(context->bSizeY/2))),0,INICIO,L"Voltar");
    IGUIButton * confirmar = guienv->addButton(rect<s32>(((context->X/6)*4-(context->bSizeX/2)), ((context->Y/8)*7-(context->bSizeY/2)), ((context->X/6)*4+(context->bSizeX/2)), ((context->Y/8)*7+(context->bSizeY/2))),0,CHANGE,L"Confirmar mudancas");
}

int intro(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context){

    static int choice=0,run=0;
    static bool state=true;

    if(run == 150 || run == 300 || run == 450 || run >=600){
        state=true;
        choice++;
    }

    if(state){
        switch (choice){

            case 0:
                guienv->addImage(driver->getTexture("media/open.png"),position2d<int>((context->X/2-360),(context->Y/2)-180));
                state=false;
                break;

            case 1:
                guienv->addImage(driver->getTexture("media/sourcelogo.png"),position2d<int>((context->X/2-360),(context->Y/2)-180));
                state=false;
                break;

            case 2:
                guienv->addImage(driver->getTexture("media/infohouse.jpg"),position2d<int>((context->X/2-360),(context->Y/2)-180));
                state=false;
                break;

            case 3:
                guienv->addImage(driver->getTexture("media/alg.png"),position2d<int>((context->X/2-360),(context->Y/2)-180));
                state=false;
                break;

            default:
                choice =0;
                run=0;
                state=true;
                return 0;
        };
    };

    run++;

    printf("%d ",run);
    return 7;
}
