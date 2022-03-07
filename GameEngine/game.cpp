#include "game.h"
#include "gameobject.h"

game::game()
{
	m_p_gameobject->create_player();
}

game::~game()
{
}

void game::update()
{
	m_p_gameobject->update();
}

