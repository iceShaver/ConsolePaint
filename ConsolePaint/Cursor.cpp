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
Workspace* Cursor::w;

//Cursor constructor
Cursor::Cursor(Workspace * workspace, int minX, int minY, int maxX, int maxY)
{
	w = NULL;
	this->w = workspace;
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

//Toggle draw/not-draw
void Cursor::Toggle()
{
	if (isDrawing)
		isDrawing = false;
	else
	{
		isDrawing = true;
		UpdatePosition();
		SetPosition();
	}
}

//Update and display coursor position
void Cursor::UpdatePosition()
{
	workspacePositionX = wherex() - minX + 1;
	workspacePositionY = wherey() - minY + 1;
	gotoxy(PictureEditor::instructionX0Position, PictureEditor::WINDOW_HEIGHT);
	cputs("       ");
	gotoxy(PictureEditor::instructionX0Position, PictureEditor::WINDOW_HEIGHT);
	putch('(');
	char str[3];
	_itoa_s(workspacePositionX, str, DECIMAL_SYSTEM);
	cputs(str);
	putch(',');
	_itoa_s(workspacePositionY, str, DECIMAL_SYSTEM);
	cputs(str);
	putch(')');
}

void Cursor::Move(Direction direction)
{
	if (PictureEditor::workspaceInitialized) {
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
}

//Put pixel on the picture and the array
void Cursor::SetPosition()
{
	gotoxy(positionX, positionY);
	if (isDrawing)
	{
		textcolor(color);
		textbackground(color);
		putch(PIXEL);
		SetDefault();
		w->UpdateArray(workspacePositionX, workspacePositionY);
	}
}

//Set color of the cursor
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
