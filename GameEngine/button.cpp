#include "button.h"

button::button(SDL_Renderer* _renderer, std::function<void()> _pointer_up_callback, std::function<void()> _pointer_move_callback, std::vector<const std::string&> _image_paths, int _x, int _y, int _width, int _height, double _rotation)
{
	m_p_renderer = _renderer;

	m_pointer_move_callback = _pointer_move_callback;
	m_pointer_up_callback = _pointer_up_callback;

	set_image(_image_paths[NORMAL]);

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_interact_rect = m_rect;
	m_rotation = _rotation;
}
button::~button()
{
	SDL_DestroyTexture(m_p_image);
}

void button::modify_interact_rect(int _x, int _y, int _w, int _h)
{
	m_interact_rect.x += _x;
	m_interact_rect.y += _y;
	m_interact_rect.w += _w;
	m_interact_rect.h += _h;
}

void button::on_pointer_enter()
{
	m_hovered = true;

	set_image(m_image_paths[HOVERED]);
}
void button::on_pointer_exit()
{
	m_hovered = false;

	// Only change the texture if the button hasn't been pressed
	if (!m_pressed)
	{
		set_image(m_image_paths[NORMAL]);
	}
}

void button::on_pointer_down()
{
	m_pressed = true;

	set_image(m_image_paths[PRESSED]);
}
void button::on_pointer_move()
{
	if (m_pressed && m_pointer_move_callback)
	{
		m_pointer_move_callback();
	}
}
void button::on_pointer_up()
{
	if (m_hovered && m_pointer_up_callback)
	{
		m_pointer_up_callback();
	}
	m_pressed = false;

	// If the button isn't hovered then it goes to the normal state, otherwise it goes to the hovered state
	if (m_hovered)
	{
		set_image(m_image_paths[HOVERED]);
	}
	else
	{
		set_image(m_image_paths[PRESSED]);
	}
}
