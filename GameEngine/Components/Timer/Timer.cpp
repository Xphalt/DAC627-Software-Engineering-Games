#include "Timer.h"
#include <SDL.h>

float Timer::delta_time()
{
	return (float)(current_tick - previous_tick) / THOUSAND;
}

void Timer::update_timer()
{
	previous_tick = current_tick;
	current_tick = SDL_GetTicks();
}
