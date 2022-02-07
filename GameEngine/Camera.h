#pragma once 
#include <SDL.h>


class Camera
{
private:
	//Player position 
	SDL_Rect playerRect;

	//Tiles details 
	int tileWidth, tileHeight;
	//Map details 
	int mapFullWidth, mapFullHeight;

	//Screen and camera details details
	SDL_Rect cameraRect;

public:
	Camera();
	Camera(SDL_Rect _pRect, int _tileWidth, int _tileHeight, int _screenWidth, int _screenHeight, int _mapFullWidth, int _mapFullHeight);
	~Camera() = default;

	void UpdateTargetPos(int _pX, int _pY); 

	//Setters
	bool SetScreenSize(int _width, int _height);
	bool SetTileSize(int _width, int _height);
	bool SetMapFullSize(int _width, int _height);
	

	//Getters for rendering map
	int GetStartRow();
	int GetEndRow(int _numberOfTilesVertical);
	int GetStartColumn();
	int GetEndColumn(int _numberOfTilesHorizontal); 
};