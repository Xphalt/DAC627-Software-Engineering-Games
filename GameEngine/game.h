#pragma once
#include <memory>

class gameobject;
class input_component;
class output_component;
class logic_component;

using namespace std;

class game
{
public:
	void update();

private:
	shared_ptr<gameobject> m_p_gameobject{ make_shared<gameobject>() };
	shared_ptr<input_component> m_p_input_component{ make_shared<input_component>() };
	shared_ptr<output_component> m_p_output_component{ make_shared<output_component>() };
	shared_ptr<logic_component> m_p_logic_component{ make_shared<logic_component>() };
};