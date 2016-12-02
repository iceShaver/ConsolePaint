#pragma once

class PictureEditor
{
public:
	enum Position {instructionLeft, instructionRight};
	static int windowWidth;
	static int windowHeight;
	PictureEditor();
	void DrawInstruction();
	void Tasker();
private:

	int instructionWidth;
	int workpaceX0Position;
	Position layout;
	bool programRunning;

	//void loadModule();
	
	
};

