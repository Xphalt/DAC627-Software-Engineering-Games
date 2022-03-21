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
	WALL_L = 'W',
	WALL_R = 'M',
	DOORWAY_L = 'D',
	DOORWAY_R = 'B',
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

	const std::string m_floor_tile_path			{ "Sprites/Isometric/floor.png" };
	const std::string m_wall_left_tile_path		{ "Sprites/Isometric/wallLeft.png" };
	const std::string m_wall_right_tile_path	{ "Sprites/Isometric/wallRight.png" };
	const std::string m_doorway_left_tile_path  { "Sprites/Isometric/doorwayLeft.png" };
	const std::string m_doorway_right_tile_path { "Sprites/Isometric/doorwayRight.png" };

	renderer* m_p_renderer;

public:
	tilemap(int _block_size, std::string _tilaemap_path, renderer* _renderer);

	void load_from_file(std::string _path);
	std::vector<gameobject*> return_objects();

	int get_grid_height();
	int get_grid_width();

	char get_object_at(int _x, int _y);

	int get_block_size();

	int get_stage_width();
	int get_stage_height();

	int get_row(int _x);
	int get_column(int _y);
};

