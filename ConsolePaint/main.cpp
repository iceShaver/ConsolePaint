#include <stdlib.h>
#include "conio2.h"
#include "console.cpp"
#include "PictureEditor.h"
#include "Cursor.h"
#include "Keyboard.h"
/* Uwaga: w docelowym programie nalezy zadeklarowac odpowiednie
stale, na przyklad po to, aby wyeliminowac z programu
wartosci numeryczne umieszczajac w ich miejsce
dobrze dobrane identyfikatory */
Cursor cursor;
int main()
{
	PictureEditor pictureEditor;

	do
	{
		pictureEditor.DrawInterface();
		pictureEditor.Tasker();
		
	}
	while (pictureEditor.GetProgramState());



	return 0;
}
