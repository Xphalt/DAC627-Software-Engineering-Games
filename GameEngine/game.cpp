#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"
#include "level.h"
#include "renderer.h"

game::game()
{
	m_p_window = new Window();
	m_p_renderer = new renderer(m_p_window);
	m_p_level = new level("Sprites/Tilemaps/TestMap", m_p_renderer);
}

game::~game()
{
}

void game::update()
{
	while (true)
	{
		m_p_level->update();
	}
}

