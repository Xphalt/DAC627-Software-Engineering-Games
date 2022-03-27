#include "animator.h"

animator::animator()
{
}

animator::~animator()
{
	for (int a = 0; a < m_animation_names.size(); a++)
	{
		delete m_p_animations[m_animation_names[a]];
	}
	m_p_animations.clear();
}

void animator::add_animation(renderer* _renderer, std::string _filename, std::string _animation_name, int _rows, int _columns, int _duration, bool _loop)
{
	m_p_animations[_animation_name] = new animation(_renderer, _filename);

	if (_rows != 0 && _columns != 0)
	{
		m_p_animations[_animation_name]->set_frames(_rows, _columns, _loop);
		if (_duration != 0) m_p_animations[_animation_name]->set_frame_duration(_duration);
	}

	m_animation_names.push_back(_animation_name);
}

void animator::set_animation(std::string _animation_name)
{
	m_current_animation = _animation_name;
}

void animator::play(int _x, int _y, int _width, int _height, double _rotation, FLIP _flip)
{
	m_p_animations[m_current_animation]->draw(_x, _y, _width, _height, _rotation, _flip);
}
