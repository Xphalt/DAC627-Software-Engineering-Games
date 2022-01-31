#pragma once
#include<SDL.h>
#undef main
#include <memory>
#include "game.h"

using namespace std;

int main()
{
	unique_ptr<game> game;
	game->update();

	return 0;
}