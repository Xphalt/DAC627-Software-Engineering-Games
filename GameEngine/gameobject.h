#pragma once

class renderer;
class image;
class ui_component;
class camera;
class animation;
class animator;
class audioman;
class input_master;

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

	gameobject* create_player();
	gameobject* create_enemy();
	gameobject* create_UI();

private:
	// player constructor
	gameobject(renderer* _renderer, image* _image, camera* _Camera, animation* _animation, animator* _animator, audioman* _audioman, input_master* _InputMaster);

	// enemy constructor
	gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman);

	// UI constructor
	gameobject(renderer* _renderer, ui_component* _ui_component, animation* _animation, animator* _animator, audioman* audioman);

	// for more constructors, collision/movement components need to be implemented

	position m_position{ };
	rotation m_rotation{ };
	scale m_scale{ };
};