#include "PictureEditor.h"
#include <cstdio>
#include "conio2.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Workspace.h"
#include "File.h"
#include <stdlib.h>

int PictureEditor::windowHeight;
int PictureEditor::windowWidth;
int PictureEditor::instructionWidth;
int PictureEditor::instructionX0Position;
bool PictureEditor::workspaceInitialized;
Workspace* workspace;

void PictureEditor::Tasker()
{
	while (programRunning) {
		//Cursor::SetDefault();
		switch (Keyboard::getKey())
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
			break;
		case Keyboard::space:
			Cursor::Toggle();
			break;
		case Keyboard::backspace: break;
		case Keyboard::enter: break;
		case Keyboard::n:
		{
			//delete workspace;
			/*if (workspaceInitialized) {
				delete workspace;
			}*/
			workspace = new Workspace(workpaceX0Position,
				Keyboard::Input("Podaj nazwe: "),
				Keyboard::InputNumber("Podaj szerokosc: "),
				Keyboard::InputNumber("Podaj wysokosc: "));
			workspaceInitialized = true;
			DrawInstruction();
			Cursor::SetPosition();
			break;
		}
		case Keyboard::ESC:
			programRunning = false;
			break;
		case Keyboard::any:
			break;
		case Keyboard::n1:
			Cursor::SetColor(Cursor::black);
			break;
		case Keyboard::n2:
			Cursor::SetColor(Cursor::blue);
			break;
		case Keyboard::n3:
			Cursor::SetColor(Cursor::green);
			break;
		case Keyboard::n4:
			Cursor::SetColor(Cursor::cyan);
			break;
		case Keyboard::n5:
			Cursor::SetColor(Cursor::red);
			break;
		case Keyboard::n6:
			Cursor::SetColor(Cursor::magenta);
			break;
		case Keyboard::n7:
			Cursor::SetColor(Cursor::brown);
			break;
		case Keyboard::n8:
			Cursor::SetColor(Cursor::lightgray);
			break;
		case Keyboard::n9:
			Cursor::SetColor(Cursor::darkgray);
			break;
		case Keyboard::n0:
			Cursor::SetColor(Cursor::lightblue);
			break;
		case Keyboard::q:
			Cursor::SetColor(Cursor::lightgreen);
			break;
		case Keyboard::w:
			Cursor::SetColor(Cursor::lightcyan);
			break;
		case Keyboard::e:
			Cursor::SetColor(Cursor::lightred);
			break;
		case Keyboard::r:
			Cursor::SetColor(Cursor::lightmagenta);
			break;
		case Keyboard::t:
			Cursor::SetColor(Cursor::yellow);
			break;
		case Keyboard::y:
			Cursor::SetColor(Cursor::white);
			break;
		case Keyboard::i: {
			//if (workspaceInitialized) {
			//	delete workspace;
			//}
			workspace = new Workspace(workpaceX0Position, File::Read("obrazek.txt"));
			workspaceInitialized = true;
			DrawInstruction();
			Cursor::SetPosition();
			break;
		}
		case Keyboard::o:
			//if (workspaceInitialized) {
			//	delete workspace;
			//}
			workspaceInitialized = true;
			workspace = new Workspace(workpaceX0Position, File::Read(Keyboard::Input("Podaj nazwe pliku do odczytania: ")));

			DrawInstruction();
			Cursor::SetPosition();
			break;

		case Keyboard::s:
			if (workspaceInitialized)
				File::Save(this->workspace);
			break;
		default:
			break;
		}
	}
}

PictureEditor::PictureEditor()
{
	workspaceInitialized = false;
	//textmode(C4350);
	textcolor(WHITE);
	windowWidth = 120;
	windowHeight = 30;
	instructionWidth = 44;
	layout = instructionLeft;
	programRunning = true;
	switch (layout)
	{
	case instructionLeft:
		workpaceX0Position = instructionWidth + 2;
		instructionX0Position = 1;
		break;
	case instructionRight:
		workpaceX0Position = 1;
		instructionX0Position = windowWidth - instructionWidth;
		break;
	default:
		workpaceX0Position = instructionWidth + 1;
		break;
	}
	DrawInstruction();
	Tasker();
}

void PictureEditor::DrawInstruction()
{

	int x, y = 1;
	switch (layout)
	{
	case instructionLeft:
		x = 1;
		for (int i = 0; i < windowHeight; ++i)
		{
			gotoxy(x + instructionWidth, y + i);
			putch(186);
		}
		break;
	case instructionRight:
		x = windowWidth - instructionWidth;
		for (int i = 0; i < windowHeight; ++i)
		{
			gotoxy(x - 1, y + i);
			putch(186);
		}
		break;
	default:
		x = 1;
		break;
	}

	gotoxy(x, y);
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
	textbackground(BLACK);
	cputs("1");
	textbackground(BLUE);
	cputs("2");
	textbackground(GREEN);
	cputs("3");
	textbackground(CYAN);
	cputs("4");
	textbackground(RED);
	cputs("5");
	textbackground(MAGENTA);
	cputs("6");
	textbackground(BROWN);
	cputs("7");
	textbackground(LIGHTGRAY);
	cputs("8");
	textbackground(DARKGRAY);
	cputs("9");
	textbackground(LIGHTBLUE);
	cputs("0");
	textbackground(LIGHTGREEN);
	cputs("q");
	textbackground(LIGHTCYAN);
	cputs("w");
	textbackground(LIGHTRED);
	cputs("e");
	textbackground(LIGHTMAGENTA);
	cputs("r");
	textcolor(BLACK);
	textbackground(YELLOW);
	cputs("t");
	textbackground(WHITE);
	cputs("y");
	gotoxy(x, ++y);
	textbackground(BLACK);
	textcolor(WHITE);
	cputs("1234567890qwerty - wybor koloru");

	gotoxy(x, ++y);
	cputs("backspace - cofnij");

	//Cursor::SetPosition();

}


