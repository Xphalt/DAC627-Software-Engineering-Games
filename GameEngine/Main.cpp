#pragma once
#include<SDL.h>
#include <memory>
#include "game.h"

using namespace std;

int main(int argc, char* argv[])
{
	unique_ptr<game> game;
	game->update();

	return 0;
}