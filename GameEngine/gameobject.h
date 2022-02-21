#pragma once

#include "Renderer.h"
#include "image.h"
#include "ui_component.h"
#include "Camera.h"
#include "animation.h"
#include "animator.h"
#include "audioman.h"
#include "InputMaster.h"


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
	~gameobject();

	void update();
	position get_position() { return m_position; }
	rotation get_rotation() { return m_rotation; }
	scale get_scale() { return m_scale; }

	void set_position(float _x, float _y);
	void set_rotation(float _x, float _y);
	void set_scale(float _x, float _y);

	gameobject* create_player();
	gameobject* create_enemy();
	gameobject* create_UI();

private:
	// player constructor
	gameobject(Renderer* _renderer, image* _image, Camera* _Camera, animation* _animation, animator* _animator, audioman* _audioman, InputMaster* _InputMaster);

	// enemy constructor
	gameobject(Renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman);

	// UI constructor
	gameobject(Renderer* _renderer, ui_component* _ui_component, animation* _animation, animator* _animator, audioman* audioman);

	// for more constructors, collision/movement components need to be implemented


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