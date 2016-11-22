#pragma once
class Keyboard
{
public:
	enum Key{leftArrow, rightArrow, upArrow, downArrow, space, backspace, enter, ESC, any};
	Keyboard();
	~Keyboard();
	static Key getKey();
};

