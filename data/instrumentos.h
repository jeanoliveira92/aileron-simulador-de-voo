#include "classes.h"
struct fumacaStr
{
    IBillboardSceneNode* fumaca;
    vector3df posicao;
    bool ativo;
    float tempo;
};

class incendio
{
    private:
    array<ITexture *> expSprite;
    IBillboardSceneNode * explosao;
    fumacaStr fumaca[20];
    int tempo;
    int start;
    int expAni;
    int tipoExp;
    bool apagar;
    ITexture * denso;
    ITexture * normal;
    ITexture * fraco;

    public:
    bool ativo;
    incendio(IrrlichtDevice * device, vector3df posicao, int tipo);
    void animar();
    void apagarInc();
    int getFrame();
    //int getFrame();
    void setExplosaoEm(vector3df posicao);
    void atualizaPosition(vector3df posicao);
};


class Painel
{
    public:

        Painel(ISceneManager* smgrPainel, stringw name, IVideoDriver* driver, ITimer *my_timer,IGUIEnvironment * guienvPainel);
        void atualizaVeloz (float atuaPont);
        void atualizaRPM (int atuaPont);
        void atualizaALT (vector3df mapeiaPos);
        void rotBussula(vector3df orient);
        bool mostra_warning(bool watch_out, float distancia, float altura, float raio);
        bool fim_de_jogo(vector3df posAviao, float veloz, bool bateu);
        bool fuelTemp(int tempo);

    private:
        SAppContext context;
        int gas;
        int recTempIni;
        bool primaVezTemp;
        ITimer * timer;
        bool inicia_jogo;
        bool confirmBat;
        bool ver1;
        bool voou;
        int xIni;
        IVideoDriver* mydriver;
        IGUIEnvironment * myguienv;
        stringw recName;
        f32 se_747_ter;//
        f32 ajeitaPos;
        stringw *Name;
        IMesh * marVeloz;
        IMeshSceneNode * marcVeloz;
        IMeshSceneNode * marcRPM;
        IMeshSceneNode * marcALT;
        IMeshSceneNode * bussula;
        IMeshSceneNode * modelo;
        IMeshSceneNode * localizar;
        IMeshSceneNode * aviso;
        IMeshSceneNode * mapa_1;
};





