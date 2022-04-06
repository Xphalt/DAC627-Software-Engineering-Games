#include "Patrolling.h"
#include "Attacking.h"
#include <iostream>

Patrolling::Patrolling()
{

}

Patrolling::Patrolling(vector<position> m_p_waypoints)
{
	m_waypoints = m_p_waypoints;
}

void Patrolling::Enter()
{
	//one route for now, but set up a method to change it later
	for (int i = 0; i < m_waypoints.size(); i++)
	{
		m_distances.push_back(CalculateDistance(m_p_agent->get_position(), m_waypoints[i]));
	}

	sort(m_distances.begin(), m_distances.end());

	for (int i = 0; i < m_waypoints.size(); i++)
	{
		if (m_distances[0] == CalculateDistance(m_p_agent->get_position(), m_waypoints[i]))
			m_destination = m_waypoints[i];
	}

}

void Patrolling::Execute()
{
	//change the position of the agent based on the destination, so it travels in a certain path
	//use an increment function (will be put in later)
	//iterate through the vector for each waypoint
	//if agent position is equal to the waypoint, move to next one in the vector
	m_p_agent->add_translation(1, 0);

	float diffx = m_p_agent->get_position().x - m_p_target->get_position().x;
	float diffy = m_p_agent->get_position().y - m_p_target->get_position().y;

	float mag = (diffx * diffx) + (diffy * diffy);
	mag = sqrt(mag);

	//std::cout << mag << endl;
	if (std::abs(mag < m_attackDist))
	{
		std::cout << "Should attack" << endl;
		m_p_parentMachine->ChangeState(new Attacking());
	}

}

void Patrolling::Exit()
{

}

float Patrolling::CalculateDistance(position _one, position _two)
{
	float m_delta_x = _one.x - _two.x;
	float m_delta_y = _one.y - _two.y;
	return (pow(m_delta_x, 2) + pow(m_delta_y, 2));
}

void Patrolling::AddWaypoint(position newWaypoint)
{
	m_waypoints.push_back(newWaypoint);
}

void Patrolling::AddWaypoint(int x, int y)
{
	m_destination.x = x;
	m_destination.y = y;
	m_waypoints.push_back(m_destination);
}

void Patrolling::AddWaypoint(vector<position> m_p_waypoints)
{
	for (int i = 0; i < m_p_waypoints.size(); i++)
	{
		m_waypoints.push_back(m_p_waypoints[i]);
	}
}
