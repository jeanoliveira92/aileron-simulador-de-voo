#include "instrumentos.h"

///FUNÇÕES PARA FÍSICA (NEWTON GAME DYNAMICS)
NewtonCollision* addHullCollision (IMesh* source, IVideoDriver* driver, NewtonWorld * nWorld, dVector offset, int ID);
void updateGenericScene (const NewtonBody* body, const dFloat * timestep, int thread);
void applyGenericForce (const NewtonBody* body, dFloat timestep, int thread);
dVector calculateTorqueAt(dVector force, dVector position, const NewtonBody * body);
dVector conVecI2N (vector3df vector);
vector3df conVecN2I (dVector vector);
vector3df readVec(IReadFile * file);
f32 readFloat(IReadFile * file);
void printStringw(stringw string);
