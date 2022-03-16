#pragma once

class renderer;
class image;
class ui_component;
class camera;
class animation;
class animator;
class audioman;
class input_master;
class Window;
class tilemap;

	struct position
	{
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
	gameobject(renderer* _renderer);
	~gameobject();

	void update();
	position get_position() { return m_position; }
	rotation get_rotation() { return m_rotation; }
	scale get_scale() { return m_scale; }

	void set_position(int x, int y);
	void set_rotation(int x, int y);
	void set_scale(int x, int y);

	gameobject* create_player();
	gameobject* create_enemy();
	gameobject* create_UI();

private:
	// player constructor
	gameobject(renderer* _renderer, image* _image, camera* _camera, animation* _animation, animator* _animator, audioman* _audioman, input_master* _input_master);

	// enemy constructor
	gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman);

	// UI constructor
	gameobject(renderer* _renderer, ui_component* _ui_component, animation* _animation, animator* _animator, audioman* _audioman);

	// for more constructors, collision/movement components need to be implemented

	position m_position{ };
	rotation m_rotation{ };
	scale m_scale{ };

	renderer* m_p_renderer{ nullptr };
	image* m_p_image{ nullptr };
	ui_component* m_p_ui_component{ nullptr };
	camera* m_p_camera{ nullptr };
	animation* m_p_animation{ nullptr };
	animator* m_p_animator{ nullptr };
	audioman* m_p_audioman{ nullptr };
	input_master* m_p_input_master{ nullptr };

	Window* m_p_window{ nullptr };
};