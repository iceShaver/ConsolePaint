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

Picture File::Read(char* fileName)
{
	FILE *file;
	//If opening fail
	if ((file = fopen(fileName, "r")) == NULL) {
		Picture picture;
		picture.ok = false;
		return picture;
	}
	char tmp[Keyboard::MAX_FILENAME_LENGTH];
	fscanf(file, "%s", tmp);
	Picture picture;
	picture.name = tmp;
	fscanf(file, "%d %d", &picture.width, &picture.height);

	//Create two-dimensional array and read values from file
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
		return 1;
	}
	char tmp[32];
	fprintf(file, "%s %d %d ", workspace->name, workspace->width, workspace->height);
	for (int i = 0; i < workspace->height; ++i)
	{
		for (int j = 0; j < workspace->width; ++j)
		{
			fprintf(file, "%d ", workspace->picture[i][j]);
		}
	}
	fclose(file);
	return 0;
}


