#include "File.h"
#include "conio2.h"
#include "Keyboard.h"


File::File()
{
}


File::~File()
{
}

char* File::CreateNewFile()
{
	clrscr();
	gotoxy(0, 30);
	cputs("Podaj nazwe nowego pliku (max 32 znaki): ");
	char* fileName = Keyboard::input(32);
	clrscr();
	//Tworzenie pliku
	return fileName;
}