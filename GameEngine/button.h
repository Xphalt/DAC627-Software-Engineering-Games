/*
* A button is an image that can have a normal, hover or pressed state
* Created by: Dominique
*/


#pragma once

#include "image.h"
#include <functional>
#include <vector>

enum BUTTON_STATE { NORMAL, HOVERED, PRESSED };

class button : public image {
public:
	button(
		SDL_Renderer* _renderer, 
		std::function<void()> _pointer_up_callback, 
		std::function<void()> _pointer_move_callback, 
		std::vector<const std::string&> _image_paths, 
		int _x,
		int _y,
		int _width,
		int _height,
		double _rotation);
	~button();

	void modify_interact_rect(int _x, int _y, int _w, int _h);

	void on_pointer_enter();
	void on_pointer_exit();

	void on_pointer_down();
	void on_pointer_move();
	void on_pointer_up();
private:
	SDL_Rect m_interact_rect;

	// Corresponds to BUTTON_STATE enum
	std::vector<const std::string&> m_image_paths;

	// Use std::function and lambdas for callbacks (see slider constructor for an example)
	std::function<void()> m_pointer_up_callback;
	std::function<void()> m_pointer_move_callback;

	bool m_pressed;
	bool m_hovered;
};