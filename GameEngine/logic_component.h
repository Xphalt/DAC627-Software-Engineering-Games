#pragma once

class gameobject;

class logic_component {
public:
	logic_component();
	~logic_component();
	void update(gameobject& _gameobject);
};