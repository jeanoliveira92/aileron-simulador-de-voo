#include "controls.h"

cria_scene :: cria_scene(ISceneManager* smgr, IVideoDriver* driver, NewtonWorld * nWorld, IrrlichtDevice * device, IGUIEnvironment * guienv, sol * ensolarado)
{
    mydevice = device;
    iluminar = ensolarado;
    IAnimatedMeshSceneNode * taxi747 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("models/747/taxi_747.x"));
    taxi747->setFrameLoop(0,800);
    taxi747->setAnimationSpeed(10.0f);
    taxi747->setScale(vector3df(3.0f));

    IAnimatedMeshSceneNode * taxi160C = smgr->addAnimatedMeshSceneNode(smgr->getMesh("models/160C/160C_taxi.x"));
    //ITriangleSelector * quv = smgr->createTriangleSelector(taxi160C->getMesh(),taxi160C);
    //taxi160C->setTriangleSelector(quv);
    //NewtonCollision * taxi160CCol = addHullCollision(taxi160C->getMesh(), driver, nWorld, dVector(0.0f, 0.0f, 0.0f), 0);
    //NewtonBody * taxi160CBody = NewtonCreateBody(nWorld,taxi160CCol);
    taxi160C->setFrameLoop(0,800);
    taxi160C->setAnimationSpeed(10.0f);
    taxi160C->setScale(vector3df(5.0f));

    IAnimatedMeshSceneNode * zepel = smgr->addAnimatedMeshSceneNode(smgr->getMesh("scene/Zeppel/zeppel.x"));
    //ITriangleSelector * uut = smgr->createTriangleSelector(zepel->getMesh(),zepel);
    //zepel->setTriangleSelector(uut);
    //NewtonCollision * zepelCol = addHullCollision(zepel->getMesh(), driver, nWorld, dVector(0.0f, 0.0f, 0.0f), 0);
    //NewtonBody * zepelBody = NewtonCreateBody(nWorld,zepelCol);
    zepel->setFrameLoop(0,800);
    zepel->setAnimationSpeed(0.7f);
    zepel->setScale(vector3df(10.0f,10.0f,8.0f));


    superficie = smgr->addMeshSceneNode(smgr->getMesh("scenary/scenary.x"));
    ITriangleSelector * ts = smgr->createTriangleSelector(superficie->getMesh(),superficie);
    superficie->setTriangleSelector(ts);
    NewtonCollision * superficieCol = addHullCollision(superficie->getMesh(), driver, nWorld, dVector(0.0f, 0.0f, 0.0f), 0);
    NewtonBody * superficieBody = NewtonCreateBody(nWorld,superficieCol);

    IMeshSceneNode * muro = smgr->addMeshSceneNode(smgr->getMesh("scenary/muro.x"));
    muro->setPosition(vector3df(0.0f, 0.0f, 3500.0f));
    //muro->setScale(vector3df(2.0f));
    ITriangleSelector * tx = smgr->createTriangleSelector(muro->getMesh(),muro);
    muro->setTriangleSelector(tx);
    NewtonCollision * muroCol = addHullCollision(muro->getMesh(), driver, nWorld, dVector(0.0f, 0.0f, 3500.0f), 0);
    NewtonBody * muroBody = NewtonCreateBody(nWorld,muroCol);
    NewtonReleaseCollision(nWorld,muroCol);

    /*IMeshSceneNode * arco = smgr->addMeshSceneNode(smgr->getMesh("scenary/arco_backup.x"));
    arco->setPosition(vector3df(0.0f, 0.0f, 1000.0f));
    //arco->setScale(vector3df(3.5f, 3.0f, 1.0f));
    ITriangleSelector * ttt = smgr->createTriangleSelector(arco->getMesh(),arco);
    arco->setTriangleSelector(ttt);
    NewtonCollision * arcoCol = addHullCollision(arco->getMesh(), driver, nWorld, dVector(0.0f, 0.0f, 1000.0f), 0);
    NewtonBody * arcoBody = NewtonCreateBody(nWorld,arcoCol);
    NewtonReleaseCollision(nWorld,arcoCol);*/

    IMeshSceneNode * aeroporto = smgr->addMeshSceneNode(smgr->getMesh("scenary/pista/aeroporto.x"));
    aeroporto->setPosition(vector3df(-990.0f, 0.1f, 1725.0f));
    NewtonCollision * aeroportoCol = addHullCollision(aeroporto->getMesh(), device->getVideoDriver(), nWorld, dVector(0.0f,0.0f,0.0f),0);
    NewtonBody * aeroportoPBody = NewtonCreateBody(nWorld,aeroportoCol);
    dMatrix matrixA = GetIdentityMatrix();
    matrixA.m_posit = dVector(-990.0f, 0.1f, 1725.0f);
    NewtonBodySetMatrix(aeroportoPBody,&matrixA[0][0]);
    NewtonReleaseCollision(nWorld,aeroportoCol);

    ///*******Muros de contenção*******************
    for(int w =0; w<15; w++)
    {
        IMeshSceneNode * conter = smgr->addMeshSceneNode(smgr->getMesh("scenary/muro.x"));
        conter->setPosition(vector3df(-150.0f, 0.0f, 200.0f + w *150));
        conter->setRotation(vector3df(0.0f, 90.0f, 0.0f));
        NewtonCollision * conterCol = addHullCollision(conter->getMesh(), device->getVideoDriver(), nWorld, dVector(0.0f,0.0f,0.0f),0);
        NewtonBody * conterBody = NewtonCreateBody(nWorld,conterCol);
        dMatrix matrixM = GetIdentityMatrix();
        matrixM.m_posit = dVector(-150.0f, 0.0f, 200.0f + w *150);
        NewtonBodySetMatrix(conterBody,&matrixM[0][0]);
        NewtonReleaseCollision(nWorld, conterCol);
    };

    ///PREDIOS COM COLISÃO*************************************
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            IMeshSceneNode * conjPredio = smgr->addMeshSceneNode(smgr->getMesh("fx/predio/pr50m.x"));
            //conjPredio->setMaterialFlag(EMF_LIGHTING, false);
            conjPredio->setPosition(vector3df(1500.0f - j*200, 0.0f, 1700.0f + i *200));
            NewtonCollision * conjPCol = addHullCollision(conjPredio->getMesh(), device->getVideoDriver(), nWorld, dVector(0.0f,0.0f,0.0f),0);
            NewtonBody * conjPBody = NewtonCreateBody(nWorld,conjPCol);
            dMatrix matrix = GetIdentityMatrix();
            matrix.m_posit = dVector(1500.0f - j*200, 0.0f, 1700.0f + i *200);
            NewtonBodySetMatrix(conjPBody,&matrix[0][0]);
            NewtonReleaseCollision(nWorld,conjPCol);
        };
    };

    ///CÉU
    qualCeu =0;
    srand(time(NULL));
    qualCeu = rand()%4;
    //qualCeu = 0;
    cenario = smgr->addMeshSceneNode(smgr->getMesh("scenary/ceu/ceu.x"));
    cenario->setScale(vector3df(4.0f,4.0f,4.0f));
    //cenario->setMaterialFlag(EMF_LIGHTING, false);
    cenario->setMaterialTexture(0,driver->getTexture("scenary/ceu/fs1.jpg"));

    ceuPos = vector3df(0.0f);
    ceuRot = vector3df(0.0f);

    ///SOl OBJECT
    ISceneNode * Orient2 = smgr->addEmptySceneNode();
    Orient2->setMaterialFlag(EMF_LIGHTING, false);
    Orient2->setScale(vector3df(3.0f, 3.0f, 3.0f));
    Orient2->setParent(cenario);

    ///ILUMINAÇÃO
    SLight luzSetup;
    //luzSetup.AmbientColor = SColor(255,70,40,20);//Backup
    //luzSetup.AmbientColor = SColor(255,200,200,200);
    luzSetup.DiffuseColor = SColor(255,240,200,130);//emite

    //ILightSceneNode * luzPrincipal = smgr->addLightSceneNode(0, vector3df(-79.0f,-30.0f,-386.0f), SColor(255,230,100,90), 1500);
    //luzPrincipal->setPosition(vector3df(-450.0f,1200.0f,-2450.0f));
    //luzPrincipal->setParent(Orient2);
    luzPrincipal = smgr->addLightSceneNode(0, vector3df(20.0f,20.0f,20.0f), SColor(255,230,100,90), 5000);

    switch (qualCeu)
    {
        case 0:
            luzSetup.AmbientColor = SColor(255,100,80,80);// Amanhecendo
            luzPrincipal->setPosition(vector3df(-10000.0f,300.0f, 31000.0f));
            break;
        case 1:
            luzSetup.AmbientColor = SColor(255,140,130,130);
            luzPrincipal->setPosition(vector3df(-10000.0f,6000.0f, 15000.0f));
            break;
        case 2:
            luzSetup.AmbientColor = SColor(255,220,220,220);//Meio dia
            luzPrincipal->setPosition(vector3df(0.0f,6000.0f, 0.0f));
            break;
        case 3:
            luzSetup.AmbientColor = SColor(255,110,100,90);// entardecer
            luzPrincipal->setPosition(vector3df(1000.0f,200.0f, -31000.0f));
            break;
        case 4:
            luzSetup.AmbientColor = SColor(255,20,20,20);//A noitinha
            luzSetup.DiffuseColor = SColor(255,30,30,30);//emite
            luzPrincipal->setPosition(vector3df(0.0f,10000.0f, 0.0f));

            break;
    };
    luzPrincipal->setLightData(luzSetup);

};///Fim da Função

void cria_scene :: posiciona_ceu(vector3df camera)///POSICIONADO O CEU e o SOL
{
   // printf("\n%d",qualCeu);
    //if(qualCeu !=4)//A noite não tem sol!!!!
    //printf("\nAqui");
    iluminar->reflexoSol(luzPrincipal);
     //printf("\nAquita");
    ceuPos=camera;
    ceuPos.Y=0;
    ceuRot=(vector3df(ceuRot.X+0.0,ceuRot.Y+0.02,0.0f));
    cenario->setPosition(ceuPos);
    cenario->setRotation(ceuRot);
};
