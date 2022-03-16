#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"
#include "level.h"
#include "renderer.h"
#include "Camera.h"
#include "text.h"
#include "Timer.h"

game::game()
{
	m_p_window = new Window();
<<<<<<< Updated upstream
	SDL_Rect player{ 960, 720, 64, 64 };
	m_p_camera = new camera(player, 128 ,128, 960, 720, 2000, 1536);
=======
	//SDL_Rect player{ 960, 720, 64, 64 };
	//m_p_camera = new camera(player, 128 ,128, 960, 720, 1536, 1536);
>>>>>>> Stashed changes
	m_p_renderer = new renderer(m_p_window);
	m_p_level = new level("Sprites/Tilemaps/TestMap", m_p_renderer/*, m_p_camera*/);
	//m_p_text = new text(m_p_renderer);
}

game::~game()
{
}

void game::update()
{
	if (m_p_timer->delta_time() == 60.0f)
	{
		i += 0.1f;
		m_p_camera->update_target_pos(i, 360);
		m_p_level->update();
<<<<<<< Updated upstream
=======

		//m_p_text->draw();
		//m_p_camera->update_target_pos(400, 360);

		m_p_timer->update_timer();
>>>>>>> Stashed changes
	}
}

