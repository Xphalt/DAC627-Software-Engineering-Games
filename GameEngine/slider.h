/*
* The slider has a background, handle and fill and will adjust the size/position of these images when the value is set
* Created by: Dominique
*/

#pragma once

#include "image.h"

class slider : public ui_component {
public:
	slider(	SDL_Renderer* _renderer, 
			std::string _background_image_path,
			std::string _fill_image_path,
			std::string _handle_image_path,
			float _min_value, 
			float _max_value, 
			float _x, 
			float _y, 
			float _width, 
			float _height, 
			double _rotation);
	~slider();

	void set_value(float _value);
	void set_images(std::string _background_image_path, std::string _fill_image_path, std::string _handle_image_path);

	void draw() override;
private:
	image* m_p_background = nullptr;
	image* m_p_fill = nullptr;
	image* m_p_handle = nullptr;

	float m_min_value;
	float m_max_value;
	float m_value;
};