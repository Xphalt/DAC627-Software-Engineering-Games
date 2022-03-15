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
    std::vector<gameobject*> m_tilemap_objects;
    std::vector<gameobject*> m_level_objects;
    std::vector<gameobject*> m_ui_objects;
    int m_object_size;

public:
    level(std::string _fileName, renderer* renderer);
    ~level();
    void update();

    void set_filepath(std::string _filepath);
    void add_object(gameobject* _object);
    void add_tile();
};
