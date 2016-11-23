#pragma once
#include "PictureEditor.h"

class Workspace
{
public:
	char* name;
	Workspace(char*, PictureEditor::Position);
	~Workspace();
	void draw();
	static int width;
	static int height;
};

