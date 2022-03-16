#pragma once

class gameobject;
class level;
class renderer;
class camera;
//class input_component;
//class output_component;
//class logic_component;

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
	camera* m_p_camera{ nullptr };
};