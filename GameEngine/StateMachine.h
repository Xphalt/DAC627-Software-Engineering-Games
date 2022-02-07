#pragma once

using namespace std;

class StateMachine
{
public:
	virtual void Enter();
	virtual void Execute();
	virtual void Exit();
	void SetStartState();
	void GetActiveState();
	void ChangeState();

private:
	
};

