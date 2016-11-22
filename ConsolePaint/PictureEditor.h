#pragma once

class PictureEditor
{
public:
	static const int windowWidth;
	static const int windowHeight;
	PictureEditor();
	~PictureEditor();
	enum InstructionPosition {left,right};
	void DrawInterface();
	bool GetProgramState();
	void Tasker();
private:
	InstructionPosition instructionPosition;
	bool programRunning;

	void loadModule();
	void drawInstruction();
	void printBoard();
	void drawWorkspace();
	
	
};

