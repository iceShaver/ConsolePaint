#pragma once
class Cursor
{
public:
	Cursor();
	~Cursor();
	void MoveTo(int, int);
	void Move(int, int);
	void SetPosition();
private:
	int positionX;
	int positionY;
};

