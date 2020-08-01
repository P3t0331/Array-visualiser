//------------------------------------------------------------
//This program was modified with Compiler made by Peter Gregus.
//------------------------------------------------------------
#include <QDebug>
#include "arraywindow.h"
#include "stdio.h"
int mainProgram(arrayWindow *wnd)
{
	int i;
int cislapole[10];
char pismenapole[20];
float desatinne[5];

cislapole[5] = 2;
wnd->foundArray(new Pole(cislapole, 10, "cislapole"));
pismenapole[15] = 'x';
wnd->foundArray(new Pole(pismenapole, 20, "pismenapole"));
desatinne[1] = 2.5;
wnd->foundArray(new Pole(desatinne, 5, "desatinne"));
	for (i = 0; i < 5; i++)
	{
wnd->inputValue(new Input(desatinne, i));
wnd->foundArray(new Pole(desatinne, 5, "desatinne"));
	}
	for (i = 0; i < 10; i++)
	{
wnd->inputValue(new Input(cislapole, i));
wnd->foundArray(new Pole(cislapole, 10, "cislapole"));
	}
	
	
wnd->vystupEnd();
return 0;
}
