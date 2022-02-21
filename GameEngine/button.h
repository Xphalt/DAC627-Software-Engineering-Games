/*
* A button has an image that changes between NORMAL, HOVERED and PRESSED states and holds callbacks for being hovered and clicked
* Created by: Dominique
*/


#pragma once

#include "image.h"
#include <functional>
#include <vector>

enum BUTTON_STATE { NORMAL, HOVERED, PRESSED };

class button : public ui_component {
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
	button(SDL_Renderer* _renderer, int _x, int _y, int _width, int _height, double _rotation);
	~button();

	void set_images(std::vector<const std::string&> _image_paths);
	void set_pointer_up_callback(std::function<void()> _pointer_up_callback);

	void modify_interact_rect(int _x, int _y, int _w, int _h);

	void on_pointer_enter();
	void on_pointer_exit();

	void on_pointer_down();
	void on_pointer_move();
	void on_pointer_up();

	void draw() override;
private:
	// Corresponds to BUTTON_STATE enum
	std::vector<const std::string&> m_image_paths;

	image* m_p_image;

	// Use std::function and lambdas for callbacks (see slider constructor for an example)
	std::function<void()> m_pointer_up_callback;
	std::function<void()> m_pointer_move_callback;

	bool m_pressed;
	bool m_hovered;
};