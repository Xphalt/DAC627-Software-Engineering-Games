/*
* Shows text at a specified position, size and rotation using the font, color and font size provided
* Created by: Dominique
*/

#pragma once

#include "ui_component.h"

#include <string>

class text : public ui_component {
public:
	text(SDL_Renderer* _renderer, const std::string &_font_path, SDL_Color _color, int _font_size, float _x, float _y, float _width, float _height, double _rotation);
	~text();

	void set_text(std::string _text);
	void set_font(std::string _font_path);

	void draw() override;
private:
	SDL_Texture* m_p_font;
	SDL_Color m_color;

	std::string m_font_path;
	std::string m_text;

	int m_font_size;
};