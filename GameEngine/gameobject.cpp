#include "gameobject.h"
#include "input_component.h"
#include "output_component.h"
#include "logic_component.h"

#include "audioman.h"

gameobject::gameobject()
{
	audioman::runAudio("MusicIdea", 69, 1); // unironically 69 is a really good medium volume...
	audioman::runAudio("LevelTheme", 128, 1);
	audioman::runAudio("Back", 128, 1);
	audioman::runAudio("Boss Charge Attack", 128, 1);
	audioman::runAudio("EnemyHurt", 128, 1);
	audioman::runAudio("Explosion", 128, 1);
	audioman::runAudio("Dash", 128, 1);
	SDL_Delay(100000);
	m_p_input_component = new input_component();
	m_p_output_component = new output_component();
	m_p_logic_component = new logic_component();
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