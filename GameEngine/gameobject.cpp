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
#include "collider.h"

gameobject::gameobject(renderer* _renderer, camera* _camera, animator* _animator, audioman* _audioman, input_master* _input_master)
	: m_p_renderer{ _renderer }, m_p_camera{ _camera }, m_p_animator{ _animator }, m_p_audioman{ _audioman }, m_p_input_master{ _input_master }
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
	m_scale.x = 1;
	m_scale.y = 1;

	m_p_animator = new animator();
	m_p_animator->add_animation(_renderer, fileName, "Default");
	m_p_animator->set_animation("Default");
}

gameobject::gameobject(renderer* _renderer, std::string fileName, int rows, int columns, int duration)
	: m_p_renderer{ _renderer }
{
	m_scale.x = 1;
	m_scale.y = 1;

	m_p_animator = new animator();
	m_p_animator->add_animation(_renderer, fileName, "Default", rows, columns, duration);
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

void gameobject::update(bool autodisplay)
{ 
	if (m_p_input_master != nullptr)
	{
		m_p_animator->set_animation("Player_Idle");
		if (m_p_input_master->key_pressed(ActionKeys::UP))
		{
			add_col_translation(0, -10);
			m_p_animator->set_animation("Player_Run");
		}
		if (m_p_input_master->key_pressed(ActionKeys::DOWN))
		{
			add_col_translation(0, 10);
			m_p_animator->set_animation("Player_Run");
		}
		if (m_p_input_master->key_pressed(ActionKeys::LEFT))
		{
			add_col_translation(-10, 0);
			m_p_animator->set_animation("Player_Run");
			flipStatus = FLIP::HORIZONTAL;
		}
		if (m_p_input_master->key_pressed(ActionKeys::RIGHT))
		{
			add_col_translation(10, 0);
			m_p_animator->set_animation("Player_Run");
			flipStatus = FLIP::NONE;
		}
	}

	//if (m_p_renderer != nullptr) { m_p_renderer->Update(); }
	for (int i = 0; i < m_ui_components.size(); i++)
	{
		m_ui_components[i]->draw();
	}
	if (m_p_camera != nullptr) { m_p_camera->update_target_pos(m_position.x, m_position.y); }
	//if (m_p_animation != nullptr) { m_p_animation->draw(); }
	if (autodisplay) display(flipStatus);
	if (m_p_statemachine != nullptr) { m_p_statemachine->UpdateState(); }
	if (m_p_collider != nullptr) {m_p_collider->updateColliders(); }
	//if (m_p_audioman != nullptr) { m_p_audioman->; }
	//if (m_p_input_master != nullptr) { m_p_input_master->Update(); }
}

void gameobject::display(FLIP _flipStatus)
{
	if (m_p_animator != nullptr) { m_p_animator->play(m_testPos.x, m_testPos.y, 128 * m_scale.x, 128 * m_scale.y, 0.0, flipStatus); }
}

void gameobject::set_position(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void gameobject::set_rotation(int x, int y)
{
	m_rotation.x = x;
	m_rotation.y = y;
}

void gameobject::set_scale(float x, float y)
{
	m_scale.x = x;
	m_scale.y = y;
}

void gameobject::add_translation(float x, float y)
{
	m_position.x += x;
	m_position.y += y;
}

void gameobject::add_translation(position pos_add)
{
	m_position.x += pos_add.x;
	m_position.y += pos_add.y;
}

void gameobject::add_col_translation(float x, float y)
{
	position* newPos = new position{ x,y };
	newPos->x += m_position.x;
	newPos->y += m_position.y;
	bool validMove = m_p_collider->isMoveValid(newPos);

	if (validMove)
	{
		m_position.x += x;
		m_position.y += y;
	}
	delete newPos;
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
	m_p_collider = new collider(10, this, 5, 5);
	return nullptr;
}

gameobject* gameobject::create_enemy(gameobject* target)
{
	m_p_collider = new collider(10, this, 5, 5);
	m_p_statemachine = new StateMachine();
	m_p_patrolling = new Patrolling();
	m_p_patrolling->AddWaypoint(20, 20);
	m_p_patrolling->AddWaypoint(50, 20);
	m_p_patrolling->AddWaypoint(50, -50);
	m_p_patrolling->AddWaypoint(0, -50);
	m_p_statemachine->Init(this, target);
	m_p_statemachine->ChangeState(m_p_patrolling);
	return nullptr;
}

collider* gameobject::create_line_collider(float startx, float starty, float endx, float endy)
{
	m_p_collider = new collider(startx, starty, endx, endy, this);
	return m_p_collider;
}

void gameobject::set_collider_walls(std::vector<collider*> walls)
{
	m_p_collider->setWallLineColliderVector(walls);
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

collider* gameobject::get_collider()
{
	return m_p_collider;
}
