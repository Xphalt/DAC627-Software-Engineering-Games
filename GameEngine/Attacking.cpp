#include "Attacking.h"

void Attacking::Enter(gameobject* _Agent)
{
	m_destination = m_target.get_position();
	//pathfind a route to the destination
}

void Attacking::Execute(gameobject* _Agent)
{
	if (m_destination.x > _Agent->get_position().x)
	{

	}
	else if (m_destination.x < _Agent->get_position().x)
	{

	}

	if (m_destination.y > _Agent->get_position().y)
	{

	}
	else if (m_destination.y < _Agent->get_position().y)
	{

	}


	//move towards the player, executing necessary combat functions
	//if player is close enough (within a certain range), attack in the set way based on class
}

void Attacking::Exit(gameobject* _Agent)
{
	//pause briefly, return to patrolling
}

//need: method of pathfinding route 