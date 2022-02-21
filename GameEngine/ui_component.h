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
	ui_component(SDL_Renderer* _renderer, int _x, int _y, int _width, int _height, double _rotation);
	~ui_component();
	
	void set_enabled(bool _enabled) { m_enabled = _enabled; }
	void set_position(int _x, int _y) { m_rect.x = _x; m_rect.y = _y; }
	void set_size(int _w, int _h) { m_rect.w = _w; m_rect.h = _h; }
	void set_rotation(double _rotation) { m_rotation = _rotation; }

	SDL_Rect GetRect() { return m_rect; }

	// To be overriden when inherited
	virtual void draw();
protected:
	SDL_Renderer* m_p_renderer;

	SDL_Rect m_rect;

	bool m_enabled;
	double m_rotation;
};