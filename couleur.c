#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color( int a , int b)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);       ///fonction de la couleur
    SetConsoleTextAttribute(H,a*16+b);
}
