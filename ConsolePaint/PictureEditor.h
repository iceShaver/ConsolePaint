#pragma once
#include "Workspace.h"

class PictureEditor
{
public:
	enum Position {instructionLeft, instructionRight};
	const static int WINDOW_WIDTH = 120;
	const static int WINDOW_HEIGHT = 30;
	const static int INSTRUCTION_WIDTH = 44;
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
	
	
};

