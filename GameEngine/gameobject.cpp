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

gameobject::gameobject(renderer* _renderer, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
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

void gameobject::create_button()
{
	m_ui_components.push_back(new button(m_p_renderer));
}
void gameobject::create_hotbar()
{
	m_ui_components.push_back(new hotbar(m_p_renderer));
}
void gameobject::create_image()
{
	m_ui_components.push_back(new image(m_p_renderer));
}
void gameobject::create_slider()
{
	m_ui_components.push_back(new slider(m_p_renderer));
}
void gameobject::create_text()
{
	m_ui_components.push_back(new text(m_p_renderer));
}