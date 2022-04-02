/*
* An image shows an SDL surface in a specified place, size and rotation
* Created by: Dominique
*/

#pragma once

#include "ui_component.h"

#include <string>

class image: public ui_component {
public:
	image() = default;

	image(renderer* _renderer);
	image(renderer* _renderer, std::string _image_path, int _x, int _y, int _width, int _height, double _rotation);
	~image();
	
	void set_image(std::string _image_path);

	void draw() override;
protected:
	SDL_Texture* m_p_image = nullptr;
};