#pragma once
#include "StateMachine.h"
#include "gameobject.h"


class Attacking : public State
{
public:
	void Enter() override;
	void Execute() override;
	void Exit() override;

private:

	int moveSpeed = 1;
};