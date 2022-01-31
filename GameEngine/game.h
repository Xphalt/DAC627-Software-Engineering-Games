#pragma once
#include <memory>

class gameobject;
class input_component;

using namespace std;

class game
{
public:
	void update();

private:
	shared_ptr<gameobject> m_p_gameobject{ make_shared<gameobject>() };
	shared_ptr<input_component> m_p_input_component{ make_shared<input_component>() };
};