#include "collider.h"
#include "gameobject.h"

collider::collider(int radiusIn, gameobject* parent, int xOffset = 0, int yOffset = 0)
{
    m_radius = radiusIn;
    m_p_parent = parent;
    m_position_offset = new position();
    m_position_offset->x = xOffset;
    m_position_offset->y = yOffset;

    m_circleCol = true;
}

collider::collider(position* start, position* end, gameobject* parent)
{
    m_lineStart = start;
    m_lineEnd = end;
}

collider::collider(float startx, float starty, float endx, float endy, gameobject* parent)
{
    m_lineStart = new position{ startx, starty };
    m_lineEnd = new position{ endx, endy };
    m_p_parent = parent;
}

collider::~collider()
{
    delete m_position_offset;
    delete m_lineStart;
    delete m_lineEnd;
}

void collider::updateColliders()
{
    if (!m_circleCol)
    {
        return;
    }
    position* thisPos = new position;
    thisPos->x = m_p_parent->get_position().x + m_position_offset->x;
    thisPos->y = m_p_parent->get_position().y + m_position_offset->y;

    for(int i = 0; i < m_otherColliders.size(); i++ )
    {
        position pos = m_otherColliders[i]->getParent()->get_position();
        float mag = mathFunctions::get_distance(thisPos, &pos);

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

void collider::setWallLineColliderVector(std::vector<collider*> newWalls)
{
    m_lineColliders = newWalls;
}

bool collider::isMoveValid(position* newPos)
{
    bool valid = true;
    for (int i = 0; i < m_lineColliders.size(); i++)
    {
        position start = m_lineColliders[i]->getParent()->get_position();
        position end = start;
        if (m_lineColliders[i]->m_left)
        {
            end.y -= 30;
            end.x += 50;
        }
        else
        {
            start.y -= 30;
            end.x += 50;
        }

        if (mathFunctions::get_circle_line_intersecting(m_radius, newPos, &start, &end))
        {
            valid = false;
            std::cout << i << std::endl;
        }
        /*
        if (mathFunctions::get_circle_line_intersecting(m_radius, newPos, m_lineColliders[i]->getLineStart(), m_lineColliders[i]->getLineStart()))
        {
            valid = false;
            std::cout << i << std::endl;
        }
        */

    }
    return valid;
}
