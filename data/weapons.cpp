#include "weapons.h"

machineGun::machineGun (f32 boreSize, u16 ammoQtd, vector3df position, IrrlichtDevice * irrDevice)
{
    ammo = ammoQtd;
    device = irrDevice;
    bore = boreSize;
    fireLifetime = 0;

    ISceneManager * smgr = device->getSceneManager();

    fireShot = smgr->addMeshSceneNode(smgr->getMesh("fx/outros/gun_fire.lwo"));
    fireShot -> setMaterialFlag(EMF_LIGHTING, false);
    fireShot -> setPosition (position);
    fireShot -> setMaterialType (EMT_TRANSPARENT_ALPHA_CHANNEL);
    fireShot -> setVisible(false);
};

void machineGun::setRange (u16 newRange)
{
    range = newRange;
}

void machineGun::setFireRate (u16 newFireRate)
{
    fireRate = newFireRate;
};

void machineGun::setParent (IMeshSceneNode * newParent)
{
    parent = newParent;
    fireShot -> setParent(parent);
};

void machineGun::flashLight (bool startLight)
{
    printf("FLASHLIGHT ADDED \n");
};

void machineGun::shot()
{
    fireShot -> setVisible(true);
}

void machineGun::evaluate()
{
    if(fireShot->isVisible())
    {
        fireLifetime ++;
        if (fireLifetime > 4)
        {
            fireLifetime = 0;
            fireShot->setVisible(false);
        }
    }
}
