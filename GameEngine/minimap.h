#pragma once
#include "image.h"
class minimap : public image
{
public:
	minimap(renderer* _renderer);
	minimap(renderer* _renderer, std::string _image_path, int _x, int _y, int _width, int _height, double _rotation);
	~minimap();

	void set_image(std::string _image_path);

	void draw() override;
};

