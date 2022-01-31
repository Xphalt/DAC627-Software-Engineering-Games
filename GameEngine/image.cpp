#include "image.h"

image::image(SDL_Renderer* _renderer, std::string _image_path, float _x, float _y, float _width, float _height, double _rotation)
{
	m_p_renderer = _renderer;

	set_image(_image_path);

	m_enabled = true;
	m_size.w = _width; m_size.h = _height;
	m_pos.x = _x; m_pos.y = _y;
	m_rotation = _rotation;
}
image::~image()
{
	// Clear the image
}

void image::set_image(std::string image_path)
{
	// Load in the image from the path
}

void image::draw()
{
	// Is m_image null?
	// If not then render it if the UI component is enabled
	// Else print error
}