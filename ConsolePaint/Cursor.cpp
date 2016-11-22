#include "Cursor.h"
#include "conio2.h"

int Cursor::positionX = 20;
int Cursor::positionY = 20;

Cursor::Cursor()
{

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
	positionX += positionXOffset;
	positionY += positionYOffset;
	gotoxy(positionX, positionY);
}

void Cursor::SetPosition()
{
	gotoxy(positionX, positionY);
}

