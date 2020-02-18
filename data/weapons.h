#include "tools.h"

class machineGun
{
    private:
        u16 fireLifetime;
        u16 ammo;
        f32 bore;
        u16 range;
        u16 fireRate;
        IrrlichtDevice * device;
        IMeshSceneNode * bullet;
        IMeshSceneNode * fireShot;
        IMeshSceneNode * parent;
        ILightSceneNode * light;

    public:
        machineGun (f32 bore, u16 ammo, vector3df position, IrrlichtDevice * device);
        void evaluate ();
        void setDisabled (bool disabled);
        void flashLight (bool light);
        void setAmmo (u16 ammo);
        void setFireRate (u16 fireRate);
        void setParent (IMeshSceneNode * parent);
        void setRange (u16 range);
        void shot();
        u16 getAmmo ();
};

