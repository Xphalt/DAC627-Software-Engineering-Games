#include "hotbar.h"

#include <iostream>

hotbar::hotbar(renderer* _renderer)
{
	m_p_renderer = _renderer->GetRenderer();

	std::vector<std::string> image_paths;
	image_paths.push_back("ui_assets/engine/ButtonNormal.png");
	image_paths.push_back("ui_assets/engine/ButtonHighlighted.png");
	image_paths.push_back("ui_assets/engine/ButtonPressed.png");
	// Instantiate slots and position them one after the other
	float slot_size = (150 - 10) / 3.0;
	float background_size = slot_size + 10;
	for (int i = 0; i < 3; i++)
	{
		m_p_backgrounds.push_back(new image(_renderer, "ui_assets/engine/HotbarBackground.png", (i * background_size), 0, background_size, background_size, 0));
		m_slots.push_back(new button(_renderer, nullptr, nullptr, image_paths, 5 + (i * background_size), 5, slot_size, slot_size, 0));
	}

	m_enabled = true;
	m_rect.w = 150; m_rect.h = 50;
	m_rect.x = 0; m_rect.y = 0;
	m_rotation = 0;
}
hotbar::hotbar(renderer* _renderer,
	std::string _background_image_path,
	int _number_of_slots,
	int _x,
	int _y,
	int _width,
	int _height,
	double _rotation)
{
	m_p_renderer = _renderer->GetRenderer();

	m_number_of_slots = _number_of_slots;
	float slot_size = _width / _number_of_slots;
	float background_size = slot_size + 5;
	std::vector<std::string> image_paths;
	image_paths.push_back("ui_assets/engine/ButtonNormal.png");
	image_paths.push_back("ui_assets/engine/ButtonHighlighted.png");
	image_paths.push_back("ui_assets/engine/ButtonPressed.png");
	// Instantiate slots and position them one after the other
	for (int i = 0; i < _number_of_slots; i++)
	{
		m_p_backgrounds.push_back(new image(_renderer, _background_image_path, (i * background_size), 0, background_size, background_size, 0));
		m_slots.push_back(new button(_renderer, nullptr, nullptr, image_paths, _x + (i * background_size), _y, slot_size, slot_size, _rotation));
	}

	m_enabled = true;
	m_rect.w = _width; m_rect.h = _height;
	m_rect.x = _x; m_rect.y = _y;
	m_rotation = _rotation;
}
hotbar::~hotbar()
{
	for (int i = 0; i < m_p_backgrounds.size(); i++)
	{
		delete m_p_backgrounds[i];
		m_p_backgrounds[i] = nullptr;
	}
	for (int i = 0; i < m_slots.size(); i++)
	{
		delete m_slots[i];
		m_slots[i] = nullptr;
	}
	m_slots.clear();
}

// Can set in nullptr for callback if only images are to be changed
void hotbar::setup_slot(int _index, std::function<void()> _pointer_up_callback, std::vector<std::string> _image_paths)
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
	if (!m_p_backgrounds.size() || !m_slots.size())
	{
		std::cerr << "Not got hotbar images.\n";
	}
	else if (m_enabled)
	{
		for (int i = 0; i < m_slots.size(); i++)
		{
			m_p_backgrounds[i]->draw();
			m_slots[i]->draw();
		}
	}
}