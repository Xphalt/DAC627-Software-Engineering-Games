#include "gamepad_input.h"

gamepad_input::gamepad_input()
{
    m_bControllerInitialised = false;

    InitialiseController();

    for (int i = 0; i < SIZE; i++) { m_bButtonsPressed[i] = NULL; }
}

gamepad_input::~gamepad_input()
{
    if (m_bControllerInitialised)
    {
        SDL_GameControllerClose(m_controller);
    }
}

void gamepad_input::InitialiseController()
{
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0) { SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER); }

    if (SDL_NumJoysticks() > 0)
    {
        SDL_GameController* pad{ nullptr };

        if (SDL_IsGameController)
        {
            pad = SDL_GameControllerOpen(0);

            if (pad) { m_controller = pad; }

#ifndef NDEBUG
            else { fprintf(stderr, "Could not open controller: %s\n", SDL_GetError()); }
#endif
        }

        SDL_GameControllerEventState(SDL_ENABLE);
        m_bControllerInitialised = true;

#ifndef NDEBUG
        std::cout << "Initialised gamepad" << std::endl;
#endif
    }

    else
    {
        m_bControllerInitialised = false;

#ifndef NDEBUG
        std::cout << "No controller detected, using keyboard layout instead." << std::endl;
#endif
    }
}

void gamepad_input::Update()
{
    while (SDL_PollEvent(&m_event) != NULL)
    {
        if (m_event.type == SDL_CONTROLLERBUTTONDOWN)
        {
            SDL_ControllerButtonEvent buttonPressed = m_event.cbutton;

            switch (buttonPressed.button)
            {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                m_bButtonsPressed[UP] = true;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                m_bButtonsPressed[DOWN] = true;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                m_bButtonsPressed[LEFT] = true;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                m_bButtonsPressed[RIGHT] = true;
                break;

            case SDL_CONTROLLER_BUTTON_A:
                m_bButtonsPressed[A] = true;
                break;

            case SDL_CONTROLLER_BUTTON_B:
                m_bButtonsPressed[B] = true;
                break;

            case SDL_CONTROLLER_BUTTON_X:
                m_bButtonsPressed[X] = true;
                break;

            case SDL_CONTROLLER_BUTTON_Y:
                m_bButtonsPressed[Y] = true;
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                m_bButtonsPressed[L1] = true;
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                m_bButtonsPressed[R1] = true;
                break;
            }
        }

        else if (m_event.type == SDL_CONTROLLERBUTTONUP)
        {
            SDL_ControllerButtonEvent buttonPressed = m_event.cbutton;

            switch (buttonPressed.button)
            {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                m_bButtonsPressed[UP] = false;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                m_bButtonsPressed[DOWN] = false;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                m_bButtonsPressed[LEFT] = false;
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                m_bButtonsPressed[RIGHT] = false;
                break;

            case SDL_CONTROLLER_BUTTON_A:
                m_bButtonsPressed[A] = false;
                break;

            case SDL_CONTROLLER_BUTTON_B:
                m_bButtonsPressed[B] = false;
                break;

            case SDL_CONTROLLER_BUTTON_X:
                m_bButtonsPressed[X] = false;
                break;

            case SDL_CONTROLLER_BUTTON_Y:
                m_bButtonsPressed[Y] = false;
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                m_bButtonsPressed[L1] = false;
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                m_bButtonsPressed[R1] = false;
                break;
            }
        }

        else if (m_event.type == SDL_CONTROLLERDEVICEREMOVED)
        {
            m_bControllerInitialised = false;
            std::cout << "Gamepad removed" << std::endl;
        }
    }
}