#include "File.h"
#include "conio2.h"
#include "Keyboard.h"
#include "stdio.h"
#include "stdlib.h"
#include "Workspace.h"
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
	//cputs("Podaj nazwe nowego pliku (max 32 znaki): ");
	char* fileName = Keyboard::Input("Podaj nazwê pliku: ");
	clrscr();
	//Tworzenie pliku
	return fileName;
}

Picture File::Read(char* fileName)
{
	FILE *file;
	if ((file = fopen(fileName, "r")) == NULL) {
		//cputs("Nie mogê otworzyæ pliku");
		Picture picture;
		picture.ok = false;
		return picture;
	}

	char tmp[32];
	fscanf(file, "%s", tmp);
	Picture picture;
	picture.name = tmp;
	fscanf(file, "%d %d", &picture.width, &picture.height);
	short **tmparray = new short*[picture.height];
	for (int i = 0; i < picture.height; ++i)
	{
		tmparray[i] = new short[picture.width];
	}
	for (int i = 0; i < picture.height; ++i)
	{
		for (int j = 0; j < picture.width; ++j)
		{

			fscanf(file, "%d", &tmparray[i][j]);
			//tmparray[i][j] = atoi(tmp);
			//char tmp[20];
			//itoa(picture[i][j], tmp, 10);
			//cputs(tmp);
		}
	}
	picture.content = tmparray;
	picture.ok = true;
	fclose(file);
	return picture;
}

int File::Save(Workspace* workspace)
{
	
	FILE* file;
	if ((file = fopen(workspace->name, "w")) == NULL) {
		//cputs("Nie mogê otworzyæ pliku");
		return 1;
	}

	char tmp[32];
	fprintf(file, "%s %d %d ", workspace->name, workspace->width, workspace->height);
	for (int i = 0; i < workspace->height; ++i)
	{
		for (int j = 0; j < workspace->width; ++j)
		{

			fprintf(file, "%d ", workspace->picture[i][j]);
			//tmparray[i][j] = atoi(tmp);
			//char tmp[20];
			//itoa(picture[i][j], tmp, 10);
			//cputs(tmp);
		}
	}

	fclose(file);
	return 0;
}


