#pragma once

class level;
class Window;
class text;
class Timer;

class gameobject;
class renderer;
class camera;
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
	level* m_p_level{ nullptr };
	Window* m_p_window{ nullptr };
	text* m_p_text{ nullptr };
	Timer* m_p_timer{ nullptr };

	gameobject* m_p_gameobject{ nullptr };
	gameobject* m_p_player{ nullptr };
	renderer* m_p_renderer{ nullptr };
	camera* m_p_camera{ nullptr };

};