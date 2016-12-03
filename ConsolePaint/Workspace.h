#pragma once
#include "PictureEditor.h"

class Workspace
{
private:
	int minX, minY, maxX, maxY, width, height;
	short ** picture;
public:
	char* name;
	Workspace(int, char*, int, int);
	~Workspace();
	void draw();

};

