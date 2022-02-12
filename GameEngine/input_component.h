#pragma once

class gameobject;
class InputMaster;
class Gamepad;

class input_component {
public:
	input_component();
	~input_component();
	void update(gameobject& _gameobject);
};