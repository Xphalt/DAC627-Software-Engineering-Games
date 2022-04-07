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
	WALL_LEFT = 'W',
	WALL_RIGHT = 'w',
	DOOR_LEFT = 'D',
	DOOR_RIGHT = 'd',
	SPIKES = 'S',
	ENEMY = 'E',
	PLAYER = 'P',
};

class tilemap
{
private:
	std::vector<std::string> m_layout;
	std::vector<collider*> m_lineColliders;

	int m_block_size;

	int m_stage_width;
	int m_stage_height;

	renderer* m_p_renderer;
public:
	tilemap(int _block_size, std::string _tilaemap_path, renderer* _renderer);

	bool load_from_file(std::string _path);
	std::vector<gameobject*> return_objects();
	std::vector<collider*> get_line_colliders();

	int get_grid_height();
	int get_grid_width();

	char get_object_at(int _x, int _y);

	int get_block_size();

	int get_stage_width();
	int get_stage_height();

	int get_last_tile_pos_right();
	int get_last_tile_pos_down();
	int get_last_tile_pos_left();
	int get_last_tile_pos_top();

	int get_row(int _x);
	int get_column(int _y);
};

