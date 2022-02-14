#pragma once
#include <SDL.h>


class vector_movement
{
private:

	SDL_Point m_movementVector{ 0, 0 };
	float m_maxVelocity;
	float m_acceleration;
	float m_mass;


public:

	vector_movement(float maxSpeed, float acceleration, float mass);
	~vector_movement();
	void Move(float direction_x, float direction_y);
	void update(const float deltaTime);
	SDL_Point GetMovementVector();

};

