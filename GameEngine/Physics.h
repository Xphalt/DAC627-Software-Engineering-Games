#pragma once
#include <SDL.h>

struct Position
{
	float x;
	float y;
	float z;
};

struct MovementVector
{
	float x;
	float z;
};

class Physics
{

private:

	MovementVector m_movementVector;
	float m_maxVelocity;
	float m_acceleration;
	float m_mass;


public:

	Physics(float maxSpeed, float acceleration, float mass);
	~Physics();
	void Move(float direction_x, float direction_z);
	void update(const float deltaTime);

	Position m_position;

};

