/*
* The hotbar has a background and will instantiate however many slots are required as buttons that can then be setup with callbacks individually
* Created by: Dominique
*/

#pragma once

#include "button.h"

class hotbar : public ui_component {
public:
	// After being instantiated slots need to be given image paths and callbacks using setup_slot to have functionality
	hotbar(renderer* _renderer);
	hotbar(renderer* _renderer,
		int _number_of_slots,
		int _x,
		int _y,
		int _width,
		int _height,
		double _rotation);
	~hotbar();

	void setup_slot(int _index, std::function<void()> _pointer_up_callback, std::vector<std::string> _image_paths);

	void draw() override;
private:
	std::vector<image*> m_p_backgrounds;
	int m_number_of_slots;
	std::vector<button*> m_slots;
};