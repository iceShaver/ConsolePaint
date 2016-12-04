#include "Cursor.h"
#include "conio2.h"
#include "PictureEditor.h"
#include <cstdio>
#include "Keyboard.h"
#include <stdlib.h>
#include "Workspace.h"

int Cursor::positionX;
int Cursor::positionY;
int Cursor::workspacePositionX;
int Cursor::workspacePositionY;
int Cursor::minX;
int Cursor::minY;
int Cursor::maxX;
int Cursor::maxY;
Cursor::Color Cursor::color;
bool Cursor::isDrawing;


Cursor::Cursor(Workspace * workspace, int minX, int minY, int maxX, int maxY)
{
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
	positionX = minX;
	positionY = minY;
	workspacePositionX = 0;
	workspacePositionY = 0;
	isDrawing = false;
	SetPosition();
	UpdatePosition();

}


Cursor::~Cursor()
{
}

void Cursor::Toggle()
{
	if (isDrawing)
		isDrawing = false;
	else
	{
		isDrawing = true;
		SetPosition();
	}

}

void Cursor::MoveTo(int positionX, int positionY)
{
	gotoxy(positionX, positionY);
}

void Cursor::UpdatePosition()
{
	workspacePositionX = wherex() - minX + 1;
	workspacePositionY = wherey() - minY + 1;
	gotoxy(PictureEditor::instructionX0Position, PictureEditor::windowHeight);
	cputs("       ");
	gotoxy(PictureEditor::instructionX0Position, PictureEditor::windowHeight);

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
	if (isDrawing)
	{
		textcolor(color);
		textbackground(color);
		putch(219);
		SetDefault();
	}

}

void Cursor::SetColor(Color Cursorcolor)
{
	color = Cursorcolor;
	SetPosition();
}

void Cursor::SetDefault()
{
	textcolor(white);
	textbackground(black);
}
