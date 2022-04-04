#pragma once

class gameobject;
class input_wrapper;
class keyboard_input;
class gamepad_input;

class player_input
{
public:
	player_input(keyboard_input* _keyboard, gamepad_input* _gamepad);
	~player_input();

	void Execute();

private:
	input_wrapper* m_input{ nullptr };
	keyboard_input* m_keyboard{ nullptr };
	gamepad_input* m_gamepad{ nullptr };
};