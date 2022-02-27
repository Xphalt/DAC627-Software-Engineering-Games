#include "gameobject.h"
#include "input_component.h"
#include "output_component.h"
#include "logic_component.h"

#include "audioman.h"

gameobject::gameobject()
{
	//audioman::runAudio("MusicIdea", 69, 1); // unironically 69 is a really good medium volume...
	audioman::runSFX(1, 69, 1);
	SDL_Delay(100000);

	//audioman::runAudio("Explosion", 69, 2);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 3);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 4);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 5);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 6);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 7);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 8);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 9);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 10);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 11);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 12);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 13);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 14);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 15);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 16);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 17);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 18);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 19);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 20);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 21);
	//SDL_Delay(50);
	//audioman::runAudio("Explosion", 69, 22);
	//SDL_Delay(50);

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