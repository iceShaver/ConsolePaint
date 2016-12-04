#pragma once
#include "PictureEditor.h"

struct Picture
{
	char* name;
	int width;
	int height;
	short ** content;
};

class Workspace
{
private:
	int minX, minY, maxX, maxY, width, height, x0;
	short ** picture;
public:
	const char* name;
	Workspace(int, char*, int, int);
	Workspace(int, Picture);
	void DrawFrame();
	~Workspace();
	void draw();

};

