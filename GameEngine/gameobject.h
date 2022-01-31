#pragma once
#include <memory>

class input_component;
class output_component;
class logic_component;

using namespace std;

	struct position {
		float x{ 0 };
		float y{ 0 };
	};

	struct rotation
	{
		float x{ 0 };
		float y{ 0 };
	};

	struct scale
	{
		float x{ 0 };
		float y{ 0 };
	};

class gameobject {
public:
	gameobject(shared_ptr<input_component>& _input, shared_ptr<output_component>& _output, shared_ptr<logic_component>& _logic);
	~gameobject();

	void update();
	position get_position() { return m_position; }
	rotation get_rotation() { return m_rotation; }
	scale get_scale() { return m_scale; }

	void set_position(float _x, float _y);
	void set_rotation(float _x, float _y);
	void set_scale(float _x, float _y);

private:
	shared_ptr<input_component> m_p_input_component{ make_shared<input_component>() };
	shared_ptr<output_component> m_p_output_component{ make_shared<output_component>() };
	shared_ptr<logic_component> m_p_logic_component{ make_shared<logic_component>() };

	position m_position{ NULL };
	rotation m_rotation{ NULL };
	scale m_scale{ NULL };

	//TODO
	//collider
	//texture
	//physics?
};