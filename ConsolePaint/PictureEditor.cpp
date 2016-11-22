#include "PictureEditor.h"
#include <cstdio>
#include "conio2.h"
#include "Keyboard.h"
#include "Cursor.h"
extern Cursor cursor;
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
	this->putInstruction(right);
	//cursor.SetDefaultPosition();

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
		cursor.Move(0, -1);
		break;
	case Keyboard::downArrow:
		cursor.Move(0, 1);
		break;
	case Keyboard::leftArrow:
		cursor.Move(-1, 0);
		break;
	case Keyboard::rightArrow:
		cursor.Move(1, 0);
	case Keyboard::space: break;
	case Keyboard::backspace: break;
	case Keyboard::enter: break;
	case Keyboard::ESC: break;
	case Keyboard::any: break;
	default: break;
	}
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
void PictureEditor::loadModule()
{

}

void PictureEditor::putInstruction(InstructionPosition instructionPosition)
{
	int x, y=1;
	switch (instructionPosition)
	{
	case left:
		x = 1;
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
	cursor.SetPosition();
	
}
