#include "weapons.h"

class SEngineFighter
{
    private:
        bool stopLoad;
        bool civilian;
        u16 fuselageIndex;
        u16 enginePower;
        f32 mass;
        f32 Ixx;
        f32 Iyy;
        f32 Izz;
        IrrlichtDevice * device;
        NewtonWorld * nWorld;
        stringw planeName;
        stringw *recName;
        stringw vai;
        vector3df dirVect;
        char *pontChar;
        char recChar;
        float pontAc;


        array <bool> moveType;
        array <char> gearFunc;
        array <u16> commPart;
        array <u16> comm[12]; //13 comandos disponíveis
        array <f32> lGearHeight;
        array <stringw> pieceIndex;
        array <stringw> funcIndex;
        array <stringw> mobIndex;
        array <vector3df> weapon_pos;
        array <vector3df> mob_defPos;
        array <vector3df> mob_defRot;
        array <line3df> movVect[2];
        array <line3df> lGear;
        array <IMeshSceneNode *> gra_sPieces;
        array <IMeshSceneNode *> col_sPieces;
        array <IMeshSceneNode *> mob_pieces;
        array <NewtonCollision *> ncl_sPieces;
        array <NewtonBody *> phy_sPieces;
        array <machineGun *> guns;

        static void applyForce (const NewtonBody* body, dFloat timestep, int thread);
        static void updateScene (const NewtonBody* body, const dFloat * timestep, int thread);
        void readPlanePart(IReadFile * file);
        void readCommands(IReadFile * file);
        void addMobilePart(IReadFile * file);
        void addStaticPart(IReadFile * file);
        void readLGear(IReadFile * file);
        void readData(IReadFile * file);
        void addWeapon(IReadFile * file);
        void installWeapon(IReadFile * weap, stringw weaponName, vector3df position, IMeshSceneNode * parent, bool light);
        void buildPhysicalAirplane();
        int readPlaneName(IReadFile * file, stringw name);
        int findBlock(IReadFile * file);

        //controles
        bool engine;
        bool shot;
        f32 roll;
        f32 pitch;
        f32 yaw;
        f32 flap;
        f32 gear;
        f32 accell;
        vector3df getSpeedRot;
        bool runOnce;
        array<u16> propellers;
        bool gearDown;
        bool gearMove;

    public:
        SEngineFighter (IrrlichtDevice * IrrDevice, NewtonWorld * newtWorld, stringw name);
        ~SEngineFighter();
        void setCommand (u16 part, u16 state, u16 command);
        void startEngine (bool start);
        void accelerate (u16 acce, bool acelerando);
        void checkLanding ();
        void setGearDown();
        void setShot(bool fire);
        array <machineGun *> getGunArray ();
        bool getEngineState ();
        bool isCivilian();
        array<u16> * getCommandArray();
        vector3df getPosition();
        ///*********************************
        IMeshSceneNode * getFuselage();
        float getVeloc(stringw name);
        float  getAccell(stringw name);
        bool verifCol();
        vector3df varFim;
        vector3df varIni;
        bool explode;
        bool motorLig;
        bool acabouGasolina;

};
