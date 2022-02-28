#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include "gameobject.h"

const std::string MAP_PATH = "Levels\\";

enum ObjectTypes
{
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

public:
	tilemap(int _block_size, std::string _tilaemap_path, SDL_Renderer* _renderer);

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
