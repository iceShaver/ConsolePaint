#pragma once

class PictureEditor
{
public:
	enum Position {left, right};
	static const int windowWidth;
	static const int windowHeight;
	PictureEditor();
	~PictureEditor();

	void DrawInterface();
	bool GetProgramState();
	void Tasker();
private:
	bool programRunning;

	void loadModule();
	void drawInstruction(PictureEditor::Position position);
	
	
};

