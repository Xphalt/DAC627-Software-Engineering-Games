#include "vector_movement.h"

vector_movement::vector_movement(float maxSpeed, float acceleration, float mass)
{
	m_maxVelocity = maxSpeed;
	m_acceleration = acceleration;
	m_mass = mass;
}


vector_movement::~vector_movement()
{
}

void vector_movement::Move(float direction_x, float direction_y)
{
	//accelerate in each direction
	m_movementVector.x += m_acceleration * direction_x;
	m_movementVector.y += m_acceleration * direction_y;
}


void vector_movement::update(const float deltaTime)
{
	//check if max velocity has been reched and applys friction
	if (m_movementVector.x > 0.0f)
	{
		// max velocity check in positive x
		if (m_movementVector.x > m_maxVelocity)
			m_movementVector.x = m_maxVelocity;

		//deceleration in positive x
		m_movementVector.x -= m_mass;
		if (m_movementVector.x < 0.0f)
			m_movementVector.x = 0.0f;
	}
	else if (m_movementVector.x < 0.0f)
	{
		// max velocity check in negative x
		if (m_movementVector.x < -m_maxVelocity)
			m_movementVector.x = -m_maxVelocity;

		//deceleration in negative x
		m_movementVector.x += m_mass;
		if (m_movementVector.x > 0.0f)
			m_movementVector.x = 0.0f;
	}

	if (m_movementVector.y > 0.0f)
	{
		// max velocity check in positive y
		if (m_movementVector.y > m_maxVelocity)
			m_movementVector.y = m_maxVelocity;

		//deceleration in positive y
		m_movementVector.y -= m_mass;
		if (m_movementVector.y < 0.0f)
			m_movementVector.y = 0.0f;
	}
	else if (m_movementVector.y < 0.0f)
	{
		// max velocity check in negative y
		if (m_movementVector.y < -m_maxVelocity)
			m_movementVector.y = -m_maxVelocity;

		//deceleration in negative y
		m_movementVector.y += m_mass;
		if (m_movementVector.y > 0.0f)
			m_movementVector.y = 0.0f;
	}

	//xpos = movementVector * deltaTime;
	//ypos = movementVector * deltaTime;
}

SDL_Point vector_movement::GetMovementVector()
{
	return m_movementVector;
}