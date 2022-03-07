#include "gameobject.h"
#include "renderer.h"
#include "image.h"
#include "ui_component.h"
#include "camera.h"
#include "animation.h"
#include "animator.h"
#include "audioman.h"
#include "input_master.h"

gameobject::~gameobject()
{
}

void gameobject::update()
{
}

gameobject* gameobject::create_player()
{
	return nullptr;
}

gameobject* gameobject::create_enemy()
{
	return nullptr;
}

gameobject* gameobject::create_UI()
{
	return nullptr;
}