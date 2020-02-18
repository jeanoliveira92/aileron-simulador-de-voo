#include "physics.h"

void applyPlayerForcer (const NewtonBody* body, dFloat timestep, int thread)
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

void updatePlayerScene (const NewtonBody* body, const dFloat * timestep, int thread)
{
    printf("UPDATE ... ");
	float matrix[16];

    packPhysics * pack;
    IMeshSceneNode * node;
	pack = (packPhysics*) NewtonBodyGetUserData(body);
    node = pack->node;

	NewtonBodyGetMatrix(body, matrix);

	CMatrix4<float> mat;
	memcpy(mat.pointer(), matrix, sizeof(float) * 16);

	node->setPosition(mat.getTranslation());
	node->setRotation(mat.getRotationDegrees());
	printf(".. DONE \n");
};
