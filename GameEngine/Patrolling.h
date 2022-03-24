#pragma once
#include <vector>
#include <algorithm>
#include "StateMachine.h"
#include "gameobject.h"

class Patrolling : public State
{
public:
	Patrolling();
	void Enter() override;
	void Execute() override;
	void Exit() override;
	float CalculateDistance(position _one, position _two);


private:
	vector<position> m_waypoints;
	vector<float> m_distances;
	gameobject m_waypoint_1;
	gameobject m_waypoint_2;
	gameobject m_waypoint_3;
	gameobject m_waypoint_4;
	position m_destination;
};
