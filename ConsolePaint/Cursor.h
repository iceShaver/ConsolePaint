#pragma once


class Cursor
{
public:
	Cursor();

	~Cursor();
	static void MoveTo(int, int);
	static void Move(int, int);
	static void SetPosition();

private:
	static int positionX;
	static int positionY;

};


