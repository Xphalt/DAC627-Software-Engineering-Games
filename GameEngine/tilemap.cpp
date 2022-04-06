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
				int y = (m_block_size * row * 0.42f) + (m_block_size * column * 0.42f);

				//Create all objects in game based on text file loaded externally
				switch (std::toupper(get_object_at(column, row)))
				{
				case WALL:
					x += m_block_size * 0.5f;
					y -= m_block_size * 0.5f;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/Floor.bmp"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case FLOOR:
					x += m_block_size * 0.5f;
					y -= m_block_size * 0.5f;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/DoorFrontLeft.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;
				case DOOR:
					x += m_block_size * 0.5f;
					y -= m_block_size * 0.5f;

					objects.push_back(new gameobject(m_p_renderer, "Sprites/Isometric/WallLeft.png"));
					objects[objects.size() - 1]->set_position(x, y);
					break;

				default:
					break;
				}
			}
		}
	}

	gameobject* newObject = new gameobject(m_p_renderer, "Sprites/Potions/potion1.png");
	newObject->set_position(5, 5);
	newObject->create_enemy();
	objects.push_back(newObject);
	return objects;
}

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