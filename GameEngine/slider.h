/*
* The slider has a background, handle and fill and will adjust the size/position of these images when the value is set
* Created by: Dominique
*/

#pragma once

#include "button.h"

class slider : public ui_component {
public:
	slider(	renderer _renderer, 
			std::string _background_image_path,
			std::string _fill_image_path,
			// Paths correspond to BUTTON_STATE enum (button.h)
			std::vector<std::string> _handle_image_paths,
			float _min_value, 
			float _max_value, 
			int _x, 
			int _y, 
			int _width, 
			int _height, 
			double _rotation);
	~slider();

	void set_value(float _value);
	void modify_value(float _value);
	void set_images(renderer _renderer, std::string _background_image_path, std::string _fill_image_path);
	void set_handle(renderer _renderer, std::vector<std::string> _handle_image_paths, std::function<void()> _callback);

	void on_handle_move();

	void draw() override;
private:
	image* m_p_background = nullptr;
	image* m_p_fill = nullptr;
	button* m_p_handle = nullptr;

	float m_min_value;
	float m_max_value;
	float m_value;
};