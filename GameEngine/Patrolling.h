#pragma once
#include "StateMachine.h"
#include <vector>
#include <algorithm>

class Patrolling : public State
{
public:
	void Enter(gameobject* _Agent);
	void Execute(gameobject* _Agent);
	void Exit(gameobject* _Agent);
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
