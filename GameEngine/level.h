#pragma once
#include <string>
#include <vector>
#include "gameobject.h"
#include "tilemap.h"

class gameobject;
class renderer;
class camera;
class animation;
class animator;
class audioman;
class player_input;

class level
{

public:
    level(std::string _fileName, renderer* renderer);
    ~level();
    void update();

    void set_filepath(std::string _filepath);
    void add_object(gameobject* _object);
    void add_tile();

private:
    tilemap* m_tilemap;
    renderer* m_p_renderer;
    camera* m_p_camera;
    std::vector<gameobject*> m_tilemap_objects;
    std::vector<gameobject*> m_level_objects;
    std::vector<gameobject*> m_ui_objects;
    int m_object_size;

    animation* m_p_animation{ nullptr };
    animator* m_p_animator{ nullptr };
    audioman* m_p_audio{ nullptr };
    player_input* m_p_player_input{ nullptr };

    gameobject* m_p_player{ nullptr };
};