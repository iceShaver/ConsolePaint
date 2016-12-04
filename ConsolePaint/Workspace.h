#pragma once
#include "PictureEditor.h"
#include "Keyboard.h"

struct Picture
{
	char* name;
	int width;
	int height;
	short ** content;
	bool ok;
};

class Workspace
{
public:
	int minX, minY, maxX, maxY, width, height, x0;
	short ** picture;
	char name[Keyboard::MAX_FILENAME_LENGTH];
	Workspace(int, char*, int, int);
	Workspace(int, Picture);
	Workspace();
	~Workspace();
	void DrawFrame();
	void UpdateArray(int position_x, int position_y);
};

