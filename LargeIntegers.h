#ifndef _LARGE_INTEGERS_H_
#define _LARGE_INTEGERS_H_

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class LargeIntegers
{
	private:
		// private helping methods
		string setNumber1();
		string setNumber2();
		void calcSum();
		void zeroFill(int, int);
	public:
		//	structor
		LargeIntegers();
		// destructor
		~LargeIntegers();
		
		// accessors

		// mutators
		
		// helping methods
		void run();
};
#endif
