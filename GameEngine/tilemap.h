#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include "gameobject.h"

class renderer;

const std::string MAP_PATH = "Levels\\";

enum ObjectTypes
{
	FLOOR = 'F',
	WALL = 'W',
	DOOR = 'D',
	SPIKES = 'S',
	ENEMY = 'E',
	PLAYER = 'P',
};

class tilemap
{
private:
	std::vector<std::string> m_layout;

	int m_block_size;

	int m_stage_width;
	int m_stage_height;

	renderer* m_p_renderer;
public:
	tilemap(int _block_size, std::string _tilaemap_path, renderer* _renderer);

	void load_from_file(std::string _path);
	std::vector<gameobject*> return_objects();

	int get_grid_height() { return m_layout.size(); }
	int get_grid_width() { return m_layout[0].length(); }
	char get_object_at(int _x, int _y) { return m_layout[_y][_x]; }
	int get_block_size() { return m_block_size; }
	int get_stage_width() { return m_stage_width; }
	int get_stage_height() { return m_stage_height; }
	int get_row(int _y) { return std::floor(_y / m_block_size); }
	int get_column(int _x) { return std::floor(_x / m_block_size); }

	int get_last_tile_pos_right();
	int get_last_tile_pos_down();
	int get_last_tile_pos_left();
	int get_last_tile_pos_top();
};