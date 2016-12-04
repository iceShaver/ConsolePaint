#pragma once
#include "Workspace.h"

class PictureEditor
{
public:
	enum Position {instructionLeft, instructionRight};
	static int windowWidth;
	static int windowHeight;
	static int instructionWidth;
	static int instructionX0Position;
	class Workspace* workspace;
	static bool workspaceInitialized;
	PictureEditor();
	void DrawInstruction();
	void Tasker();
private:

	int workpaceX0Position;
	Position layout;
	bool programRunning;

	//void loadModule();
	
	
};

