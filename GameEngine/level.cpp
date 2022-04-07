#include "level.h"
#include "renderer.h"
#include "Camera.h"
#include "gameobject.h"
#include "animator.h"
#include "collider.h"
#include <algorithm>

level::level(std::string _fileName, renderer* renderer, input_master* input)
	: m_p_renderer{ renderer }, m_p_input{ input }
{
	m_tilemap = new tilemap(128, _fileName, renderer);
	m_tilemap_objects = m_tilemap->return_objects();

	// Dominique UI Testing
	gameobject* m_p_hotbar = new gameobject(m_p_renderer, "");
	m_ui_objects.push_back(m_p_hotbar);
	m_p_hotbar->set_scale(200, 200);
	m_p_hotbar->set_position(355, 665);

	hotbar* hotbar = m_p_hotbar->create_hotbar(5);
	std::vector<std::string> button_paths;
	button_paths.push_back("Sprites/Misc/bomb.png");
	button_paths.push_back("Sprites/Misc/bomb.png");
	button_paths.push_back("Sprites/Misc/bomb.png");
	hotbar->setup_slot(0, nullptr, button_paths);

	//gameobject* m_p_slider = new gameobject(m_p_renderer, "");
	//m_ui_objects.push_back(m_p_slider);
	//m_p_slider->set_scale(400, 50);
	//m_p_slider->set_position(275, 610);
	//slider* slider = m_p_slider->create_slider("ui_assets/engine/SliderFill.png", 0, 100);
	//slider->set_value(20);

	gameobject* m_p_text = new gameobject(m_p_renderer, "");
	m_ui_objects.push_back(m_p_text);
	m_p_text->set_scale(200, 50);
	m_p_text->set_position(5, 5);

	m_p_text->create_text("Welcome", "ui_assets/fonts/VCR_OSD_MONO.ttf", { 255, 255, 255 }, 24);


	animator* m_p_anim = new animator();
	m_p_anim->add_animation(m_p_renderer, "Sprites/Adventurer/adventurerIdle.png", "Player_Idle", 1, 4, 0.2f);
	m_p_anim->set_animation("Player_Idle");

	int windowWidth = 0, windowHeight = 0;
	SDL_GetWindowSize(m_p_renderer->GetWindow(), &windowWidth, &windowHeight);
	int fullWidth = m_tilemap->get_last_tile_pos_right();
	int fullHeight = m_tilemap->get_last_tile_pos_down();
 	m_p_camera = new camera(SDL_Rect{0,0,128,128}, 128, 128, windowWidth, windowHeight, fullWidth, fullHeight);

	gameobject* m_p_player = new gameobject(m_p_renderer, m_p_camera, m_p_anim, nullptr, input );
	m_p_player->create_player();

	m_p_camera->set_target(m_p_player);
	m_p_camera->set_map_start_left(m_tilemap->get_last_tile_pos_left());
	m_p_camera->set_map_start_top(m_tilemap->get_last_tile_pos_top());

	m_level_objects.push_back(m_p_player);
	m_level_objects.back()->set_scale(1, 1);
	m_level_objects.back()->set_position(256, 256);

	m_p_camera->update_target_pos(m_level_objects.back()->get_position().x, m_level_objects.back()->get_position().y);
	i = 0.5f;

	int mapIndex = 2;
	while (m_tilemap->load_from_file("Sprites/Tilemaps/TestMap" + std::to_string(mapIndex++)))
	{
		std::vector<gameobject*> tilemap2 = m_tilemap->return_objects();
		m_level_objects.insert(m_level_objects.end(), tilemap2.begin(), tilemap2.end());
	}

#pragma region Enemies
	gameobject* enemy = new gameobject(m_p_renderer, "Sprites/Monsters_Creatures_Fantasy/Skeleton/Walk.png", 1, 4, 200);
	enemy->set_position(0, 200);
	enemy->create_enemy(m_p_player);
	m_level_objects.push_back(enemy);
	// Add enemy to player's list of colliders
	m_p_player->get_collider()->addNewCollider(enemy->get_collider());
#pragma endregion


#pragma region UI_TUTORIAL
	// HOW TO CREATE AN IMAGE
	/*
		m_ui_test->create_image("ui_assets/engine/DefaultImageHighlighted.png");
	*/
	// HOW TO CREATE A HOTBAR
	/*
	hotbar* hotbar = m_p_hotbar->create_hotbar(5);
	std::vector<std::string> button_paths;
	button_paths.push_back("ui_assets/engine/ButtonNormal.png");
	button_paths.push_back("ui_assets/engine/ButtonHighlighted.png");
	button_paths.push_back("ui_assets/engine/ButtonPressed.png");
	hotbar->setup_slot(0, nullptr, button_paths);
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
#pragma endregion

	//Matt's minimap testing
	m_p_minimap = new minimap(m_p_renderer, "ui_assets/engine/HotbarBackground.png",
		"ui_assets/engine/DefaultImageNormal.png", "ui_assets/engine/ButtonMinimapBackground.png",
		355, 5, 200, 200, 0);
	m_p_minimap->set_player(m_p_player);
}

level::~level()
{

}

void level::update()
{ 
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
		/*if (m_level_objects[i] == m_level_objects.back())
			m_level_objects[i]->add_translation(position{this->i, this->i });*/
		if (i == 0)
		{
			m_level_objects[i]->m_testPos.x = m_p_camera->get_player_drawing_rect().x;
			m_level_objects[i]->m_testPos.y = m_p_camera->get_player_drawing_rect().y;
		}
		else
		{
			m_level_objects[i]->m_testPos.x = m_p_camera->get_tile_drawX(m_level_objects[i]->get_position().x);
			m_level_objects[i]->m_testPos.y = m_p_camera->get_tile_drawY(m_level_objects[i]->get_position().y);
		}
		m_level_objects[i]->update(false);
	}

	display_objects();

	for (int i = 0; i < m_ui_objects.size(); i++)
	{
		m_ui_objects[i]->update();
	}

	m_p_minimap->update_minimap();
	m_p_minimap->draw();

	m_p_renderer->Update();
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

void level::display_objects()
{
	std::vector<gameobject*> waiting;
	waiting.insert(waiting.begin(), m_level_objects.begin(), m_level_objects.end());

	int total = m_level_objects.size();
	for (int g1 = 0; g1 < total; g1++)
	{
		float highest = waiting[0]->get_height();
		int index = 0;
		for (int g2 = 1; g2 < waiting.size(); g2++)
		{
			if (waiting[g2]->get_position().y < highest)
			{
				highest = waiting[g2]->get_height();
				index = g2;
			}
		}

		waiting[index]->display();
		waiting.erase(waiting.begin() + index);
	}	
}
