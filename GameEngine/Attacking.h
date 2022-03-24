#pragma once
#include "StateMachine.h"


class Attacking : public State
{
public:
	void Enter() override;
	void Execute() override;
	void Exit() override;


private:
	//gameobject* m_target;
	//position m_destination;
};