#include "tilemap.h"
#include <iostream>
#include "renderer.h"

tilemap::tilemap(int _block_size, std::string _tilemap_path, renderer* _renderer)
	: m_block_size{ _block_size }, m_p_renderer{ _renderer }
{
	load_from_file(_tilemap_path);

	m_stage_width = m_block_size * get_grid_width(); //Calculates total pixel size of tilemap based on layout
	m_stage_height = m_block_size * get_grid_height();
}

void tilemap::load_from_file(std::string _path)
{
	std::ifstream tilemapFile(_path + ".txt");
	std::string row;

	if (tilemapFile.is_open())
	{
		while (getline(tilemapFile, row)) //Gets all lines of tilemap file and stores them in a string vector
		{
			m_layout.push_back(row);
		}
	}
}

std::vector<gameobject*> tilemap::return_objects()
{
	std::vector<gameobject*> objects;

	for (int row = 0; row < get_grid_height(); row++)
	{
		for (int column = 0; column < get_grid_width(); column++)
		{
			if (get_object_at(column, row) != '.')
			{
				int x = (m_block_size * column * 0.5f) - (m_block_size * row * 0.5f);
				int y = (m_block_size * row * 0.5f) + (m_block_size * column * 0.5f);

				//Create all objects in game based on text file loaded externally
				switch (std::toupper(get_object_at(column, row)))
				{
				case WALL:
					x += m_block_size * 0.5f;
					y -= m_block_size * 0.5f;
					objects.push_back(new gameobject(m_p_renderer));
					objects[objects.size() - 1]->set_position(x, y);
					break;

				default:
					break;
				}
			}
		}
	}
	return objects;
}

int tilemap::get_grid_height() { return m_layout.size(); }

int tilemap::get_grid_width() { return m_layout[0].length(); }

char tilemap::get_object_at(int _x, int _y) { return m_layout[_y][_x]; }

int tilemap::get_block_size() { return m_block_size; }

int tilemap::get_stage_width() { return m_stage_width; }

int tilemap::get_stage_height() { return m_stage_height; }

int tilemap::get_row(int _y) { return std::floor(_y / m_block_size); }

int tilemap::get_column(int _x) { return std::floor(_x / m_block_size); }
