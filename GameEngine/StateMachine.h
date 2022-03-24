#pragma once
#include <cmath>

class Patrolling;
class gameobject;

using namespace std;

class State
{
public:
	void InitState(gameobject* _Agent);
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
protected:
	gameobject* m_p_agent;
};

class StateMachine
{
public:	
	void SetStartState(State* _startState);
	State* GetActiveState();
	void ChangeState(State* _newState);
	void UpdateState();
	void Init(gameobject* newAgent);

private:
	gameobject* m_agent;
	State* currentState;
};