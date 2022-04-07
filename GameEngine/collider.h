#pragma once
#include <vector>
#include <conio.h>
#include <iostream>
#include <string>
#include "mathFunctions.h"

class gameobject;
struct position;

class collider
{
public:
    collider(int radiusIn, gameobject* parent, int xOffset, int yOffset);
    collider(position* start, position* end, gameobject* parent);
    collider(float startx, float starty, float endx, float endy, gameobject* parent);
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

    bool m_circleCol = false;

public:
    gameobject* getParent() { return m_p_parent; }
    float getRadius() { return m_radius; }

    void addNewCollider(collider* newCol);
    void setWallLineColliderVector(std::vector<collider*> newWalls);

    bool isMoveValid(position* newPos);
    bool m_left = false;

    position* getLineStart() { return m_lineStart; }
    position* getLineEnd() { return m_lineEnd; }
};

