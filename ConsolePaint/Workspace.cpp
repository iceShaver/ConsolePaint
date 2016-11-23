#include "Workspace.h"
#include "conio2.h"
#include "PictureEditor.h"

int Workspace::width = 60;
int Workspace::height = 28;


Workspace::Workspace(char* name, PictureEditor::Position)
{
	this->name = name;
}

Workspace::~Workspace()
{
}

void Workspace::draw()
{
	gotoxy(1, 1);
	cputs(this->name);
	putch('|');
	gotoxy(1, 2);
	while(wherex() < Workspace::width)
		putch('_');


}
