#include "Cursor.h"
#include "conio2.h"
#include "PictureEditor.h"
#include <cstdio>
#include "Keyboard.h"

int Cursor::positionX;
int Cursor::positionY;
int Cursor::minX;
int Cursor::minY;
int Cursor::maxX;
int Cursor::maxY;
Cursor::Color Cursor::color;



Cursor::Cursor(int minX, int minY, int maxX, int maxY)
{
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
	positionX = minX;
	positionY = minY;

}


Cursor::~Cursor()
{
}

void Cursor::MoveTo(int positionX, int positionY)
{
	gotoxy(positionX, positionY);
}

void Cursor::Move(Direction direction)
{
	if (direction == up && positionY > minY)
		positionY--;
	else if (direction == down && positionY < maxY)
		positionY++;
	else if (direction == left && positionX > minX)
		positionX--;
	else if (direction == right && positionX < maxX)
		positionX++;
	gotoxy(positionX, positionY);
	putch(219);
}

void Cursor::SetPosition()
{
	gotoxy(positionX, positionY);
	//_setcursortype(_NOCURSOR);
	
}

