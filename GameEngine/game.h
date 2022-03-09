#pragma once

class gameobject;
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

private:
	gameobject* m_p_gameobject{ nullptr };
	Window* m_p_window{ nullptr };
};