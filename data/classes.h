#include <math.h>
#include <ctime>
#include <windows.h>
#include <irrlicht.h>
#include <irrklang.h>
#include <newton.h>
#include <dVector.h>
#include <dMatrix.h>
#define GRAVITY -9.8

using namespace irr;
using namespace irrklang;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

enum
{
    FLAP = 0,
	ROLL = 1,
	YAW = 2,
	PITCH = 3,
	GEAR = 4,
	GEARCOVER = 5,
	LIGHT = 6,
	EJECT = 7,
	SHOT = 8,
	SELWEAP = 9,
	ACCELL = 10,
	DECCELL = 11,
	ENGINEON = 12
};

struct packPhysics
{
    dVector lGearForce;
    dVector lGearTorque;
    IMeshSceneNode * node;
};

int joy(array<SJoystickInfo> * joystickInfo, IrrlichtDevice *device);

/// STRUCT START STOP TIME
typedef struct
{
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
}stopWatch;

/// CLASS LIMTED FRAME
class CStopWatch
{
    private:
        stopWatch timer;
        LARGE_INTEGER frequency;
        double LIToSecs( LARGE_INTEGER & L);
    public:
        CStopWatch();
        void startTimer( );
        void stopTimer( );
        double getElapsedTime();
};


///REFLEXO DO SOL
class sol
{
    public:
        sol(IrrlichtDevice * deviceQvem, ISceneManager * smgrQvem,IGUIEnvironment * guienV, IVideoDriver * driveR);
        void reflexoSol(ILightSceneNode * sol);
    private:
        IGUIEnvironment * guienv;
        IVideoDriver * driver;
        IrrlichtDevice * device;
        ISceneManager * smgr;
        IGUIImage * flare;
        IGUIImage * flareOp;
        IGUIImage * flareIn;
        IGUIImage * flarePq;
        IGUIImage * flarePq2;
        f32 mult;
        bool runOnce;
};

///outras do MENU
class SAppContext
{
    public:
        SAppContext(); //construtor
        IrrlichtDevice * deviceRestart();

        IrrlichtDevice * device;
        bool fechar;
        int selecao;
        int rotate;
        stringw name;

///VALORES DE OBJETOS
        int windowType;
        dimension2d<u32> resolucao;
        u32 BITS;
        bool FullScreen;
        bool StencilBuffer;
        bool Vsync;
        u32 X;
        u32 Y;
        int bSizeY;
        int bSizeX;
};

enum
{
    CAMPANHA,
    INICIO,
    SAIR,
    FECHAR,
    PLUS,
    MINUS,
    INICIAR,
    CONFIGURACAO,
    RESOLUCAO,
    FULLSCREEN,
    VSYNC,
    CHANGE
};

class MyEventReceiver : public irr::IEventReceiver
{
    public:
	MyEventReceiver(SAppContext & context) : Context(context) {

		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
    };

	virtual bool OnEvent(const irr::SEvent& event);

	bool IsKeyDown(EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
    const SEvent::SJoystickEvent & GetJoystickState(void) const{

        return JoystickState;
    }
	private:
	SAppContext & Context;
    SEvent::SJoystickEvent JoystickState;
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


struct controles
{
    int triangulo;
    int circulo;
    int xX;
    int quadrado;
    int l1;
    int r1;
    int l2;//Liga o avião
    int digEsq;
    int r2;//Camera;
    bool ajeitaDir;
    int start;
    u16 gearOn;
};
/// FUNCOES DO MENU
void mainMenu(IVideoDriver * driver,IGUIEnvironment * guienv, ISceneManager* smgr, SAppContext * context,IAnimatedMeshSceneNode* node);
void loading(IVideoDriver * driver,IGUIEnvironment * guienv, SAppContext * context);
void escolhaMenu(IrrlichtDevice *device, IVideoDriver * driver, IGUIEnvironment * guienv, ISceneManager* smgr, SAppContext * context, MyEventReceiver * receiver, controles botoes);
void configuracao(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context);
int intro(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context);
void endGame(IVideoDriver * driver, IGUIEnvironment * guienv, SAppContext * context);
