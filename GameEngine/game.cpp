#include "game.h"
#include "gameobject.h"

game::game()
{
	m_p_gameobject = new gameobject();
}

game::~game()
{
}

void game::update()
{
	m_p_gameobject->update();
}

