#include "collider.h"
#include "gameobject.h"

collider::collider(int radiusIn, gameobject* parent, int xOffset = 0, int yOffset = 0)
{
    m_radius = radiusIn;
    m_p_parent = parent;
    m_position_offset = new position();
    m_position_offset->x = xOffset;
    m_position_offset->y = yOffset;
}

collider::~collider()
{
    delete m_position_offset;
}

void collider::updateColliders()
{
    float posx = m_p_parent->get_position().x + m_position_offset->x;
    float posy = m_p_parent->get_position().y + m_position_offset->y;

    for(int i = 0; i < m_otherColliders.size(); i++ )
    {
        float diffx = posx - m_otherColliders[i]->getParent()->get_position().x;
        float diffy = posy - m_otherColliders[i]->getParent()->get_position().y;

        float mag = (diffx * diffx) + (diffy * diffy);
        mag = sqrt(mag);

        if(mag < m_radius + m_otherColliders[i]->getRadius())
        {
            printf("Collided");
        }
    }
}

void collider::addNewCollider(collider* newCol)
{
    m_otherColliders.push_back(newCol);
}