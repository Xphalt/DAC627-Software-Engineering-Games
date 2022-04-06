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
	m_layout.clear();

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

	const float left_x_offset{ 0.25f }, right_x_offset{ 0.75f };
	const float y_offset{ 0.15f };

	for (int row = 0; row < get_grid_height(); row++)
	{
		for (int column = 0; column < get_grid_width(); column++)
		{
			if (get_object_at(column, row) != '.')
			{
				int x = (m_block_size * column * 0.5f) - (m_block_size * row * 0.5f);
				int y = (m_block_size * row * 0.25f) + (m_block_size * column * 0.25f);

				//Create all objects in game based on text file loaded externally
				switch (get_object_at(column, row))
				{
				case WALL_LEFT:
					x += m_block_size * left_x_offset;
					y -= m_block_size * y_offset;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/WallLeft.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case WALL_RIGHT:
					x += m_block_size * right_x_offset;
					y -= m_block_size * y_offset;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/WallRight.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case FLOOR:
					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/floor.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case DOOR_LEFT:
					x += m_block_size * left_x_offset;
					y -= m_block_size * y_offset;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/doorwayLeft.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case DOOR_RIGHT:
					x += m_block_size * right_x_offset;
					y -= m_block_size * y_offset;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/doorwayRight.png"));
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

int tilemap::get_last_tile_pos_right()
{
	std::vector<gameobject*> obj = return_objects();
	int x = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		if (x < obj[i]->get_position().x)
		{
			x = obj[i]->get_position().x;
		}
	}

	return x + (m_block_size);
}

int tilemap::get_last_tile_pos_down()
{
	std::vector<gameobject*> obj = return_objects();
	int y = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		if (y < obj[i]->get_position().y)
		{
			y = obj[i]->get_position().y;
		}
	}
	return y + m_block_size;
}

int tilemap::get_last_tile_pos_left()
{
	std::vector<gameobject*> obj = return_objects();
	int x = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		if (x > obj[i]->get_position().x)
		{
			x = obj[i]->get_position().x;
		}
	}

	return x;
}

int tilemap::get_last_tile_pos_top()
{
	std::vector<gameobject*> obj = return_objects();
	int y = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		if (y > obj[i]->get_position().y)
		{
			y = obj[i]->get_position().y;
		}
	}
	return y;
}

int tilemap::get_row(int _y) { return std::floor(_y / m_block_size); }

int tilemap::get_column(int _x) { return std::floor(_x / m_block_size); }
