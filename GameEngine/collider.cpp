#include "collider.h"
#include "gameobject.h"

collider::collider(float radiusIn, gameobject* parent)
{
    m_radius = radiusIn;
    m_p_parent = parent;
}

void collider::updateColliders()
{
    int posx = m_p_parent->get_position().x;
    int posy = m_p_parent->get_position().y;

    for(int i = 0; i < m_otherColliders.size(); i++ )
    {
        int diffx = posx - m_otherColliders[i]->getParent()->get_position().x;
        int diffy = posy - m_otherColliders[i]->getParent()->get_position().y;

        int mag = (diffx * diffx) + (diffy * diffy);
        mag = sqrt(mag);

        if(mag < m_radius + m_otherColliders[i]->getRadius())
        {
            printf("Collided");
        }
    }
}
