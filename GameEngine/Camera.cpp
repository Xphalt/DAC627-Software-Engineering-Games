#include "Camera.h"


Camera::Camera()
	:
	playerRect(SDL_Rect()), 
	tileWidth(32), 
	tileHeight(32), 
	mapFullWidth(32),
	mapFullHeight(32),
	cameraRect({ 0,0,1280,720 })
{ }

Camera::Camera(SDL_Rect _pRect, int _tileWidth, int _tileHeight, int _screenWidth, int _screenHeight, int _mapFullWidth, int _mapFullHeight)
	:
	playerRect(_pRect), 
	tileWidth(tileWidth), 
	tileHeight(_tileHeight), 
	cameraRect({ 0,0,_screenWidth,_screenHeight }),
	mapFullWidth(mapFullWidth),
	mapFullHeight(mapFullHeight)
{
	//Calculate plyer position
	cameraRect.x = (playerRect.x + (playerRect.h / 2)) - cameraRect.w / 2;
	cameraRect.y = (playerRect.y + (playerRect.h / 2)) - cameraRect.h / 2;
}

void Camera::UpdateTargetPos(int _pX, int _pY)
{
	//Set player in the middle 
	cameraRect.x = (_pX + (playerRect.w / 2)) - cameraRect.w / 2;
	cameraRect.y = (_pY + (playerRect.h / 2)) - cameraRect.h / 2;

	//Avoid player in the middle when at the edge of the map
	if (cameraRect.x < 0)
		cameraRect.x = 0;
	if (cameraRect.y < 0)
		cameraRect.y = 0;

	//same as up, but checks the end of the map
	if (cameraRect.x > mapFullWidth - cameraRect.w)
		cameraRect.x = mapFullWidth - cameraRect.w;
	if (cameraRect.y > mapFullHeight - cameraRect.h)
		cameraRect.y = mapFullHeight - cameraRect.h;
}

bool Camera::SetScreenSize(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	cameraRect.w = _width;
	cameraRect.h = _height;

	return true;
}

bool Camera::SetTileSize(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	tileWidth = _width;
	tileHeight = _height;

	return true;
}

bool Camera::SetMapFullSize(int _width, int _height)
{
	if (_width <= 0 || _height <= 0)
		return false;

	mapFullWidth = _width;
	mapFullHeight = _height;

	return true;
}

int Camera::GetStartRow()
{
	return cameraRect.y / (tileHeight * FOVscaleFactor); 
}

int Camera::GetEndRow(int _numberOfTilesVertical)
{
	int endRow = (cameraRect.y + cameraRect.h) / (tileHeight * FOVscaleFactor);
	if (endRow > _numberOfTilesVertical) //check boundaries
		endRow = _numberOfTilesVertical;

	return endRow;
}

int Camera::GetStartColumn()
{
	return cameraRect.x / (tileWidth * FOVscaleFactor);
}

int Camera::GetEndColumn(int _numberOfTilesHorizontal)
{
	int endColumn = (cameraRect.x + cameraRect.w) / (tileWidth * FOVscaleFactor);
	if (endColumn > _numberOfTilesHorizontal) //check boundaries
		endColumn = _numberOfTilesHorizontal;

	return endColumn;
}