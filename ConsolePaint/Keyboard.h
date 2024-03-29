#pragma once
class Keyboard
{
private:
	static const char ENTER = 13;
	static const char BACKSPACE = 8;

public:
	enum InputType{string, number};
	enum Key {
		leftArrow, rightArrow, upArrow, downArrow,
		ctrlLeftArrow, ctrlRightArrow, ctrlUpArrow, ctrlDownArrow,
		altLeftArrow, altRightArrow, altUpArrow, altDownArrow,
		space, backspace, enter, ESC, any,
		n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, q, w, e, r, t, y,
		i, o, n, s, l, k, c, p, f
	};
	static const short MAX_FILENAME_LENGTH = 32;
	Keyboard();
	~Keyboard();
	static Key getKey();
	static char getChar();
	static char* Input(char*);
	static int InputNumber(char*);
};

