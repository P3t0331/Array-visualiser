//------------------------------------------------------------
//This program was modified with Compiler made by Peter Gregus.
//------------------------------------------------------------
#include <QDebug>
#include "arraywindow.h"
#include "stdio.h"
int mainProgram(arrayWindow *wnd)
{
	int i;
int numarray[10];
char chararray[20];
float floatarray[5];

numarray[5] = 2;
wnd->foundArray(new ArrayClass(numarray, 10, "numarray"));
chararray[15] = 'x';
wnd->foundArray(new ArrayClass(chararray, 20, "chararray"));
floatarray[1] = 2.5;
wnd->foundArray(new ArrayClass(floatarray, 5, "floatarray"));
	for (i = 0; i < 5; i++)
	{
wnd->inputValue(new Input(floatarray, i));
wnd->foundArray(new ArrayClass(floatarray, 5, "floatarray"));
	}
	for (i = 0; i < 10; i++)
	{
wnd->inputValue(new Input(numarray, i));
wnd->foundArray(new ArrayClass(numarray, 10, "numarray"));
	}
	
	
wnd->outputEnd();
return 0;
}
