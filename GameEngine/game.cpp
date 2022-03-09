#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"

game::game()
{
	m_p_window = new Window();
	m_p_gameobject = new gameobject(m_p_window);
	m_p_gameobject->create_player();
}

game::~game()
{
}

void game::update()
{
	while (true)
	{
		m_p_gameobject->update();
	}
}

