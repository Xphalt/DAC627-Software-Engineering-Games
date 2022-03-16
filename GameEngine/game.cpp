#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"
#include "level.h"
#include "renderer.h"
#include "Camera.h"

game::game()
{
	m_p_window = new Window();
	SDL_Rect player{ 960, 720, 64, 64 };
	m_p_camera = new camera(player, 128 ,128, 960, 720, 2000, 1536);
	m_p_renderer = new renderer(m_p_window);
	m_p_level = new level("Sprites/Tilemaps/TestMap", m_p_renderer, m_p_camera);
}

game::~game()
{
}

void game::update()
{
	while (true)
	{
		i += 0.1f;
		m_p_camera->update_target_pos(i, 360);
		m_p_level->update();
	}
}

