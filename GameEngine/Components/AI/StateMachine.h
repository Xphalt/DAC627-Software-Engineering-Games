#pragma once
#include "../../gameobject.h"
#include <cmath>

using namespace std;

struct State
{
public:
	virtual void Enter(gameobject* _Agent);
	virtual void Execute(gameobject* _Agent);
	virtual void Exit(gameobject* _Agent);
protected:
};

enum States
{
	Patrolling,
	Attacking
};

class StateMachine
{
public:	
	void SetStartState(State _startState);
	State GetActiveState();
	void ChangeState(State _newState);

private:
	gameobject* m_agent;
	State currentState;
};