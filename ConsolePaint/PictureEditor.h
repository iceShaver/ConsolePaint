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
	bool programRunning;
	void loadModule();
	void putInstruction(InstructionPosition);
	void printBoard();
	
};

