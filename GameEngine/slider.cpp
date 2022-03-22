#include "slider.h"

#include <iostream>

slider::slider(renderer* _renderer)
{
	m_p_renderer = _renderer->GetRenderer();

	m_enabled = true;
	m_rect.w = 150; m_rect.h = 50;
	m_rect.x = 0; m_rect.y = 0;
	m_rotation = 0;

	set_images(_renderer, "ui_assets/engine/SliderBackground.png", "ui_assets/engine/SliderFill.png");

	// Store a copy of a lambda
	std::vector<std::string> handle_image_paths;
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	set_handle(_renderer, handle_image_paths, [&] { on_handle_move(); });
	m_min_value = 0;
	m_max_value = 100;

	set_value(m_max_value);
}
slider::slider(	renderer* _renderer,
				std::string _fill_image_path,
				float _min_value,
				float _max_value,
				int _x,
				int _y,
				int _width,
				int _height,
				double _rotation)
{
	m_p_renderer = _renderer->GetRenderer();

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;

	set_images(_renderer, "ui_assets/engine/SliderBackground.png", _fill_image_path);

	std::vector<std::string> handle_image_paths;
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	handle_image_paths.push_back("ui_assets/engine/SliderHandle.png");
	// Store a copy of a lambda
	set_handle(_renderer, handle_image_paths, [&] { on_handle_move(); });
	m_min_value = _min_value;
	m_max_value = _max_value;

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
	int updated = (int)((m_p_background->GetRect().w / m_max_value) * m_value);
	m_p_fill->set_size(updated, m_p_fill->GetRect().h);
	m_p_handle->set_position(m_p_fill->GetRect().x + updated - (m_p_fill->GetRect().w/5), m_p_handle->GetRect().y);
}
void slider::modify_value(float _amount)
{
	set_value(m_value + _amount);
}
void slider::set_images(renderer* _renderer, std::string _background_image_path, std::string _fill_image_path)
{
	// Clear old images
	if (m_p_background) delete m_p_background;
	if (m_p_fill) delete m_p_fill;

	m_p_background = new image(_renderer, _background_image_path, m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_rotation);
	m_p_fill = new image(_renderer, _fill_image_path, m_rect.x, m_rect.y, m_rect.w, m_rect.h, m_rotation);
	
}
void slider::set_handle(renderer* _renderer, std::vector<std::string> _handle_image_paths, std::function<void()> _callback)
{
	if (m_p_handle) delete m_p_handle;

	m_p_handle = new button(_renderer, nullptr, _callback, _handle_image_paths, m_rect.x, m_rect.y, m_rect.w/10, m_rect.h, m_rotation);
}

// Set slider value according to mouse pos compared to background bar
void slider::on_handle_move()
{
	// TODO: Get mouse pos from input system
	float mouse_x_pos = 0.0f;

	float numerator = mouse_x_pos - m_min_value;
	float denominator = m_max_value - m_min_value;
	float new_value = (float)numerator / (float)denominator;
	set_value(new_value);
}

void slider::draw()
{
	if (!m_p_background || !m_p_fill || !m_p_handle)
	{
		std::cerr << "Not got slider images.\n";
	}
	else if (m_enabled)
	{
		m_p_fill->draw();
		m_p_background->draw();
		m_p_handle->draw();
	}
}