#include "hotbar.h"

#include <iostream>

hotbar::hotbar(SDL_Renderer* _renderer,
	const std::string& _background_image_path,
	int _number_of_slots,
	int _slot_size,
	int _x,
	int _y,
	int _width,
	int _height,
	double _rotation)
{
	m_p_renderer = _renderer;

	m_p_background = new image(_renderer, _background_image_path, _x, _y, _width, _height, _rotation);

	// Instantiate slots and position them one after the other
	for (int i = 0; i < _number_of_slots; i++)
	{
		m_slots.push_back(new button(_renderer, _x + (i * _slot_size), _y, _slot_size, _slot_size, _rotation));
	}

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
hotbar::~hotbar()
{
	if (m_p_background)
	{
		delete m_p_background;
		m_p_background = nullptr;
	}
	for (int i = 0; i < m_slots.size(); i++)
	{
		delete m_slots[i];
		m_slots[i] = nullptr;
	}
	m_slots.clear();
}

// Can set in nullptr for callback if only images are to be changed
void hotbar::setup_slot(int _index, std::function<void()> _pointer_up_callback, std::vector<const std::string&> _image_paths)
{
	if (_index >= m_slots.size())
	{
		std::cerr << "Trying to setup slot at index " << _index << " when we have " << m_slots.size() << " slots.\n";
	}

	button* slot = m_slots[_index];
	if (_pointer_up_callback)
	{
		slot->set_pointer_up_callback(_pointer_up_callback);
	}
	slot->set_images(_image_paths);
}

void hotbar::draw()
{
	if (!m_p_background || !m_slots.size())
	{
		std::cerr << "Not got hotbar images.\n";
	}
	else if (m_enabled)
	{
		m_p_background->draw();
		for (int i = 0; i < m_slots.size(); i++)
		{
			m_slots[i]->draw();
		}
	}
}