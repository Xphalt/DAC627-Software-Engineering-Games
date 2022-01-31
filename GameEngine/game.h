#pragma once
#include <memory>

class gameobject;
class input_component;
class output_component;
class logic_component;

using namespace std;

class game
{
public:
	void update();

private:
	shared_ptr<gameobject> m_p_gameobject{ make_shared<gameobject>() };
};