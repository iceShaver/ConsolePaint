#include "Keyboard.h"
#include "conio2.h"


Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{
}

Keyboard::Keys Keyboard::getKey()
{
	int key;
	key = getch();
	if (key == 13)
		return enter;
	if (key == 32)
		return space;
	if (key == 8)
		return backspace;
	if (key == 27)
		return ESC;

	if (key == 0)
	{
		key = getch();
		switch (key)
		{
		case 72:
			return upArrow;
			break;
		case 80:
			return downArrow;
			break;
		case 75:
			return leftArrow;
			break;
		case 77:
			return rightArrow;
			break;
		default:
			return any;
		}
	}
}

