#include "gameobject.h"
#include "renderer.h"
#include "camera.h"
#include "animation.h"
#include "animator.h"
#include "audioman.h"
#include "input_master.h"
#include "Graphics\Window.h"
#include "Patrolling.h"
#include "StateMachine.h"
#include "minimap.h"

gameobject::gameobject(renderer* _renderer, image* _image, camera* _camera, animation* _animation, animator* _animator, audioman* _audioman, input_master* _input_master)
	: m_p_renderer{ _renderer }, m_p_camera{ _camera }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }, m_p_input_master{ _input_master }
{
}

gameobject::gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
{
}

gameobject::gameobject(renderer* _renderer, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
{
}

gameobject::gameobject()
{

}

gameobject::gameobject(renderer* _renderer, std::string fileName)
	: m_p_renderer{ _renderer }
{
	m_p_animator = new animator();
	m_p_animator->add_animation(_renderer, fileName, "Default");
	m_p_animator->set_animation("Default");
}

gameobject::~gameobject()
{
	for (int i = 0; i < m_ui_components.size(); i++)
	{
		delete m_ui_components[i];
	}
	m_ui_components.clear();
}

void gameobject::update()
{
	//if (m_p_renderer != nullptr) { m_p_renderer->Update(); }
	for (int i = 0; i < m_ui_components.size(); i++)
	{
		m_ui_components[i]->draw();
	}
	//if (m_p_camera != nullptr) { m_p_camera->update_target_pos(m_position.x, m_position.y); }
	//if (m_p_animation != nullptr) { m_p_animation->draw(); }
	if (m_p_animator != nullptr) { m_p_animator->play(m_testPos.x, m_testPos.y, 128, 128, 0.0, FLIP::NONE); }
	if (m_p_statemachine != nullptr) { m_p_statemachine->UpdateState(); }
	//if (m_p_audioman != nullptr) { m_p_audioman->; }
	//if (m_p_input_master != nullptr) { m_p_input_master->Update(); }
}

void gameobject::set_position(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void gameobject::set_rotation(int x, int y)
{
	m_rotation.x = x;
	m_rotation.y = y;
}

void gameobject::set_scale(int x, int y)
{
	m_scale.x = x;
	m_scale.y = y;
}

void gameobject::add_translation(int x, int y)
{
	m_position.x += x;
	m_position.y += y;
}

void gameobject::add_translation(position pos_add)
{
	m_position.x += pos_add.x;
	m_position.y += pos_add.y;
}

void gameobject::add_rotation(int x, int y)
{
	m_rotation.x += x;
	m_rotation.y += y;
}

void gameobject::add_rotation(rotation rot_add)
{
	m_rotation.x += rot_add.x;
	m_rotation.y += rot_add.y;
}

void gameobject::add_scale(int x, int y)
{
	m_scale.x += x;
	m_scale.y += y;
}

void gameobject::add_scale(scale sc_add)
{
	m_scale.x += sc_add.x;
	m_scale.y += sc_add.y;
}

gameobject* gameobject::create_player()
{
	return nullptr;
}

gameobject* gameobject::create_enemy()
{
	m_p_statemachine = new StateMachine();
	m_p_statemachine->Init(this);
	m_p_statemachine->ChangeState(new Patrolling());
	return nullptr;
}

button* gameobject::create_button(std::function<void()> _pointer_up_callback, std::function<void()> _pointer_move_callback, std::vector<std::string> _image_paths)
{
	button* new_button = new button(m_p_renderer, _pointer_up_callback, _pointer_move_callback, _image_paths, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	m_ui_components.push_back(new_button);
	return new_button;
}
hotbar* gameobject::create_hotbar(int _number_of_slots)
{
	hotbar* new_hotbar = new hotbar(m_p_renderer, _number_of_slots, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	m_ui_components.push_back(new_hotbar);
	return new_hotbar;
}
image* gameobject::create_image(std::string _image_path)
{
	image* new_image = new image(m_p_renderer, _image_path, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	m_ui_components.push_back(new_image);
	return new_image;
}
slider* gameobject::create_slider(std::string _fill_image_path, float _min_value, float _max_value)
{
	slider* new_slider = new slider(m_p_renderer,  _fill_image_path, _min_value, _max_value, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	m_ui_components.push_back(new_slider);
	return new_slider;
}
text* gameobject::create_text(std::string _text, std::string _font_path, SDL_Color _color, int _font_size)
{
	text* new_text = new text(m_p_renderer, _font_path, _color, _font_size, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	new_text->set_text(_text);
	m_ui_components.push_back(new_text);
	return new_text;
}

minimap* gameobject::create_minimap(std::string _image_path)
{
	minimap* new_minimap = new minimap(m_p_renderer, _image_path, m_position.x, m_position.y, m_scale.x, m_scale.y, 0);
	m_ui_components.push_back(new_minimap);
	return new_minimap;
}