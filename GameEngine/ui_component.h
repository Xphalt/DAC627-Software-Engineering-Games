/*
* A base for UI components such as text, image and slider to enable size/position/rotation changing of those items
* Created by: Dominique
*/

#pragma once

#include <SDL.h>

class ui_component {
public:
	// Provide a default class to be overriden by children
	ui_component() = default;
	ui_component(SDL_Renderer* _renderer, float _x, float _y, float _width, float _height, double _rotation);
	~ui_component();
	
	void set_enabled(bool _enabled) { m_enabled = _enabled; }
	void set_position(float _x, float _y) { m_pos.x = _x; m_pos.y = _y; }

	// To be overriden when inherited
	virtual void draw();
protected:
	SDL_Renderer* m_p_renderer;

	SDL_Rect m_size;
	SDL_Point m_pos;

	bool m_enabled;
	double m_rotation;
};