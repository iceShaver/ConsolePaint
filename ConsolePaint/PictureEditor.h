#pragma once

class PictureEditor
{
public:
	enum Position {instructionLeft, instructionRight};

	PictureEditor();
	void DrawInstruction();
	void Tasker();
private:
	int windowWidth;
	int windowHeight;
	int instructionWidth;
	int workpaceX0Position;
	Position layout;
	bool programRunning;

	//void loadModule();
	
	
};

