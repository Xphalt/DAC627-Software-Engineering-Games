#pragma once

class gameobject;
class level;
class renderer;
class camera;
class text;
class Timer;
class input_master;

class Window;

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
	Window* m_p_window{ nullptr };
	level* m_p_level{ nullptr };
	renderer* m_p_renderer{ nullptr }; 
	text* m_p_text{ nullptr };
	Timer* m_p_timer{ nullptr };
	input_master* m_p_input{ nullptr };
};