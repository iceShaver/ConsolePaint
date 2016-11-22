#pragma once

class PictureEditor
{
public:
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
	void putInstruction();
	void printBoard();
	
};

