#pragma once


class Cursor
{
public:
	enum Direction{up, down, left, right};
	Cursor();

	~Cursor();
	static void MoveTo(int, int);
	static void Move(Direction);
	static void SetPosition();

private:
	static int positionX;
	static int positionY;

};


