#include "Patrolling.h"

void Patrolling::Enter(gameobject* _Agent)
{
	//one route for now, but set up a method to change it later
	m_waypoints.push_back(m_waypoint_1.get_position());
	m_distances.push_back(CalculateDistance(_Agent->get_position(), m_waypoint_1.get_position()));
	m_waypoints.push_back(m_waypoint_2.get_position());
	m_distances.push_back(CalculateDistance(_Agent->get_position(), m_waypoint_2.get_position()));
	m_waypoints.push_back(m_waypoint_3.get_position());
	m_distances.push_back(CalculateDistance(_Agent->get_position(), m_waypoint_3.get_position()));
	m_waypoints.push_back(m_waypoint_4.get_position());
	m_distances.push_back(CalculateDistance(_Agent->get_position(), m_waypoint_4.get_position()));

	sort(m_distances.begin(), m_distances.end());
	if (m_distances[0] = CalculateDistance(_Agent->get_position(), m_waypoint_1.get_position()))
	{
		m_destination = m_waypoint_1.get_position();
	}
	else if (m_distances[0] = CalculateDistance(_Agent->get_position(), m_waypoint_2.get_position()))
	{
		m_destination = m_waypoint_2.get_position();
	}
	else if (m_distances[0] = CalculateDistance(_Agent->get_position(), m_waypoint_3.get_position()))
	{
		m_destination = m_waypoint_3.get_position();
	}
	else if (m_distances[0] = CalculateDistance(_Agent->get_position(), m_waypoint_4.get_position()))
	{
		m_destination = m_waypoint_4.get_position();
	}

}

void Patrolling::Execute(gameobject* _Agent)
{
	//change the position of the agent based on the destination, so it travels in a certain path
	//use an increment function (will be put in later)
	//iterate through the vector for each waypoint
	//if agent position is equal to the waypoint, move to next one in the vector
}

void Patrolling::Exit(gameobject* _Agent)
{
}

float Patrolling::CalculateDistance(position _one, position _two)
{
	float m_delta_x = _one.x - _two.x;
	float m_delta_y = _one.y - _two.y;
	return (pow(m_delta_x, 2) + pow(m_delta_y, 2));
}

//need: an increment function for game object position 