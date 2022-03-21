#include "level.h"
#include "renderer.h"
#include "Camera.h"
#include "gameobject.h"

level::level(std::string _fileName, renderer* renderer, camera* camera)
	: m_p_renderer{ renderer }, m_p_camera{ camera }
{
	m_tilemap = new tilemap(128, _fileName, renderer);
	m_tilemap_objects = m_tilemap->return_objects();

	// Dominique UI Testing
	gameobject* m_image_test = new gameobject(m_p_renderer, "");
	m_ui_objects.push_back(m_image_test);
	m_image_test->create_hotbar();
}

level::~level()
{

}

void level::update()
{
	m_p_renderer->ClearRender();

	for (int i = 0; i < m_tilemap_objects.size(); i++)
	{
		//if (m_p_camera->can_draw_tile(m_tilemap_objects[i]))
		//{
			m_tilemap_objects[i]->m_testPos.x = m_p_camera->get_tile_drawX(m_tilemap_objects[i]->get_position().x);
			m_tilemap_objects[i]->m_testPos.y = m_p_camera->get_tile_drawY(m_tilemap_objects[i]->get_position().y);

			m_tilemap_objects[i]->update();
		//}
	}

	for (int i = 0; i < m_level_objects.size(); i++)
	{
		m_level_objects[i]->update();
	}

	for (int i = 0; i < m_ui_objects.size(); i++)
	{
		m_ui_objects[i]->update();
	}

	m_p_renderer->PresentRender();
}

void level::set_filepath(std::string _filepath)
{
	m_tilemap_objects.clear();
	m_level_objects.clear();
	m_ui_objects.clear();

	//m_tilemap->set the filepath
}

void level::add_object(gameobject* _object)
{
	m_level_objects.push_back(_object);
}

void level::add_tile()
{

}
