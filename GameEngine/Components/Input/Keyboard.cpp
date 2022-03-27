#include "Keyboard.h"
#include <iostream>

bool Keyboard::keysPressed[SIZEOF_KEY_LIST];
bool Keyboard::keysHeld[SIZEOF_KEY_LIST];

Keyboard::Keyboard()
{
    for (int i = 0; i < SIZEOF_KEY_LIST; i++)
    {
        keysPressed[i] = false;
        keysHeld[i] = false;
    }
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update(SDL_Event event)
{
    SetKeyHold();

    if (event.type == SDL_KEYDOWN)
    {
        SDL_Keycode pressed = event.key.keysym.sym;

        switch (pressed)
        {
        case SDLK_ESCAPE:
            keysPressed[KEY_ESC] = true;
            break;
        case SDLK_w: case SDLK_UP:
            keysPressed[KEY_UP] = true;
            break;
        case SDLK_a: case SDLK_LEFT:
            keysPressed[KEY_LEFT] = true;
            break;
        case SDLK_s: case SDLK_DOWN:
            keysPressed[KEY_DOWN] = true;
            break;
        case SDLK_d: case SDLK_RIGHT:
            keysPressed[KEY_RIGHT] = true;
            break;
        case SDLK_p:
            keysPressed[KEY_P] = true;
            break;
        case SDLK_SPACE:
            keysPressed[KEY_SPACE] = true;
            break;
        case SDLK_LSHIFT:
            keysPressed[KEY_LSHIFT] = true;
            break;
        case SDLK_RETURN:
            keysPressed[KEY_ENTER] = true;
            break;
        default:
            break;
        }

#ifdef _DEBUG
        std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG
    }

    else if (event.type == SDL_KEYUP)
    {
        SDL_Keycode pressed = event.key.keysym.sym;

        switch (pressed)
        {
        case SDLK_ESCAPE:
            keysPressed[KEY_ESC] = false;
            break;
        case SDLK_w: case SDLK_UP:
            keysPressed[KEY_UP] = false;
            break;
        case SDLK_a: case SDLK_LEFT:
            keysPressed[KEY_LEFT] = false;
            break;
        case SDLK_s: case SDLK_DOWN:
            keysPressed[KEY_DOWN] = false;
            break;
        case SDLK_d: case SDLK_RIGHT:
            keysPressed[KEY_RIGHT] = false;
            break;
        case SDLK_p:
            keysPressed[KEY_P] = false;
            break;
        case SDLK_SPACE:
            keysPressed[KEY_SPACE] = false;
            break;
        case SDLK_LSHIFT:
            keysPressed[KEY_LSHIFT] = false;
            break;
        case SDLK_RETURN:
            keysPressed[KEY_ENTER] = false;
            break;
        default:
            break;
        }
#ifdef DEBUG
        std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG
    }
}

bool Keyboard::KeyPressed(KEY_LIST key)
{
    if (!keysHeld[key])
    {
        return keysPressed[key];
    }
    else
    {
        return false;
    }
}

bool Keyboard::KeyHeld(KEY_LIST key)
{
    return keysHeld[key];
}

void Keyboard::SetKeyHold()
{
    for (int i = 0; i < SIZEOF_KEY_LIST; i++)
    {
        keysHeld[i] = keysPressed[i];
    }
}
