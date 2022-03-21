#include "level.h"
#include "renderer.h"

level::level(std::string _fileName, renderer* renderer)
	: m_p_renderer{ renderer }
{
	m_tilemap = new tilemap(16, _fileName, renderer);
	m_tilemap_objects = m_tilemap->return_objects();

	gameobject* m_image_test = new gameobject(m_p_renderer);
	m_ui_objects.push_back(m_image_test);
	// Dominique UI Testing
	//m_image_test->create_button();
}

level::~level()
{

}

void level::update()
{
	m_p_renderer->ClearRender();

	for (int i = 0; i < m_tilemap_objects.size(); i++)
	{
		m_tilemap_objects[i]->update();
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
