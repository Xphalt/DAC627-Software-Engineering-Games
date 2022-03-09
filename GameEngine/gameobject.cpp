#include "gameobject.h"
#include "renderer.h"
#include "image.h"
#include "ui_component.h"
#include "camera.h"
#include "animation.h"
#include "animator.h"
#include "audioman.h"
#include "input_master.h"

gameobject::gameobject(renderer* _renderer, image* _image, camera* _camera, animation* _animation, animator* _animator, audioman* _audioman, input_master* _input_master)
	: m_p_renderer{_renderer}, m_p_image{_image}, m_p_camera{_camera}, m_p_animation{_animation}, m_p_animator{_animator}, m_p_audioman{_audioman}, m_p_input_master{_input_master}
{
}

gameobject::gameobject(renderer* _renderer, image* _image, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_image{ _image }, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
{
}

gameobject::gameobject(renderer* _renderer, ui_component* _ui_component, animation* _animation, animator* _animator, audioman* _audioman)
	: m_p_renderer{ _renderer }, m_p_ui_component{_ui_component}, m_p_animation{ _animation }, m_p_animator{ _animator }, m_p_audioman{ _audioman }
{
}

gameobject::gameobject()
{
}

gameobject::~gameobject()
{
}

void gameobject::update()
{
	if (m_p_renderer != nullptr) { m_p_renderer->Update(); }
	if (m_p_image != nullptr) { m_p_image->draw(); }
	if (m_p_ui_component != nullptr) { m_p_ui_component->draw(); }
	if (m_p_camera != nullptr) { m_p_camera->update_target_pos(m_position.x, m_position.y); }
	//if (m_p_animation != nullptr) { m_p_animation->draw(); }
	//if (m_p_animator != nullptr) { m_p_animator->play(); }
	//if (m_p_audioman != nullptr) { m_p_audioman->; }
	if (m_p_input_master != nullptr) { m_p_input_master->Update(); }
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
	return nullptr;
}