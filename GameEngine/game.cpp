#include "game.h"
#include "gameobject.h"
#include "Graphics\Window.h"
#include "level.h"
#include "renderer.h"
#include "Camera.h"
#include "text.h"
#include "Timer.h"
#include "audioman.h"

game::game()
{
	m_p_window = new Window();
	SDL_Rect player{ 960, 720, 64, 64 };
	m_p_camera = new camera(player, 960, 128, 128, 720, 2000, 2000);

	m_p_renderer = new renderer(m_p_window);
	m_p_level = new level("Sprites/Tilemaps/TestMap", m_p_renderer, m_p_camera);

	m_p_timer = new Timer();

	audioman::runmusiclist(audioman::LEVELTHEME, 10, 1, 1);
}

game::~game()
{
}

void game::update()
{
	float mytime = 0.0f;
	SDL_Event events;

	bool _isRunning = true;

	while (_isRunning)
	{
		while (SDL_PollEvent(&events) != 0)
		{
			switch (events.type)
			{
			case SDL_QUIT:
				_isRunning = false;
				break;

			default:
				break;
			}
		}

		m_p_timer->update_timer();
		mytime += m_p_timer->delta_time();
		if (mytime > 1.0f / 60.0f)
		{
			mytime = 0.0f;
			i += 0.1f;
			m_p_camera->update_target_pos(0, 360);
			m_p_level->update();
		}
	}
}

