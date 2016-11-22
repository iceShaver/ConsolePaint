#include "Cursor.h"
#include "conio2.h"


Cursor::Cursor()
{
	this->positionX = 20;
	this->positionY = 20;
}


Cursor::~Cursor()
{
}

void Cursor::MoveTo(int positionX, int positionY)
{
	gotoxy(positionX, positionY);
}

void Cursor::Move(int positionXOffset, int positionYOffset)
{
	this->positionX += positionXOffset;
	this->positionY += positionYOffset;
	gotoxy(this->positionX, this->positionY);
}

void Cursor::SetPosition()
{
	gotoxy(this->positionX, this->positionY);
}
