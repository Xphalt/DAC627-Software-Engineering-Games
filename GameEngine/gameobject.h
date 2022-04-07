#pragma once
#include <string>
#include <vector>
#include <functional>

#include "ui_library.h"

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
class Patrolling;
class StateMachine;
class collider;
class minimap;

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
	gameobject();
	gameobject(renderer* _renderer, std::string fileName);
	gameobject(renderer* _renderer, std::string fileName, int rows, int columns, int duration);
	~gameobject();

	void update(bool autodisplay = true);
	void display();
	position get_position() { return m_position; };
	rotation get_rotation() { return m_rotation; };
	scale get_scale() { return m_scale; };
	float get_height() { return m_position.y + m_scale.y; }

	void set_position(float x, float y);
	void set_rotation(int x, int y);
	void set_scale(int x, int y);

	void add_translation(float x, float y);
	void add_translation(position pos_add);
	void add_col_translation(float x, float y);
	void add_rotation(int x, int y);
	void add_rotation(rotation rot_add);
	void add_scale(int x, int y);
	void add_scale(scale sc_add);

	gameobject* create_player();
	gameobject* create_enemy(gameobject* target);
	collider* create_line_collider(float startx, float starty, float endx, float endy);
	void set_collider_walls(std::vector<collider*> walls);

	button* create_button(std::function<void()> _pointer_up_callback, std::function<void()> _pointer_move_callback, std::vector<std::string> _image_paths);
	// After being created each slot of the hotbar still needs to be setup
	hotbar* create_hotbar(int _number_of_slots);
	image* create_image(std::string _image_path);
	slider* create_slider(std::string _fill_image_path, float _min_value, float _max_value);
	text* create_text(std::string _text, std::string _font_path, SDL_Color _color, int _font_size);
	collider* get_collider();
	position m_testPos{};

	// player constructor
	gameobject(renderer* _renderer, camera* _camera, animator* _animator, audioman* _audioman, input_master* _input_master);

	// enemy constructor
	gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman);

	// UI constructor
	gameobject(renderer* _renderer, animation* _animation, animator* _animator, audioman* _audioman);

	bool is_player() { return m_p_input_master != nullptr; }

private:
	// for more constructors, collision/movement components need to be implemented

	position m_position{ };
	rotation m_rotation{ };
	scale m_scale{ };

	renderer* m_p_renderer{ nullptr };
	std::vector<ui_component*> m_ui_components;
	camera* m_p_camera{ nullptr };
	animation* m_p_animation{ nullptr };
	animator* m_p_animator{ nullptr };
	audioman* m_p_audioman{ nullptr };
	minimap* m_p_minimap{ nullptr };
	input_master* m_p_input_master{ nullptr };
	StateMachine* m_p_statemachine{ nullptr };
	Patrolling* m_p_patrolling{ nullptr };

	collider* m_p_collider{nullptr};

	Window* m_p_window{ nullptr };
};