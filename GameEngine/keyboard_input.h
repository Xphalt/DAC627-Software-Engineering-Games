#pragma once
#include <SDL.h>

enum Keys
{
    KEY_ESCAPE, KEY_SPACE, KEY_E, KEY_W, KEY_A, KEY_S, KEY_D, SIZE_OF_KEYS
};

class keyboard_input
{
public:
    keyboard_input();
    ~keyboard_input();

    Keys get_key() { return m_keys; }
    bool KeyIsPressed(Keys key) { return m_keysPressed[key]; }
    void Update();

private:
    SDL_Event m_event;
    Keys m_keys;
    bool m_keysPressed[SIZE_OF_KEYS];
};