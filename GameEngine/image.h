/*
* An image shows an SDL surface in a specified place, size and rotation
* Created by: Dominique
*/

#pragma once

#include <string>

#include "ui_component.h"

class image: public ui_component {
public:
	image(SDL_Renderer* _renderer, std::string _image_path, float _x, float _y, float _width, float _height, double _rotation);
	~image();
	
	void set_image(std::string _image_path);

	void draw() override;
private:
	SDL_Surface* m_p_image = nullptr;
};