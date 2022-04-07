#pragma once
#include <cmath>

class Patrolling;
class gameobject;
class StateMachine;

using namespace std;

class State
{
public:
	void InitState(gameobject* _Agent, gameobject* target, StateMachine* parentMachine);
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
protected:
	gameobject* m_p_agent;
	gameobject* m_p_target;
	StateMachine* m_p_parentMachine;
};

class StateMachine
{
public:	
	void SetStartState(State* _startState);
	State* GetActiveState();
	void ChangeState(State* _newState);
	void UpdateState();
	void Init(gameobject* newAgent, gameobject* newTarget);

private:
	gameobject* m_agent;
	gameobject* m_p_target;
	State* currentState;
};