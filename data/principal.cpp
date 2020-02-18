#include "controls.h"

int principal_main(IrrlichtDevice * device, IVideoDriver * driver, IGUIEnvironment * guienv,
        SAppContext * context, CStopWatch * hrTimer,MyEventReceiver * receiver, ISoundEngine * sEngine, array<SJoystickInfo> joystickInfo, controles botoes)
{
    for(int i=0; i<=255;i++) /// FRESCURINHA PARA BRILHAR A TELA
    {
        driver->beginScene(true, true, SColor(0,i,i,i));
        driver->endScene();
    };
    sEngine->removeAllSoundSources();
    loading(driver,guienv,context); /// CARREGA UMA IMAGEM DE LOADING

    ITimer * timer = device->getTimer();
    IGUIEnvironment* guienvPainel = device->getGUIEnvironment();
    ISceneManager* smgr = device->getSceneManager();
    ISceneManager* smgrPainel = smgr->createNewSceneManager(); ///CRIA UM SEGUNDO SCENE MANAGER PARA AS INSTRUMENTAÇÕES

    ///ESCOLHER UM AVIAO
    int escolhe;

    if(context->name =="thunderbolt") escolhe = 1;
    else if (context->name =="747") escolhe = 2;
    else if (context->name == "160C") escolhe = 3;
    else escolhe = 4;

    ///PHYSIC DEVICE
    NewtonWorld * nWorld = NewtonCreate ();
    dVector worldMin (-30000.0f, -20.0f, -30000.0f);
    dVector worldMax (30000.0f, 5100.0f, 30000.0f);
    NewtonSetWorldSize (nWorld, &worldMin[0], &worldMax[0]);

    if(context->name == "747")
        sEngine->play2D("musica/aeromoca.wav",false);
    //else if(context->name == "thunderbolt")
      //  sEngine->play2D("musica/Sentaapua.wav",false);

    ///INICIANDO JOYPAD DEVICE

    //array<SJoystickInfo> joystickInfo;
/*
    if(joy(&joystickInfo, device) < 0)
    { /// CRIADA POR NOS PARA EXBIR INFORMAÇÕES DO JOYSTICK
        device->activateJoysticks(joystickInfo);
        printf("\nJOY ATIVADO");
    }
*/
    ///Cameras....
    ICameraSceneNode * cameraPainel = smgrPainel->addCameraSceneNode(0, vector3df(2.0f, 0.0f, 0.0f), vector3df(0.0f));

    ICameraSceneNode * cam2 = smgr->addCameraSceneNode(0, vector3df(5, -7, -8), vector3df(0,-8,0));
    cam2->setFarValue(20000);

    ICameraSceneNode * camera = smgr->addCameraSceneNode(0, vector3df(0,0,0), vector3df(0,0,0));
    camera->setFarValue(20000);

    guienv->clear();
    ///Construtores.......
    SEngineFighter * player = new SEngineFighter(device,nWorld,context->name);

    sol * ensolarado = new sol(device, smgr, guienv, driver);

    Painel * mostraPainel = new Painel(smgrPainel, context->name, driver, timer, guienvPainel);

    cria_scene * scene = new cria_scene(smgr, driver, nWorld, device, guienv, ensolarado);

    incendio * vamosIncendiar = new incendio (device, player->getPosition(), 0);

    sons * audio = new sons(sEngine, context->name);//Classe de som (O construtor está implementado no arquivo controls.cpp )

    player -> setGearDown(); //trem de pouso

    ///GET FUSELAGEM
    IMeshSceneNode * fuselagem = player->getFuselage();

    ///CAM OBJECT VIEW
    ISceneNode * Orient = smgr->addEmptySceneNode();
    //Orient->setMaterialFlag(EMF_LIGHTING, false);
    //Orient->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
    //Orient->setScale(vector3df(10.0f, 10.0f, 10.0f));
    Orient->setPosition(fuselagem->getPosition()+(vector3df(0.0f,2.0f,2.0f)));
    Orient->setParent(fuselagem);

    camera->setParent(fuselagem);

    camera->setPosition(vector3df(0.0f, 5.0f, -10.f));

    bool teclaPres=true;
    int posCam = 1;//Posição inicial da camera; 0 é o padrâo do Ney,
    float atuaPont;
    //static float acum_alt = 0.0f;
    vector3df vecCam(0.0f);
    vector3df rotCam(0.0f);
    vector3df tem(0.0f,1.0f, 20.0f);
    float apgInc = 0.0f;
    bool verInc = false;
    bool verifBat = false;
    float distFuselagem = 0.0f;
    bool finish = false;
    bool expBat =false;
    bool ligMotor = false;//Verifica se o avião já ligou o motor!
    bool acabouGas = false;//Verifica se a gasolina acabou;

    ///FPS VARIAVEIS
    int lastFPS = -1;
    SEvent::SJoystickEvent joystickData;
    /*controles botoes;
    if(joystickInfo.size()!=0)
    {
        botoes.triangulo    =   0;
        botoes.circulo      =   1;
        botoes.xX           =   2;
        botoes.quadrado     =   3;
        botoes.l1           =   4;
        botoes.r1           =   5;
        botoes.l2           =   6;
        botoes.r2           =   7;
        botoes.start        =   9;
        botoes.digEsq       =   10;
        botoes.ajeitaDir    =   true;
    }
    else
    {
        botoes.triangulo    =   40;
        botoes.circulo      =   40;
        botoes.xX           =   40;
        botoes.quadrado     =   40;
        botoes.l1           =   40;
        botoes.r1           =   40;
        botoes.l2           =   40;
        botoes.r2           =   40;
        botoes.start        =   40;
        botoes.digEsq       =   40;
        botoes.ajeitaDir    =   false;
    };*/
        botoes.gearOn       =    0;
    IGUIImage * pause = guienv->addImage(driver->getTexture("pause.png"),position2d<int>((context->X/2-200),(context->Y/2)-255));
    pause->setVisible(false);
    while(device->run())
    {
        joystickData=receiver->GetJoystickState();
        ///pausar o jogo
        if(receiver->IsKeyDown(KEY_SPACE)|| joystickData.IsButtonPressed(botoes.start))
        {
                printf("GUI ATIVADA");
                device->sleep(500);
                sEngine->setSoundVolume(0.1f);
                //guienv->addImage(driver->getTexture("pause.png"),position2d<int>((context->X/2-200),(context->Y/2)-255));
                pause->setVisible(true);
                IGUIButton * campanha = guienv->addButton(rect<s32>(((context->X/2)-(context->bSizeX/2)), ((context->Y/2)-50-(context->bSizeY/2)), ((context->X/2)+(context->bSizeX/2)), ((context->Y/2)-50+(context->bSizeY/2))),0,INICIO,L"MENU INICIAL");

                IGUIButton * sair = guienv->addButton(rect<s32>(((context->X/2)-(context->bSizeX/2)), ((context->Y/2)+50-(context->bSizeY/2)), ((context->X/2)+(context->bSizeX/2)), ((context->Y/2)+50+(context->bSizeY/2))),0,FECHAR,L"SAIR");

                while(device->run())
                {
                    joystickData=receiver->GetJoystickState();
                    if(receiver->IsKeyDown(KEY_SPACE)|| joystickData.IsButtonPressed(botoes.start))
                        break;
                    if(device->isWindowActive())
                    {
                        driver->beginScene(true, true, SColor(0,200,200,200));
                        if(joystickData.IsButtonPressed(botoes.xX))//Para voltar ao menu com o Joystick
                            context->selecao = 0;
                        if(joystickData.IsButtonPressed(botoes.circulo))//Para sair com o Joystick
                        {
                            context->selecao = 1024;
                            context->fechar = true;
                        };

                        if(context->selecao!=2)
                        {
                            sEngine->removeAllSoundSources();
                            sEngine->setSoundVolume(1.0f);
                            return context->selecao;
                        };
                        smgr->drawAll();
                        guienv->drawAll();
                        driver->endScene();
                    };
                };
                //guienv->clear();
                pause->setVisible(false);
                campanha->setVisible(false);
                sair->setVisible(false);
                device->sleep(300);
        };

        if(player->motorLig)
        {
            ligMotor =true;
        };
        if(!acabouGas && ligMotor)
            acabouGas = mostraPainel->fuelTemp(timer->getTime());
        else
            player->startEngine(false);
        if(acabouGas)
            player->acabouGasolina = true;

        vector3df pes = fuselagem->getPosition();//Altitude do avião

        distFuselagem = fuselagem->getPosition().getLength();//if(fuselagem->getPosition().getLength() > 300.0f)

        verifBat = player->verifCol();

        verifBat = mostraPainel->mostra_warning(verifBat,distFuselagem,pes.Y, pes.getDistanceFrom(vector3df(0.0f, 0.0f, 0.0f)));//printf("\n%0.2f",fuselagem->getPosition().Z);

        if(verifBat)expBat = true;

        ///bussula
        vector3df ori = Orient->getAbsolutePosition();
        vector3df pln = fuselagem->getAbsolutePosition();

        ori.Y = 0.0f;
        pln.Y = 0.0f;

        line3df linBus (ori, pln);
        vector3df oraviao = linBus.getVector();

        ///Atualizações dos medidores de velocidade, aceleração....etc

        mostraPainel->rotBussula(oraviao.getHorizontalAngle());//Atualiza a posição da bussula;
        mostraPainel->atualizaALT(pes);//Atualiza o altimetro;
        atuaPont = player->getAccell(context->name);//Recebe o valor do RPM
        mostraPainel->atualizaRPM(atuaPont);//Atualiza o medidor de RPM no painel
        atuaPont = player->getVeloc(context->name);//Recebe o valor da velocidade;
        mostraPainel->atualizaVeloz(atuaPont);//Atualiza a velocidade no painel
        ///Cuidado pra deixar  a linha do finish = mostraP..... logo após  a atualização
        ///da velocidade, pois ela precisa deste valor.(Ou seja, não mudar de lugar!)
        ///*************************************

        finish = mostraPainel->fim_de_jogo(pes,atuaPont,expBat);//Verifica se o  jogo vai acabar;

        ///Posiciocontext->namento das Câmeras
        if(posCam == 1 || posCam == 2)
        {
            if(posCam == 2)//opção 3 de camera
            {
                if(context->name == "747")
                    camera->setPosition(vector3df(0.0f, 15.0f, -32.0f));
                else if (context->name == "160C")
                    camera->setPosition(vector3df(0.0f, 1.6f, -2.0f));
                else
                    camera->setPosition(vector3df(0.0f, 2.0f, -2.0f));
            }
            else//opção 2 da camera;
            {
                if(context->name == "747")
                    camera->setPosition(vector3df(0.0f, 40.0f, -80.f));
                else if (context->name == "160C")
                    camera->setPosition(vector3df(0.0f, 4.0f, -8.f));
                else
                    camera->setPosition(vector3df(0.0f, 5.0f, -10.f));
            }

            smgr->setActiveCamera(camera);
            camera->setTarget(Orient->getAbsolutePosition());
            CMatrix4<f32> naveMatriz = fuselagem->getAbsoluteTransformation();

            vector3df upVector (0.0f, 1.0f, 0.0f);

            naveMatriz.rotateVect(upVector);
            upVector = upVector.normalize();
            camera->setUpVector(upVector);
        }
        else
        {
            smgr->setActiveCamera(cam2);
            vector3df planePos = player->getPosition();
            cam2->setTarget(planePos);
            if (context->name == "747")
                cam2->setPosition(vector3df(planePos.X + 80, planePos.Y+10, planePos.Z - 15));
            else if (context->name == "160C")
                cam2->setPosition(vector3df(planePos.X + 6.5, planePos.Y+1, planePos.Z - 1.5));
            else
                cam2->setPosition(vector3df(planePos.X + 9, planePos.Y, planePos.Z - 3));
        };

        if(receiver->IsKeyDown(KEY_KEY_C) || joystickData.IsButtonPressed(botoes.r2))//R2
        {
            if (teclaPres)
            {
                switch (posCam)
                {
                    case 0:
                        posCam = 1;
                        break;
                    case 1:
                        posCam = 2;
                        break;
                    case 2:
                        posCam = 0;
                        break;
                };

                teclaPres = false;
            };
        }
            else
                teclaPres = true;

        ///************************** INCENDIAR
       if (verifBat || verInc)
        {
            if(!audio->musicExpl)
            {

                sEngine->removeSoundSource(audio->somPlane);//Remove o som da memória( Unico jeito q achei)
                sEngine->play2D(audio->explodir,false,false,false,true);
                //sEngine->play2D(ligarMotor,false,false,false,true);
                audio->musicExpl = true;
            };
            vamosIncendiar->animar();

            fuselagem->setVisible(false);
            //posCam = 1;
            if(apgInc <5.0f)
                verInc = true;
            else
            {
                vamosIncendiar->apagarInc();
                verInc = false;
                apgInc = 0.0f;
            };
            apgInc +=0.01f;
        };
        vamosIncendiar->atualizaPosition(player->getPosition());

        ///POSICIONADO O CEU e o SOL
        scene->posiciona_ceu(camera->getAbsolutePosition());

		///INICIO DA CENA ( PER FRAME )

        hrTimer->startTimer(); /// INICIA O CONTADOR DO TIMER
        driver->beginScene(true, true, SColor(0,200,200,200));

        readControls(receiver,player,sEngine, botoes, audio);

        NewtonUpdate(nWorld, 1);
        smgrPainel->drawAll();
        smgr->drawAll();

        guienv->drawAll();

        driver->endScene();

        ///GAME LABEL - DISPLAY FPS
        int fps = driver->getFPS();
        if(lastFPS != fps)
        {

			core::stringw tmp(L"Aileron Game Teste | Controles: ");
            tmp += joystickInfo.size();
            tmp += L" | Driver: ";
			tmp += driver->getName();
			tmp += L" - FPS: ";
			tmp += fps;

			device->setWindowCaption(tmp.c_str());
			lastFPS = fps;
		};

        ///LIMITED FPS
        hrTimer->stopTimer(); ///PARA O CONTADOR
        s16 timeElp = (s16)((0.017 - hrTimer->getElapsedTime())*1000);
        if(timeElp > 0)
        device->sleep(timeElp,false);


        if(finish)
        {
            smgr->clear();
            smgrPainel->clear();
            guienv->clear();
            break;
        }
    };
    sEngine->removeAllSoundSources();
    //sEngine->drop();
    player->~SEngineFighter();
    delete (player);
    scene->~cria_scene();
    delete (scene);
    return 0;
};


