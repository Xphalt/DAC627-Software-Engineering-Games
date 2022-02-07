#pragma once
#include <map>
#include <vector>
#include <string>
#include "Animation.h"
class animator
{
private:
	std::map<std::string, animation*> m_p_animations;
	std::vector<std::string> m_animation_names;
	std::string m_current_animation;

public:
	animator();
	~animator();

	void add_animation(SDL_Renderer* _renderer, std::string _filename, std::string _animation_name, int _rows = 0, int _columns = 0, int _duration = 0, bool _loop = true);
	void set_animation(std::string _animation_name);
	void play(int _x, int _y, int _width, int _height, double _rotation, FLIP _flip);
};

