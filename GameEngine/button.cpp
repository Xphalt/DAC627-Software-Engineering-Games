#include "button.h"

#include <iostream>

button::button(renderer* _renderer)
{
	m_p_renderer = _renderer->GetRenderer();

	m_pointer_move_callback = nullptr;
	m_pointer_up_callback = nullptr;

	std::vector<std::string> image_paths;
	image_paths.push_back("ui_assets/engine/ButtonNormal.png");
	image_paths.push_back("ui_assets/engine/ButtonHighlighted.png");
	image_paths.push_back("ui_assets/engine/ButtonPressed.png");
	m_image_paths = image_paths;
	m_p_image = new image(_renderer, image_paths[NORMAL], 0, 0, 50, 50, 0);

	m_enabled = true;
	m_rect.w = 50; m_rect.h = 50;
	m_rect.x = 0; m_rect.y = 0;
	m_rotation = 0;
}
button::button(renderer* _renderer, std::function<void()> _pointer_up_callback, std::function<void()> _pointer_move_callback, std::vector<std::string> _image_paths, int _x, int _y, int _width, int _height, double _rotation)
{
	m_p_renderer = _renderer->GetRenderer();

	m_pointer_move_callback = _pointer_move_callback;
	m_pointer_up_callback = _pointer_up_callback;

	m_image_paths = _image_paths;
	m_p_image = new image(_renderer, _image_paths[NORMAL], _x, _y, _width, _height, _rotation);

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
button::~button()
{
	delete m_p_image;
}

void button::set_images(std::vector<std::string> _image_paths)
{
	m_image_paths = _image_paths;
	m_p_image->set_image(m_image_paths[NORMAL]);
}
void button::set_pointer_up_callback(std::function<void()> _pointer_up_callback)
{
	m_pointer_up_callback = _pointer_up_callback;
}

void button::modify_interact_rect(int _x, int _y, int _w, int _h)
{
	m_rect.x += _x;
	m_rect.y += _y;
	m_rect.w += _w;
	m_rect.h += _h;
}

void button::on_pointer_enter()
{
	m_hovered = true;

	m_p_image->set_image(m_image_paths[HOVERED]);
}
void button::on_pointer_exit()
{
	m_hovered = false;

	// Only change the texture if the button hasn't been pressed
	if (!m_pressed)
	{
		m_p_image->set_image(m_image_paths[NORMAL]);
	}
}

void button::on_pointer_down()
{
	m_pressed = true;

	m_p_image->set_image(m_image_paths[PRESSED]);
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
		m_p_image->set_image(m_image_paths[HOVERED]);
	}
	else
	{
		m_p_image->set_image(m_image_paths[PRESSED]);
	}
}

void button::set_position(int _x, int _y)
{ 
	m_rect.x = _x; m_rect.y = _y; 
	m_p_image->set_position(_x, _y);
}

void button::draw()
{
	if (!m_p_image)
	{
		std::cerr << "Not got button image.\n";
	}
	else if (m_enabled)
	{
		m_p_image->draw();
	}
}