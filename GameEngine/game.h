#pragma once

class gameobject;
class level;
class renderer;
class camera;
class text;
class Timer;
class Window;
class animation;
class animator;
class audioman;
class player_input;

using namespace std;

class game
{
public:
	game();
	~game();

	void update();
	float i = 0;
private:
	gameobject* m_p_gameobject{ nullptr };
	gameobject* m_p_player{ nullptr };
	Window* m_p_window{ nullptr };
	level* m_p_level{ nullptr };
	renderer* m_p_renderer{ nullptr };
	text* m_p_text{ nullptr };
	Timer* m_p_timer{ nullptr };
	camera* m_p_camera{ nullptr };
};