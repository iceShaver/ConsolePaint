#pragma once
#include "PictureEditor.h"

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
private:


public:
	int minX, minY, maxX, maxY, width, height, x0;
	short ** picture;
	char name[32];
	Workspace(int, char*, int, int);
	Workspace(int, Picture);
	Workspace();
	void DrawFrame();
	~Workspace();
	void draw();
	void UpdateArray(int position_x, int position_y);
};

