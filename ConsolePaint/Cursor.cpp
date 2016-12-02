#include "Cursor.h"
#include "conio2.h"
#include "PictureEditor.h"
#include <cstdio>
#include "Keyboard.h"
#include <stdlib.h>

int Cursor::positionX;
int Cursor::positionY;
int Cursor::workspacePositionX;
int Cursor::workspacePositionY;
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
	workspacePositionX = 0;
	workspacePositionY = 0;

}


Cursor::~Cursor()
{
}

void Cursor::MoveTo(int positionX, int positionY)
{
	gotoxy(positionX, positionY);
}

void Cursor::UpdatePosition()
{
	workspacePositionX = wherex() - minX;
	workspacePositionY = wherey() - minY;
	gotoxy(1, PictureEditor::windowHeight);
	cputs("       ");
	gotoxy(1, PictureEditor::windowHeight);

	putch('(');
	char str[3];
	_itoa_s(workspacePositionX, str, 10);
	cputs(str);
	putch(',');
	_itoa_s(workspacePositionY, str, 10);

	cputs(str);
	putch(')');
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
	UpdatePosition();
	SetPosition();
}

void Cursor::SetPosition()
{
	gotoxy(positionX, positionY);
	textcolor(color);
	textbackground(color);
	putch(219);
	SetDefault();
	
}

void Cursor::SetColor(Color Cursorcolor)
{
	color = Cursorcolor;
	gotoxy(positionX, positionY);
	textcolor(color);
	textbackground(color);
	putch(219);
	SetDefault();
}

void Cursor::SetDefault()
{
	textcolor(white);
	textbackground(black);
}
