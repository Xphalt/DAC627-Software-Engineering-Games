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
	
		gameobject* m_ui_test = new gameobject(m_p_renderer, "");
		m_ui_objects.push_back(m_ui_test);

		m_ui_test->set_scale(100, 100);
		m_ui_test->set_position(150, 150);
	
	// HOW TO CREATE AN IMAGE
	/*
		m_ui_test->create_image("ui_assets/engine/DefaultImageHighlighted.png");
	*/
	// HOW TO CREATE A HOTBAR
	/*
		m_ui_test->create_hotbar(3);
	*/
	// HOW TO CREATE A BUTTON
	/*
		std::vector<std::string> button_paths;
		button_paths.push_back("ui_assets/engine/ButtonNormal.png");
		button_paths.push_back("ui_assets/engine/ButtonHighlighted.png");
		button_paths.push_back("ui_assets/engine/ButtonPressed.png");
		m_ui_test->create_button(nullptr, nullptr, button_paths);
	*/
	// HOW TO CREATE A SLIDER
	/*
		m_ui_test->set_scale(300, 50);
		slider* the_slider = m_ui_test->create_slider("ui_assets/engine/SliderFill.png", 0, 100);
		the_slider->set_value(50);
	*/
	// HOW TO CREATE TEXT
	/*
		m_ui_test->set_scale(300, 50);
		m_ui_test->create_text("Hello world", "ui_assets/fonts/VCR_OSD_MONO.ttf", { 255, 255, 255 }, 24);
	*/
	
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
