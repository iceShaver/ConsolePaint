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
	if (key == 0x71 || key == 0x51)
		return q;
	if (key == 0x77 || key == 0x57)
		return w;
	if (key == 0x65 || key == 0x45)
		return e;
	if (key == 0x72 || key == 0x52)
		return r;
	if (key == 0x74 || key == 0x54)
		return t;
	if (key == 0x79 || key == 0x59)
		return y;
	if (key == 0x69 || key == 0x49)
		return i;
	if (key == 0x6f || key == 0x4f)
		return o;
	if (key == 0x70 || key == 0x50)
		return p;
	if (key == 0x6e || key == 0x4e)
		return n;
	if (key == 0x73 || key == 0x53)
		return s;
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
		case 152:
			return ctrlUpArrow;
		case 160:
			return ctrlDownArrow;
		case 115:
			return ctrlLeftArrow;
		case 116:
			return ctrlRightArrow;
		default:
			return any;
		}
	default:
		return any;
	}
}

char Keyboard::getChar()
{
	char character;
	while (true) {
		character = getch();
		if (character == 13)
			return '\0';
		if (character == 0)
			while (kbhit())
				getch();
		else if ((character >= 0x30 && character <= 0x39) ||
			(character >= 0x61 && character <= 0x7a) ||
			(character >= 0x41 && character <= 0x5a))
			return character;
	}


}

char* Keyboard::input(int maxLength)
{
	char character;
	int position = wherex();
	char* fileName = new char[maxLength+1];
	int i = 0;
	while (true)
	{
		if (i >= maxLength)
		{
		
		}
		else {
			character = Keyboard::getChar();
			fileName[i] = character;
			if (character == '\0')
				break;
			putch(character);

			i++;
		}

	}
	return fileName;
}
