#include "Attacking.h"

void Attacking::Enter(gameobject* _Agent)
{
	m_destination = m_target.get_position();
	//pathfind a route to the destination
}

void Attacking::Execute(gameobject* _Agent)
{
	//move towards the player, executing necessary combat functions
	//if player is close enough (within a certain range), attack in the set way based on class
}

void Attacking::Exit(gameobject* _Agent)
{
	//pause briefly, return to patrolling
}

//need: player position, method of pathfinding route 