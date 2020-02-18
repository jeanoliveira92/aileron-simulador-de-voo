#include "data/controls.h"

int main()
{

/// SOURCE GAME
    SAppContext context; /// CLASSE DAS VARIAVEIS E BOTOES GLBAIS
    IrrlichtDevice * device = context.deviceRestart(); ///CRIO O DEVICE APARTIR DE UMA FUNCAO
    ///SOM - IRRKLANG
    ISoundEngine * sEngine = createIrrKlangDevice();
    ///JoyStick
    array<SJoystickInfo> joystickInfo;
      if(joy(&joystickInfo, device) < 0)
    { /// CRIADA POR NOS PARA EXBIR INFORMAÇÕES DO JOYSTICK
        device->activateJoysticks(joystickInfo);
        printf("\nJOY ATIVADO");
    }
    SEvent::SJoystickEvent joystickData;
    ///*******************************
    controles botoes;
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
    };


    ///****************************8
    context.device = device;
    MyEventReceiver receiver(context); /// INSIRO AS VARIAVEIS GLOBAIS NO receiver
    device->setEventReceiver(&receiver);///PEGO O PACOTE receiver E SETO ELE NO DEVICE

    IVideoDriver* driver = device->getVideoDriver();
    IGUIEnvironment* guienv = device->getGUIEnvironment();
    ISceneManager* smgr = device->getSceneManager();

 	IGUISkin* skin = guienv->getSkin(); /// SKIN É TIPO DOS ATRBUTOS DOS ELEMENTOS DA GUI
	IGUIFont* font = guienv->getFont("media/bradley_12.bmp");
	skin->setFont(font);

    CStopWatch hrTimer; /// CLASSE QUE LIMITA OS FPS

/// COMEÇANDO A DESENVOLVER . . .

    bool estado = true; /// VARIAVEL RESPONSAVEL POR ENTRAR OU NÃO NO SWITCH
    int clear = context.selecao; // variavel que testa a troca de funcao;

    ICameraSceneNode * camera;
    ITexture * background = 0; /// INICIA COM UM FUNDO NULO

    IAnimatedMeshSceneNode* node; /// OBJETO ANIMADO DO MENU

    int lastFPS = -1; // variavel para prever o frame por segundo
    //SEvent::SJoystickEvent joystickData = receiver->GetJoystickState();
    while(device->run())
    {
        SEvent::SJoystickEvent joystickData = receiver.GetJoystickState();
        //printf("\n%d",joystickInfo.size());
        if (device->isWindowActive()) /// IF A JANELA ESTA EM FOCO, OU SEJA, ESTA SELECIONADA
        {
            if(context.fechar) /// IF A VARIAVEL FECHAR FOR TRUE ELE FECHA O DEVICE
                device->closeDevice();
            if(joystickData.IsButtonPressed(botoes.xX) && context.selecao == 0)
            {
                estado=true;
                context.selecao = 1;
            }
            else if(joystickData.IsButtonPressed(botoes.circulo) && context.selecao == 0)
            {
                estado = true;
                device->sleep(600);
                context.selecao = 1024;
            }
            else if(joystickData.IsButtonPressed(botoes.circulo) && context.selecao == 1024)
            {
                estado = true;
                context.fechar = true;
            }
            else if(joystickData.IsButtonPressed(botoes.xX) && context.selecao == 1024)
            {
                estado = true;
                device->sleep(600);
                context.selecao = 0;
            }
            else if(joystickData.IsButtonPressed(botoes.xX) && context.selecao == 1)
            {
                estado = true;
                device->sleep(600);
                context.selecao = 2;
            };
            //printf("\n -- %d",context.selecao);
            if(estado){
                switch (context.selecao)
                {

                    case 0:/// MAIN MENU
                        sEngine->play2D("musica/cabriolinha.ogg",true);
                        background = driver->getTexture("scene/menu/fs1.jpg");
                        mainMenu(driver,guienv,smgr,&context,node);
                        estado=false;
                        break;

                    case 1: /// MENU DE ESCOLHA DE AVIOES
                        escolhaMenu(device, driver,guienv, smgr, &context, &receiver, botoes);
                        estado=false;
                        break;

                    case 2: /// JOGO
                        context.selecao = principal_main(device, driver,guienv, &context, &hrTimer,&receiver, sEngine, joystickInfo, botoes);
                        break;

                    case 3: /// CONFIGURAÇÔES
                        configuracao(driver,guienv,&context);
                        break;

                    case 7: ///INTRODUCAO
                        context.selecao=intro(driver,guienv,&context);
                        estado=true;
                        break;

                    case 1024: /// VARIAVEL ALTA PARA SAIR
                        endGame(driver,guienv,&context);
                        estado=false;
                        break;

                    default:
                        break;
                }
            }


            driver->beginScene(true, true, SColor(0,0,0,0));
            hrTimer.startTimer();

            if(context.selecao != clear){ /// OPÇÃO PARA LIMPAR OS CONTEUDOS QUANDO MUDA DE CENA
                estado=true; /// HABILITA PARA ENTRAR NO SWITCH
                guienv->clear(); /// LIMPARA TODOS OS ELEMENTOS DA GUI
                smgr->clear(); /// LIMPAS TODOS OS OBJETOS DA CENA
            }

            else /// SE NÃO ELE AINDA CONTINUA EM ALGUM MENU ENTÃO CONTINUA CARREGANDO O background
                driver->draw2DImage(background,position2d<s32>(0,0));


            clear = context.selecao; /// GRAVA NA VARIAVEL QUAL O MENU ATUAL

            smgr->drawAll();
            guienv->drawAll();
            driver->endScene();
            //printf("%d \n",driver->getFPS());

            hrTimer.stopTimer();
            s16 timeElp = (s16)((0.017 - hrTimer.getElapsedTime())*1000);
            if(timeElp > 0)
            device->sleep(timeElp,false);
        }
    };
    sEngine->drop();
    device->drop(); /// DESTROI O DEVICE
    return 0;
}

