#include "Mouse.h"

Mouse::Mouse()
{
    for (int i = 0; i < SIZEOF_BUTTON_LIST; i++)
    {
        buttonPressed[i] = false;
        buttonHeld[i] = false;
    }

    SDL_GetMouseState(&m_pMousePos->x, &m_pMousePos->y);

    mouseDeadZone = 200; //Arbitrary value. Needs testing to find a good number - RA
}

Mouse::~Mouse()
{
}

void Mouse::Update(SDL_Event mouseEvent)
{
    SetButtonHold();

    if (mouseEvent.type == SDL_MOUSEBUTTONDOWN)
    {
        if (mouseEvent.button.button == SDL_BUTTON_LEFT)
        {
            buttonPressed[BUTTON_LEFT] = true;
        }
        else if (mouseEvent.button.button == SDL_BUTTON_RIGHT)
        {
            buttonPressed[BUTTON_RIGHT] = true;
        }
    }

    if (mouseEvent.type == SDL_MOUSEBUTTONUP)
    {
        if (mouseEvent.button.button == SDL_BUTTON_LEFT)
        {
            buttonPressed[BUTTON_LEFT] = false;
        }
        else if (mouseEvent.button.button == SDL_BUTTON_RIGHT)
        {
            buttonPressed[BUTTON_RIGHT] = false;
        }
    }

    if (mouseEvent.type == SDL_MOUSEMOTION)
    {
        SDL_GetMouseState(&m_pMousePos->x, &m_pMousePos->y);
    }
}

bool Mouse::ButtonPressed(BUTTON_LIST button)
{
    if (!buttonHeld[button])
    {
        return buttonHeld[button];
    }
    else
    {
        return false;
    }
}

bool Mouse::ButtonHeld(BUTTON_LIST button)
{
    return buttonHeld[button];
}

void Mouse::SetButtonHold()
{
    for (int i = 0; i < SIZEOF_BUTTON_LIST; i++)
    {
        buttonHeld[i] = buttonPressed[i];
    }
}

SDL_Point Mouse::GetMousePos()
{
    return *m_pMousePos;
}

void Mouse::SetMousePos(int x, int y)
{
    m_pMousePos->x = x;
    m_pMousePos->y = y;
}

void Mouse::SetMousePos(SDL_Point newPos)
{
    *m_pMousePos = newPos;
}
