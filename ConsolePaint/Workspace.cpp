#include "Workspace.h"
#include "conio2.h"
#include "PictureEditor.h"
#include "Cursor.h"
#include <cstring>

Workspace::Workspace(int x0, char* name, int width, int height)
{
	this->x0 = x0;
	this->width = width - 1;
	this->height = height - 1;
	this->name = name;
	this->picture = new short*[this->width];
	for (int i = 0; i < this->width; ++i)
	{
		picture[i] = new short[height];
	}
	clrscr();
	minX = x0 + 1;
	minY = 3 + 1;
	maxX = minX + this->width;
	maxY = minY + this->height;


	gotoxy(x0, 1);
	textbackground(GREEN);
	cputs(this->name);
	textbackground(BLACK);
	putch('|');
	gotoxy(minX, 2);
	while (wherex() < maxX)
		putch('_');
	Cursor cursor(this, minX, minY, maxX, maxY);
	DrawFrame();

}

Workspace::Workspace(int x0, Picture picture)
{
	this->x0 = x0;
	this->width = picture.width;
	this->height = picture.height;
	this->name = picture.name;
	this->picture = picture.content;
	minX = x0 + 1;
	minY = 3 + 1;
	maxX = minX + this->width - 1;
	maxY = minY + this->height - 1;
	this->name = new char[32];
	strcpy(this->name, picture.name);
	clrscr();

	gotoxy(x0, 1);
	textbackground(GREEN);
	cputs(this->name);
	textbackground(BLACK);
	putch('|');
	gotoxy(minX, 2);
	while (wherex() < maxX)
		putch('_');
	Cursor cursor(this, minX, minY, maxX, maxY);
	DrawFrame();
	for (int i = 0; i < picture.height; ++i)
	{
		for (int j = 0; j < picture.width; ++j)
		{
			gotoxy(minX + j, minY + i);
			textcolor(picture.content[i][j]);
			textbackground(picture.content[i][j]);
			putch(219);
		}
	}
	delete[] picture.content;
	//delete picture;
	Cursor::SetDefault();

}

void Workspace::DrawFrame()
{
	//Rysowanie obramowania poziomego
	for (int i = x0; i <= maxX + 1; ++i)
	{
		if (i == x0)
		{
			gotoxy(i, minY - 1);
			putch(201);
			gotoxy(i, maxY + 1);
			putch(200);
		}
		else if (i == maxX + 1)
		{
			gotoxy(i, minY - 1);
			putch(187);
			gotoxy(i, maxY + 1);
			putch(188);
		}

		else {
			gotoxy(i, minY - 1);
			putch(205);
			gotoxy(i, maxY + 1);
			putch(205);
		}

	}
	//Rysowanie obramowana pionowego
	for (int i = minY; i <= maxY; ++i)
	{

		gotoxy(minX - 1, i);
		putch(186);
		gotoxy(maxX + 1, i);
		putch(186);




	}
}

Workspace::~Workspace()
{
}

void Workspace::draw()
{



}
