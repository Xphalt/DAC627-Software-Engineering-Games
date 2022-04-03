#pragma once
#include "image.h"
class minimap : public image
{
public:
	minimap(renderer* _renderer);
	minimap(renderer* _renderer, std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path,
		int _x, int _y, int _width, int _height, double _rotation);
	~minimap();

	void set_image(std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path);

	void draw() override;
private:
	SDL_Texture* m_p_minimapFrame = nullptr;
	SDL_Texture* m_p_playerIcon = nullptr;
	SDL_Texture* m_p_minimapImage = nullptr;
	SDL_Texture* m_p_minimapImageCropped = nullptr;
;
};

