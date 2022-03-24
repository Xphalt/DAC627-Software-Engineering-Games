#include "StateMachine.h"
#include "Patrolling.h"
#include "gameobject.h"

void State::InitState(gameobject* agent)
{
	m_p_agent = agent;
}

void State::Enter()
{
}

void State::Execute()
{

}

void State::Exit()
{
}

void StateMachine::SetStartState(State* _startState)
{
	_startState->InitState(m_agent);
	_startState->Enter();
	currentState = _startState;
}

State* StateMachine::GetActiveState()
{
	return currentState;
}

void StateMachine::ChangeState(State* _newState)
{
	if (currentState != nullptr)
	{
		currentState->Exit();
	}

	currentState = _newState;

	currentState->InitState(m_agent);

	currentState->Enter();
}

void StateMachine::UpdateState()
{
	currentState->Execute();
}

void StateMachine::Init(gameobject* newAgent)
{
	m_agent = newAgent;
}
