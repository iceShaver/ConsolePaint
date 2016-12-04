#include "PictureEditor.h"
#include <cstdio>
#include "conio2.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Workspace.h"
#include "File.h"
#include <stdlib.h>

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
			workspaceInitialized = true;

			workspace = new Workspace(workpaceX0Position, File::Read("obrazek.txt"));
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
	layout = instructionLeft;
	workspaceInitialized = false;
	//textmode(C4350);
	textcolor(WHITE);
	programRunning = true;
	switch (layout)
	{
	case instructionLeft:
		workpaceX0Position = INSTRUCTION_WIDTH + 2;
		instructionX0Position = 1;
		break;
	case instructionRight:
		workpaceX0Position = 1;
		instructionX0Position = WINDOW_WIDTH - INSTRUCTION_WIDTH;
		break;
	default:
		workpaceX0Position = INSTRUCTION_WIDTH + 1;
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
		for (int i = 0; i < WINDOW_HEIGHT; ++i)
		{
			gotoxy(x + INSTRUCTION_WIDTH, y + i);
			putch(186);
		}
		break;
	case instructionRight:
		x = WINDOW_WIDTH - INSTRUCTION_WIDTH;
		for (int i = 0; i < WINDOW_HEIGHT; ++i)
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
	if (!workspaceInitialized)
		textcolor(DARKGRAY);
	cputs("Strzalki - poruszanie");
	textcolor(WHITE);
	gotoxy(x, ++y);
	cputs("ESC - wyjscie");
	gotoxy(x, ++y);
	cputs("i - wczytaj obrazek domyslny");
	gotoxy(x, ++y);
	cputs("o - wczytaj podany plik");
	gotoxy(x, ++y);
	cputs("n - nowy");
	if (!workspaceInitialized)
		textcolor(DARKGRAY);
	gotoxy(x, ++y);
	cputs("s - zapisz");
	textcolor(WHITE);
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
	textcolor(BLACK);
	cputs("8");
	textcolor(WHITE);
	textbackground(DARKGRAY);
	cputs("9");
	textbackground(LIGHTBLUE);
	cputs("0");
	textbackground(LIGHTGREEN);
	textcolor(BLACK);
	cputs("q");
	textbackground(LIGHTCYAN);
	cputs("w");
	textbackground(LIGHTRED);
	cputs("e");
	textbackground(LIGHTMAGENTA);
	cputs("r");
	textbackground(YELLOW);
	cputs("t");
	textbackground(WHITE);
	cputs("y");
	textbackground(BLACK);
	textcolor(WHITE);
	cputs(" - wybor koloru");
}


