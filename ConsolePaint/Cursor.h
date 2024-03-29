#pragma once


class Workspace;

class Cursor
{
public:
	enum Direction { up, down, left, right };
	enum Color {black, blue, green, cyan, red, magenta, brown, lightgray, darkgray, lightblue, lightgreen, lightcyan ,lightred, lightmagenta, yellow, white};
	static Color color;
	Cursor(Workspace*, int, int, int, int);
	~Cursor();
	static void Toggle();
	static void UpdatePosition();
	static void Move(Direction);
	static void SetPosition();
	static void SetColor(Color);
	static void SetDefault();
private:
	static const char PIXEL = 219;
	static const int DECIMAL_SYSTEM = 10;
	static int positionX;
	static int positionY;
	static int workspacePositionX;
	static int workspacePositionY;
	static int minX;
	static int minY;
	static int maxX;
	static int maxY;
	static bool isDrawing;
	static class Workspace* w;

};


