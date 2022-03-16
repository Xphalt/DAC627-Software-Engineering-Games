#include "gameobject.h"
#include "renderer.h"
#include "ui_library.h"
#include "camera.h"
#include "animation.h"
#include "animator.h"
#include "audioman.h"
#include "input_master.h"
#include "Graphics\Window.h"

gameobject::gameobject(renderer* _renderer, image* _image, camera* _camera, animation* _animation, animator* _animator, audioman* _audioman, input_master* _input_master)
	: m_p_renderer{ _renderer }, m_p_camera{ _camera }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }, m_p_input_master{ _input_master }
{
}

gameobject::gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
{
}

gameobject::gameobject(renderer* _renderer, ui_component* _ui_component, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_ui_component{ _ui_component }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
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
}

void gameobject::update()
{
	//if (m_p_renderer != nullptr) { m_p_renderer->Update(); }
	//if (m_p_ui_component != nullptr) { m_p_ui_component->draw(); }
	//if (m_p_camera != nullptr) { m_p_camera->update_target_pos(m_position.x, m_position.y); }
	//if (m_p_animation != nullptr) { m_p_animation->draw(); }
	if (m_p_animator != nullptr) { m_p_animator->play(m_testPos.x, m_testPos.y, 128, 128, 0.0, FLIP::NONE); }
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

gameobject* gameobject::create_player()
{
	return nullptr;
}

gameobject* gameobject::create_enemy()
{
	return nullptr;
}

gameobject* gameobject::create_UI()
{
	m_p_ui_component = new button(m_p_renderer);

	return nullptr;
}