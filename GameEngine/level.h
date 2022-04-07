#pragma once
#include <string>
#include <vector>
#include "gameobject.h"
#include "tilemap.h"

class level
{
private:
    tilemap* m_tilemap;
    renderer* m_p_renderer; 
    camera* m_p_camera;
    input_master* m_p_input;
    minimap* m_p_minimap;
    std::vector<gameobject*> m_tilemap_objects;
    std::vector<gameobject*> m_level_objects;
    std::vector<gameobject*> m_ui_objects;
    int m_object_size;
    float i = 0;

public:
    level(std::string _fileName, renderer* renderer, input_master* input);
    ~level();
    void update();

    void set_filepath(std::string _filepath);
    void add_object(gameobject* _object);
    void add_tile();

    void sort_objects();
};
