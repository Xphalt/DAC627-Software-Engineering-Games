#pragma once
#include "StateMachine.h"

class Attacking : public State
{
public:
	void Enter(gameobject* _Agent);
	void Execute(gameobject* _Agent);
	void Exit(gameobject* _Agent);


private:
	gameobject m_target;
	position m_destination;
};
