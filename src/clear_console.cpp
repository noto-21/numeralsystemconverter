/* clear_console.cpp */
#include "clear_console.h"
#include <iostream>

void clearConsole()
{
#ifdef _WIN32//Windows
    system("cls");
#else//Unix-based
    system("clear");
#endif
}
