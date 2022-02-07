#pragma once
#include<SDL.h>
#include "game.h"

using namespace std;

int main(int argc, char* argv[])
{
	game* j = new game();
	j->update();
	return 0;
}