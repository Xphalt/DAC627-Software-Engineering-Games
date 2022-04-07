#pragma once
#include <vector>
#include <conio.h>
#include <string>
#include "mathFunctions.h"

class gameobject;
struct position;

class collider
{
public:
    collider(int radiusIn, gameobject* parent, int xOffset, int yOffset);
    ~collider();

    void updateColliders();

protected:
    float m_radius;
    gameobject* m_p_parent;
    std::vector<collider*> m_otherColliders;
    std::vector<collider*> m_lineColliders;
    position* m_position_offset;

    position* m_lineStart;
    position* m_lineEnd;

public:
    gameobject* getParent() { return m_p_parent; }
    float getRadius() { return m_radius; }

    void addNewCollider(collider* newCol);

    bool isMoveValid(position* newPos);
};

