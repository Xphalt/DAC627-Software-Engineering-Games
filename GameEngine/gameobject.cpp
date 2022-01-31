#include "gameobject.h"
#include "input_component.h"
#include "output_component.h"
#include "logic_component.h"

gameobject::gameobject(shared_ptr<input_component>& _input, shared_ptr<output_component>& _output, shared_ptr<logic_component>& _logic)
	: m_p_input_component{_input}, m_p_output_component{_output}, m_p_logic_component{_logic}
{
}

gameobject::~gameobject()
{
}

void gameobject::update()
{
	m_p_input_component->update(*this);
	m_p_output_component->update(*this);
	m_p_logic_component->update(*this);
}