/*
* The slider has a background, handle and fill and will adjust the size/position of these images when the value is set
* Created by: Dominique
*/

#pragma once

#include "button.h"

class slider : public ui_component {
public:
	slider(renderer* _renderer);
	slider(	renderer* _renderer, 
			std::string _fill_image_path,
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
	void set_images(renderer* _renderer, std::string _background_image_path, std::string _fill_image_path);
	void set_handle(renderer* _renderer, std::vector<std::string> _handle_image_paths, std::function<void()> _callback);

	void on_handle_move();

	void enable_handle(bool enable) { m_p_handle->set_enabled(enable); }

	void draw() override;
private:
	const float handle_size_multiplier = 1.2f;
	const float handle_width_multiplier = 0.1f;

	image* m_p_background = nullptr;
	image* m_p_fill = nullptr;
	button* m_p_handle = nullptr;

	float m_min_value;
	float m_max_value;
	float m_value;
};