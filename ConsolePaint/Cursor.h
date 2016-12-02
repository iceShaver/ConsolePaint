#pragma once


class Cursor
{
public:
	enum Direction { up, down, left, right };
	enum Color {black, blue, green, cyan, red, magenta, brown, lightgray, darkgray, lightblue, lightgreen, lightcyan ,lightred, lightmagenta, yellow, white};
	struct CursorPosition
	{
		int X, Y;
	};
	static Color color;

	Cursor(int, int, int, int);

	~Cursor();
	static void MoveTo(int, int);
	static void UpdatePosition();
	static void Move(Direction);
	static void SetPosition();
	static void SetColor(Color);
	static void SetDefault();
private:
	static int positionX;
	static int positionY;
	static int workspacePositionX;
	static int workspacePositionY;
	static int minX;
	static int minY;
	static int maxX;
	static int maxY;

};


