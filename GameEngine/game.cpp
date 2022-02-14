#include "game.h"
#include "gameobject.h"

game::game()
{
	m_p_gameobject = new gameobject();
	// Tiago = smelly
}

game::~game()
{
}

void game::update()
{
	m_p_gameobject->update();
}