#pragma once

class input_component;
class output_component;
class logic_component;

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
	gameobject();
	~gameobject();

	void update();
	position get_position() { return m_position; }
	rotation get_rotation() { return m_rotation; }
	scale get_scale() { return m_scale; }

	void set_position(float _x, float _y);
	void set_rotation(float _x, float _y);
	void set_scale(float _x, float _y);

private:
	input_component* m_p_input_component{ nullptr };
	output_component* m_p_output_component{ nullptr };
	logic_component* m_p_logic_component{ nullptr };

	position m_position{ };
	rotation m_rotation{ };
	scale m_scale{ };

	//TODO
	//collider
	//texture
	//physics?
};