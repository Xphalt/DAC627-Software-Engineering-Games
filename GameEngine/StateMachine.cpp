#include "StateMachine.h"

void State::Enter(gameobject* _Agent)
{
}

void State::Execute(gameobject* _Agent)
{

}

void State::Exit(gameobject* _Agent)
{
}

void StateMachine::SetStartState(State _startState)
{
	_startState.Enter(m_agent);
	currentState = _startState;
}

State StateMachine::GetActiveState()
{
	return currentState;
}

void StateMachine::ChangeState(State _newState)
{
	currentState.Exit(m_agent);

	currentState = _newState;

	currentState.Enter(m_agent);
}
