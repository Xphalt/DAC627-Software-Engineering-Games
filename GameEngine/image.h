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

	image(SDL_Renderer* _renderer, const std::string &_image_path, int _x, int _y, int _width, int _height, double _rotation);
	~image();
	
	void set_image(std::string _image_path);

	void draw() override;
private:
	SDL_Texture* m_p_image = nullptr;
};