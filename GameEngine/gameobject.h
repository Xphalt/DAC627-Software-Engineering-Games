#pragma once
#include <memory>

class input_component;
class output_component;
class logic_component;

using namespace std;

class gameobject {
public:
	gameobject(shared_ptr<input_component>& _input, shared_ptr<output_component>& _output, shared_ptr<logic_component>& _logic);
	~gameobject();

	void update();

private:
	shared_ptr<input_component> m_p_input_component{ make_shared<input_component>() };
	shared_ptr<output_component> m_p_output_component{ make_shared<output_component>() };
	shared_ptr<logic_component> m_p_logic_component{ make_shared<logic_component>() };
};