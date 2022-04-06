#pragma once
#include <vector>
#include <algorithm>
#include "StateMachine.h"
#include "gameobject.h"

class Patrolling : public State
{
public:
	Patrolling();
	Patrolling(vector<position> m_p_waypoints);
	void Enter() override;
	void Execute() override;
	void Exit() override;
	float CalculateDistance(position _one, position _two);

	void AddWaypoint(position newWaypoint);
	void AddWaypoint(int x, int y);
	void AddWaypoint(vector<position> m_p_waypoints);


private:
	vector<position> m_waypoints;
	vector<float> m_distances;
	position m_destination;
};
