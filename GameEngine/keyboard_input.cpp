#include "keyboard_input.h"

keyboard_input::keyboard_input()
{
}

keyboard_input::~keyboard_input()
{
}

void keyboard_input::Update()
{
    while (SDL_PollEvent(&m_event) != 0)
    {
        SDL_Keycode keyPressed = m_event.key.keysym.sym;

        switch (m_event.type)
        {
#pragma region keyDown
        case SDL_KEYDOWN:

            if (keyPressed == SDLK_ESCAPE)
            {
                m_keysPressed[KEY_ESCAPE] = true;
            }

            if (keyPressed == SDLK_a)
            {
                m_keysPressed[KEY_A] = true;
            }

            if (keyPressed == SDLK_d)
            {
                m_keysPressed[KEY_D] = true;
            }


            if (keyPressed == SDLK_SPACE)
            {
                m_keysPressed[KEY_SPACE] = true;
            }

            break;
#pragma endregion

#pragma region keyUp
        case SDL_KEYUP:

            if (keyPressed == SDLK_ESCAPE)
            {
                m_keysPressed[KEY_ESCAPE] = false;
            }

            if (keyPressed == SDLK_a)
            {
                m_keysPressed[KEY_A] = false;
            }

            if (keyPressed == SDLK_d)
            {
                m_keysPressed[KEY_D] = false;
            }

            if (keyPressed == SDLK_SPACE)
            {
                m_keysPressed[KEY_SPACE] = false;
            }

            break;
#pragma endregion
        }
    }
}