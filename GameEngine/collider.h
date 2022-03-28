#pragma once
#include <vector>
#include <cmath>
#include <conio.h>
#include <string>

class gameobject;

class collider
{
public:
    collider(float radiusIn, gameobject* parent);
    ~collider();

    void updateColliders();


protected:
    float m_radius;
    gameobject* m_p_parent;
    std::vector<collider*> m_otherColliders;

public:
    gameobject* getParent() { return m_p_parent; }
    float getRadius() { return m_radius; }
};

