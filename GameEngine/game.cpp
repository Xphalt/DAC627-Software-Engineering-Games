#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"

game::game()
{
	m_p_gameobject->create_player();
	m_p_window = new Window();
}

game::~game()
{
}

void game::update()
{
	m_p_gameobject->update();

	//m_p_window
}

