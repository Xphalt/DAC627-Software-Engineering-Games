#include "StateMachine.h"
#include "Patrolling.h"
#include "gameobject.h"

void State::InitState(gameobject* agent, gameobject* target, StateMachine* parentMachine)
{
	m_p_agent = agent;
	m_p_target = target;
	m_p_parentMachine = parentMachine;
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
	_startState->InitState(m_agent, m_p_target, this);
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

	currentState->InitState(m_agent, m_p_target, this);

	currentState->Enter();
}

void StateMachine::UpdateState()
{
	currentState->Execute();
}

void StateMachine::Init(gameobject* newAgent, gameobject* newTarget)
{
	m_agent = newAgent;
	m_p_target = newTarget;
}
