#include "Cursor.h"
#include "conio2.h"
#include "PictureEditor.h"

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

void Cursor::Move(Direction direction)
{
	if (direction == up && positionY > 1)
		positionY--;
	else if (direction == down && positionY < PictureEditor::windowHeight)
		positionY++;
	else if (direction == left && positionX > 1)
		positionX--;
	else if (direction == right && positionX < 60)
		positionX++;
	gotoxy(positionX, positionY);
}

void Cursor::SetPosition()
{
	gotoxy(positionX, positionY);
}

