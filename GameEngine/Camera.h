#pragma once 
#include <SDL.h>
#include <cmath>

class gameobject;


class camera
{
private:
	//Player position 
	SDL_Rect m_player_rect;

	//Tiles details 
	int m_tile_width, m_tile_height;
	//Map details 
	int m_map_full_width, m_map_full_height;
	int m_map_start_left, m_map_start_top;

	//Screen and camera details details
	SDL_Rect m_camera_rect;

	//Zoom 
	float m_FOV_scale_factor{ 1.0f };

	gameobject* m_target;

public:
	camera();
	camera(SDL_Rect _pRect, int _tileWidth, int _tileHeight, int _screenWidth, int _screenHeight, int _mapFullWidth, int _mapFullHeight);
	~camera() = default;

	void update_target_pos(int _pX, int _pY); 

	//Setters
	void set_target(gameobject* _t);
	void set_map_start_left(int _value);
	void set_map_start_top(int _value);
	bool set_screen_size(int _width, int _height);
	bool set_tile_size(int _width, int _height);
	bool set_map_full_size(int _width, int _height);
	

	int get_tile_drawX(int _x);
	int get_tile_drawY(int _y);
	bool can_draw_tile(gameobject* _obj);

	//Getters for rendering map
	int get_start_row();
	int get_end_row(int _numberOfTilesVertical);
	int get_start_column();
	int get_end_column(int _numberOfTilesHorizontal); 

	SDL_Rect get_player_drawing_rect();
};