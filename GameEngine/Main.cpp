#include <SDL.h>
#include "Core/game.h"

int main(int argc, char* argv[])
{
	game* new_game = new game();
	new_game->update();
	return 0;
}