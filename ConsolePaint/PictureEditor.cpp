#include "PictureEditor.h"
#include <cstdio>
#include "conio2.h"
#include "Keyboard.h"
#include "Cursor.h"
#include "Workspace.h"
#include "File.h"





void PictureEditor::Tasker()
{
while(programRunning)
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
	case Keyboard::space: break;
	case Keyboard::backspace: break;
	case Keyboard::enter: break;
	case Keyboard::n:
	{
		Workspace workspace(workpaceX0Position,
			Keyboard::Input("Podaj nazwe: "),
			Keyboard::InputNumber("Podaj szerokosc: "),
			Keyboard::InputNumber("Podaj wysokosc: "));
		DrawInstruction();
		Cursor::SetPosition();
		break;
	}
	case Keyboard::ESC:
		PictureEditor::programRunning = false;
		break;
	case Keyboard::any: 
		
		break;
	case Keyboard::n1:
		textcolor(BLACK);
		textbackground(BLACK);
		break;
	case Keyboard::n2:
		textcolor(BLUE);
		textbackground(BLUE);
		break;
	case Keyboard::n3:
		textcolor(GREEN);
		textbackground(GREEN);
		break;
	case Keyboard::n4:
		textcolor(CYAN);
		textbackground(CYAN);
		break;
	case Keyboard::n5:
		textcolor(RED);
		textbackground(RED);
		break;
	case Keyboard::n6:
		textcolor(MAGENTA);
		textbackground(MAGENTA);
		break;
	case Keyboard::n7:
		textcolor(BROWN);
		textbackground(BROWN);
		break;
	case Keyboard::n8:
		textcolor(LIGHTGRAY);
		textbackground(LIGHTGRAY);
		break;
	case Keyboard::n9:
		textcolor(LIGHTBLUE);
		textbackground(LIGHTBLUE);
		break;
	case Keyboard::n0:
		textcolor(LIGHTGREEN);
		textbackground(LIGHTGREEN);
		break;
	case Keyboard::q:
		textcolor(LIGHTCYAN);
		textbackground(LIGHTCYAN);
		break;
	case Keyboard::w:
		textcolor(LIGHTRED);
		textbackground(LIGHTRED);
		break;
	case Keyboard::e:
		textcolor(LIGHTMAGENTA);
		textbackground(LIGHTMAGENTA);
		break;
	case Keyboard::r:
		textcolor(YELLOW);
		textbackground(YELLOW);
		break;
	case Keyboard::t:
		textcolor(WHITE);
		textbackground(WHITE);
		break;


	default:
		
		break;
	}
}


PictureEditor::PictureEditor()
{
	//textmode(C4350);
	windowWidth = 80;
	windowHeight = 30;
	instructionWidth = 44;
	layout = instructionLeft;
	programRunning = true;
	switch (layout)
	{
	case instructionLeft:
		workpaceX0Position = instructionWidth + 2;
		break;
	case instructionRight:
		workpaceX0Position = 1;
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
		x = instructionWidth + 1;
		for (int i = 0; i <= 28; ++i)
		{
			gotoxy(x, y + i);
			cputs("\186");
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
	//Cursor::SetPosition();

}


