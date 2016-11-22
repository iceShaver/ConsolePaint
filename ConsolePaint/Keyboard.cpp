#include "Keyboard.h"
#include "conio2.h"


Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{
}

Keyboard::Key Keyboard::getKey()
{
	int key;
	key = getch();
	switch (key)
	{
	case 8:
		return backspace;
	case 13:
		return enter;
	case 27:
		return ESC;
	case 32:
		return space;
	case 0:
		key = getch();
		switch (key)
		{
		case 72:
			return upArrow;
		case 80:
			return downArrow;
		case 75:
			return leftArrow;
		case 77:
			return rightArrow;
		default:
			return any;
		}
	default:
		return any;
	}
}

