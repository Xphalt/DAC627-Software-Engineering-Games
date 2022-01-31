#include "slider.h"

#include <iostream>

slider::slider(	SDL_Renderer* _renderer,
				const std::string &_background_image_path,
				const std::string &_fill_image_path,
				const std::string &_handle_image_path,
				float _min_value,
				float _max_value,
				float _x,
				float _y,
				float _width,
				float _height,
				double _rotation)
{
	m_p_renderer = _renderer;

	set_images(_background_image_path, _fill_image_path, _handle_image_path);
	m_min_value = _min_value;
	m_max_value = _max_value;

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;

	set_value(m_max_value);
}
slider::~slider()
{
	if (m_p_background)
	{
		delete m_p_background;
		m_p_background = nullptr;
	}
	if (m_p_fill)
	{
		delete m_p_fill;
		m_p_fill = nullptr;
	}
	if (m_p_handle)
	{
		delete m_p_handle;
		m_p_handle = nullptr;
	}
}

void slider::set_value(float _value)
{
	m_value = _value;

	// Clamp value
	if (m_value < m_min_value) m_value = m_min_value;
	else if (m_value > m_max_value) m_value = m_max_value;

	// Update fill size and handle position
	float updated = (m_p_background->GetRect().w / m_max_value) * m_value;
	m_p_fill->set_size(updated, m_p_fill->GetRect().w);
	m_p_handle->set_position(updated, m_p_handle->GetRect().y);
}
void slider::set_images(std::string _background_image_path, std::string _fill_image_path, std::string _handle_image_path)
{
	// Clear old images
	if (m_p_background) delete m_p_background;
	if (m_p_fill) delete m_p_fill;
	if (m_p_handle) delete m_p_handle;

	m_p_background = new image(m_p_renderer, _background_image_path, m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_rotation);
	m_p_fill = new image(m_p_renderer, _fill_image_path, m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_rotation);
	m_p_handle = new image(m_p_renderer, _handle_image_path, m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_rotation);
}

void slider::draw()
{
	if (!m_p_background || !m_p_fill || !m_p_handle)
	{
		std::cerr << "Not got slider images.\n";
	}
	else if (m_enabled)
	{
		m_p_background->draw();
		m_p_fill->draw();
		m_p_handle->draw();
	}
}