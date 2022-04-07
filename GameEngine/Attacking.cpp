#include "Attacking.h"
#include <iostream>

void Attacking::Enter()
{
	//m_destination = m_target.get_position();
	//pathfind a route to the destination
}

void Attacking::Execute()
{
	//move towards the player, executing necessary combat functions
	//if player is close enough (within a certain range), attack in the set way based on class

	float diffx = m_p_target->get_position().x - m_p_agent->get_position().x;
	float diffy = m_p_target->get_position().y - m_p_agent->get_position().y;

	float mag = (diffx * diffx) + (diffy * diffy);
	mag = sqrt(mag);

	diffx /= mag;
	diffy /= mag;

	m_p_agent->add_translation(diffx, diffy);
}

void Attacking::Exit()
{
	//pause briefly, return to patrolling
}

//need: player position, method of pathfinding route 