#include "Workspace.h"
#include "conio2.h"
#include "PictureEditor.h"
#include "Cursor.h"



Workspace::Workspace(int x0, char* name, int width, int height)
{
	this->name = name;
	clrscr();
	minX = x0 + 1;
	minY = 3 + 1;
	maxX = minX + width;
	maxY = minY + height;

	//Rysowanie obramowania poziomego
	for (int i = x0; i <= maxX + 1; ++i)
	{
		if (i == x0)
		{
			gotoxy(i, minY - 1);
			putch(201);
			gotoxy(i, maxY +1);
			putch(200);
		}else if(i==maxX+1)
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
	gotoxy(x0, 1);
	textbackground(GREEN);
	cputs(this->name);
	textbackground(BLACK);
	putch('|');
	gotoxy(minX, 2);
	while (wherex() < maxX)
		putch('_');
	Cursor cursor(minX, minY, maxX, maxY);

}

Workspace::~Workspace()
{
}

void Workspace::draw()
{



}
