#include "Physics.h"

Physics::Physics(float maxSpeed, float acceleration, float mass)
{
	m_maxVelocity = maxSpeed;
	m_acceleration = acceleration;
	m_mass = mass;
}


Physics::~Physics()
{
}


//pass in a direction - positive/negative x, positive/negative z (e.g. 1 or -1 or what ever value works best)
void Physics::Move(float direction_x, float direction_z)
{
	//accelerate in each direction
	m_movementVector.x += m_acceleration * direction_x;
	m_movementVector.z += m_acceleration * direction_z;
}


void Physics::update(const float deltaTime)
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

	if (m_movementVector.z > 0.0f)
	{
		// max velocity check in positive y
		if (m_movementVector.z > m_maxVelocity)
			m_movementVector.z = m_maxVelocity;

		//deceleration in positive y
		m_movementVector.z -= m_mass;
		if (m_movementVector.z < 0.0f)
			m_movementVector.z = 0.0f;
	}
	else if (m_movementVector.z < 0.0f)
	{
		// max velocity check in negative y
		if (m_movementVector.z < -m_maxVelocity)
			m_movementVector.z = -m_maxVelocity;

		//deceleration in negative y
		m_movementVector.z += m_mass;
		if (m_movementVector.z > 0.0f)
			m_movementVector.z = 0.0f;
	}

	m_position.x = m_movementVector.x * deltaTime;
	m_position.z = m_movementVector.z * deltaTime;
}


