#include "PictureEditor.h"
#include <cstdio>
#include "conio2.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Workspace.h"
#include "File.h"


const int PictureEditor::windowWidth = 120;
const int PictureEditor::windowHeight = 30;
PictureEditor::PictureEditor()
{
	this->loadModule();
	this->programRunning = true;
	

}

PictureEditor::~PictureEditor()
{
}

void PictureEditor::DrawInterface()
{

	this->drawInstruction(right);



	

}

bool PictureEditor::GetProgramState()
{
	return this->programRunning;
}

void PictureEditor::Tasker()
{
	Keyboard::Key key = Keyboard::getKey();
	switch (key)
	{
	case Keyboard::upArrow:
		Cursor::Move(Cursor::up);
		break;
	case Keyboard::downArrow:
		Cursor::Move(Cursor::down);
		break;
	case Keyboard::leftArrow:
		Cursor::Move(Cursor::left);
		break;
	case Keyboard::rightArrow:
		Cursor::Move(Cursor::right);
	case Keyboard::space: break;
	case Keyboard::backspace: break;
	case Keyboard::enter: break;
	case Keyboard::n:
	{
		Workspace workspace(File::CreateNewFile(), left);
		workspace.draw();
		break;
	}
	case Keyboard::ESC:
		this->programRunning = false;
		break;
	case Keyboard::any: break;
	default: break;
	}
}

void PictureEditor::loadModule()
{

}

void PictureEditor::drawInstruction(PictureEditor::Position position)
{
	int x, y=1;
	switch (position)
	{
	case left:
		x = 1;
		for (int i = 0; i <= 28; ++i)
		{
			gotoxy(x + 44, y + i);
			cputs("|");
		}
		break;
	case right:
		x = 61;
		for (int i = 0; i <= 28; ++i)
		{
			gotoxy(x - 1, y + i);
			cputs("|");
		}
		break;
	default:
		x = 1;
		break;
	}

	gotoxy(x,y);
	cputs("Instrukcja:");
	gotoxy(x, ++y);
	cputs("Strzalki - poruszanie");
	gotoxy(x, ++y);
	cputs("ESC - wyjscie");
	gotoxy(x, ++y);
	cputs("i - wczytaj obrazek domyslny");
	gotoxy(x, ++y);
	cputs("o - wczytaj podany plik");
	gotoxy(x, ++y);
	cputs("n - nowy plik");
	gotoxy(x, ++y);
	cputs("s - zapisz");
	gotoxy(x, ++y);
	cputs("l - rysuj linie");
	gotoxy(x, ++y);
	cputs("k - rysuj prostokat");
	gotoxy(x, ++y);
	cputs("1234567890qwerty - wybor koloru");
	gotoxy(x, ++y);
	cputs("ctrl+strzalki - przewijanie ekranu");
	gotoxy(x, ++y);
	cputs("backspace - cofnij");
	gotoxy(x, ++y);
	cputs("alt+strzalki - zaznacz obszar do kopiowania");
	gotoxy(x, ++y);
	cputs("c - kopiuj zaznaczony fragment do schowka");
	gotoxy(x, ++y);
	cputs("p - wklej fragment ze schowka");
	gotoxy(x, ++y);
	cputs("f - wypelnianie");
	Cursor::SetPosition();
	
}


