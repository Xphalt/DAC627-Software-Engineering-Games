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
    position* thisPos = new position;
    thisPos->x = m_p_parent->get_position().x + m_position_offset->x;
    thisPos->y = m_p_parent->get_position().y + m_position_offset->y;

    for(int i = 0; i < m_otherColliders.size(); i++ )
    {
        float mag = mathFunctions::get_distance(thisPos, &m_otherColliders[i]->getParent()->get_position());

        if(mag < m_radius + m_otherColliders[i]->getRadius())
        {
            printf("Collided");
        }
    }

    delete thisPos;
}

void collider::addNewCollider(collider* newCol)
{
    m_otherColliders.push_back(newCol);
}

bool collider::isMoveValid(position* newPos)
{
    return mathFunctions::get_circle_line_intersecting(m_radius, newPos, m_lineStart, m_lineEnd);
}
