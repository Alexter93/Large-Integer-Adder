// PRJ02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LargeIntegers largeIntegers;
	largeIntegers.run();
	largeIntegers.~LargeIntegers();
	
	_getch();
	return 0;
}

