#include "planes.h"

class sons
{
    public:
        sons(ISoundEngine * sEngine, stringw aviao);
        void startMotor(ISoundEngine * sEngine);
        ISoundSource * musicaFundo;
        ISoundSource * explodir;
        ISoundSource * somPlane;
        ISoundSource * ligEngine;
        bool musicLiga;//Para evitar ecos na inicialização do som do avião
        bool musicSet;
        bool musicExpl;
    private:
        stringw namePlane;
};


void readControls(MyEventReceiver * receiver, SEngineFighter * player, ISoundEngine * sEngine, controles botJoy, sons *audio);

int principal_main(IrrlichtDevice * device, IVideoDriver * driver, IGUIEnvironment * guienv,
                    SAppContext * context, CStopWatch * hrTimer,MyEventReceiver * receiver, ISoundEngine * sEngine, array<SJoystickInfo> joystickInfo, controles botoes);

class cria_scene
{
    private:
        sol * iluminar;
        ILightSceneNode * luzPrincipal;
        IrrlichtDevice * mydevice;
        IMeshSceneNode * cenario;
        IMeshSceneNode * superficie;
        int qualCeu;
    public:
        vector3df ceuPos;
        vector3df ceuRot;
        void posiciona_ceu(vector3df camera);
        cria_scene(ISceneManager* smgr, IVideoDriver* driver, NewtonWorld * nWorld, IrrlichtDevice * device, IGUIEnvironment * guienv, sol *ensolarado);
};

