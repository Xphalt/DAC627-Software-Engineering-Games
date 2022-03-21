#include "Camera.h"
#include "gameobject.h"


camera::camera()
	:
	m_player_rect{ SDL_Rect() },
	m_tile_width{ 32 },
	m_tile_height{ 32 },
	m_map_full_width{ 32 },
	m_map_full_height{ 32 },
	m_camera_rect({ 0,0,1280,720 })
{ }

camera::camera(SDL_Rect _pRect, int _tileWidth, int _tileHeight, int _screenWidth, int _screenHeight, int _mapFullWidth, int _mapFullHeight)
	:
	m_player_rect{ _pRect },
	m_tile_width{ _tileWidth },
	m_tile_height{ _tileHeight },
	m_camera_rect({ 0,0,_screenWidth,_screenHeight }),
	m_map_full_width{ _mapFullWidth },
	m_map_full_height{ _mapFullHeight }
{
	//Calculate plyer position
	m_camera_rect.x = (m_player_rect.x + (m_player_rect.h / 2)) - m_camera_rect.w / 2;
	m_camera_rect.y = (m_player_rect.y + (m_player_rect.h / 2)) - m_camera_rect.h / 2;

	set_map_full_size(m_map_full_width, m_map_full_height);
}

void camera::update_target_pos(int _pX, int _pY)
{
	//Set player in the middle 
	m_camera_rect.x = (_pX + (m_player_rect.w / 2)) - m_camera_rect.w / 2;
	m_camera_rect.y = (_pY + (m_player_rect.h / 2)) - m_camera_rect.h / 2;

	//Avoid player in the middle when at the edge of the map
	if (m_camera_rect.x < 0)
		m_camera_rect.x = 0;
	if (m_camera_rect.y < 0)
		m_camera_rect.y = 0;

	//same as up, but checks the end of the map
	if (m_camera_rect.x > m_map_full_width - m_camera_rect.w)
		m_camera_rect.x = m_map_full_width - m_camera_rect.w;
	if (m_camera_rect.y > m_map_full_height - m_camera_rect.h)
		m_camera_rect.y = m_map_full_height - m_camera_rect.h;
}

bool camera::set_screen_size(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	m_camera_rect.w = _width;
	m_camera_rect.h = _height;

	return true;
}

bool camera::set_tile_size(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	m_tile_width = _width;
	m_tile_height = _height;

	return true;
}

bool camera::set_map_full_size(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	m_map_full_width = _width;
	m_map_full_height = _height;

	return true;
}

int camera::get_tile_drawX(int _x)
{
	return _x - m_camera_rect.x;
}

int camera::get_tile_drawY(int _y)
{
	return _y - m_camera_rect.y;
}

bool camera::can_draw_tile(gameobject* _obj)
{
	return  std::abs(_obj->get_position().x - m_camera_rect.x) < (m_camera_rect.w / 2) && std::abs(_obj->get_position().y - m_camera_rect.y) < (m_camera_rect.h / 2);
}

int camera::get_start_row()
{
	return m_camera_rect.y / (m_tile_height * m_FOV_scale_factor); 
}

int camera::get_end_row(int _numberOfTilesVertical)
{
	int endRow = (m_camera_rect.y + m_camera_rect.h) / (m_tile_height * m_FOV_scale_factor);
	if (endRow > _numberOfTilesVertical) //check boundaries
		endRow = _numberOfTilesVertical;

	return endRow;
}

int camera::get_start_column()
{
	return m_camera_rect.x / (m_tile_width * m_FOV_scale_factor);
}

int camera::get_end_column(int _numberOfTilesHorizontal)
{
	int endColumn = (m_camera_rect.x + m_camera_rect.w) / (m_tile_width * m_FOV_scale_factor);
	if (endColumn > _numberOfTilesHorizontal) //check boundaries
		endColumn = _numberOfTilesHorizontal;

	return endColumn;
}