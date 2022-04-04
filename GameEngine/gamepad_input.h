#pragma once

#include <SDL.h>
#include <SDL_gamecontroller.h>
#include <iostream>

enum Buttons
{
    UP, DOWN, LEFT, RIGHT, A, X, Y, B, L1, R1, SIZE
};

class gamepad_input
{
public:
    gamepad_input();
    ~gamepad_input();

    void InitialiseController();
    bool GetControllerInitialised() { return m_bControllerInitialised; }
    Buttons get_buttons() { return m_buttons; }
    bool ButtonIsPressed(Buttons button) { return m_bButtonsPressed[button]; }
    void Update();
private:
    SDL_GameController* m_controller{ nullptr };
    SDL_Event m_event;
    Buttons m_buttons;

    bool m_bButtonsPressed[SIZE];
    bool m_bControllerInitialised{ false };
};