#pragma once

class PictureEditor
{
public:
	enum Position {instructionLeft, instructionRight};
	static int windowWidth;
	static int windowHeight;
	static int instructionWidth;
	static int instructionX0Position;
	PictureEditor();
	void DrawInstruction();
	void Tasker();
private:

	int workpaceX0Position;
	Position layout;
	bool programRunning;

	//void loadModule();
	
	
};

