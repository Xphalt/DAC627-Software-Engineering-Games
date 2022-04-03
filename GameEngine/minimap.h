#pragma once
#include "image.h"
class minimap : public image
{
public:
	minimap(renderer* _renderer);
	minimap(renderer* _renderer, std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path,
		int _x, int _y, int _width, int _height, int _map_width, int _map_height, double _rotation);
	~minimap();

	void set_image(std::string _minimapFrame_path, std::string _playerIcon_path, std::string _minimapImage_path);

	void draw() override;
private:
	SDL_Texture* m_p_minimapFrame = nullptr;
	SDL_Texture* m_p_playerIcon = nullptr;
	SDL_Texture* m_p_minimapImage = nullptr;
	SDL_Texture* m_p_minimapImageCropped = nullptr;

	SDL_Rect m_minimapImageRect;

	SDL_Surface* crop_surface(SDL_Surface* _minimap_image, int x, int y, int width, int height);
	SDL_Texture* getAreaTexture(SDL_Rect rect, SDL_Renderer* renderer, SDL_Texture* source);
};

