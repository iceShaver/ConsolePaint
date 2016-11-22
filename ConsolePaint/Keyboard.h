#pragma once
class Keyboard
{
public:
	enum Keys{leftArrow, rightArrow, upArrow, downArrow, space, backspace, enter, ESC, any};
	Keyboard();
	~Keyboard();
	static Keys getKey();
};

