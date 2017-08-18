#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string sInput1 = "";
string sInput2 = "";

// private helping methods
string LargeIntegers::setNumber1() //later be a string returning function
{
	cout << "Enter an intiger with any number of digits: ";
	cin >> sInput1;
	
	return sInput1;
}
string LargeIntegers::setNumber2()
{
	cout << "Enter another intiger with any number of digits: ";
	cin >> sInput2;
	
	return sInput2;
}
void LargeIntegers::calcSum()
{
	string temp1 = "";
	string temp2 = "";
	int tempNumber1 = 0;
	int tempNumber2 = 0;
	int tempSum = 0;
	int tempRemain = 0;
	int count = 0;

	cout << endl << "First Number: " << sInput1 << endl;
	cout << "Its Length:" << sInput1.length() << endl;

	cout << endl << "Second Number:" << sInput2 << endl;
	cout << "Its Length:" << sInput2.length() << endl;

	cout << endl << "SUM: ";

	zeroFill(sInput1.length(), sInput2.length());

	int sumArray[100];

	for (int i=0; i<sInput1.length(); i++)
	{
		temp1 = sInput1.at(i);
		temp2 = sInput2.at(i);

		tempNumber1 = atoi(temp1.c_str());
		tempNumber2 = atoi(temp2.c_str());

		sumArray[i] = 0; // instatiate each area of sumArray 1st before modifing it

		if (i == 0)
		{
			tempSum = tempNumber1 + tempNumber2;
			sumArray[i] += tempSum;
		}
		else
		{
			tempSum = tempNumber1 + tempNumber2 + tempRemain;
			if (tempSum > 9)
			{
				sumArray[i] += tempSum%10;
				sumArray[i - 1] += tempSum/10;
			}
			else
			{
				sumArray[i] += tempSum;
			}
		}
		count++;
	}
	for (int i=1; i<count; i++)	//checks for posts in sumArray that are too big (i=1 because the 1st spot can be 2 int long)
	{
		if (sumArray[i] > 9)
		{
			bool fOkay = false;
			int resend = 0;
			do
			{
				tempSum = sumArray[i - resend];
				sumArray[i - resend] = tempSum%10;
				resend++;
				sumArray[i - resend] += tempSum/10;
				if (sumArray[i - resend-1] < 10 && sumArray[i - resend] < 10)
				{
					fOkay = true;
				}
			}
			while (fOkay = false);
		}
	}

	for (int i=0; i<count; i++) //displays
	{
		cout << sumArray[i];
	}
}

// testing results:
/*			with if statement in 1st go		without in 1st go		with 10+ catch		10+ catch tweeked		10+ catch corrected
 6854641						6854641			 	  6854641		   	   6854641		  		  6854641					6854641
+5646546					   +5646546			 	 +5646546			  +5646546				 +5646546				   +5646546
--------					   --------			 	 --------			  --------				 --------				   --------
12501187					   24101187			    124101187			  12401187				 12402187				   12501187
  (goal)					   (phase1)				 (phase2)			  (phase3)			   (phase3.5)				(finished?) <-- YES!!
*/

void LargeIntegers::zeroFill(int length1, int length2)
{
	int digitFill = 0;
	string tempString = "";
	
	if (length1 > length2)
	{
		digitFill = length1 - length2;
		for (int i=0; i<digitFill; i++)
		{
			tempString += "0";
		}
		tempString += sInput2;
		sInput2 = tempString;
	}
	else
	{
		if (length1 != length2)
		{
			digitFill = length2 - length1;
			for (int i=0; i<digitFill; i++)
			{
				tempString += "0";
			}
			tempString += sInput1;
			sInput1 = tempString;
	
		}
	}
}

// public
// custructor
LargeIntegers::LargeIntegers()
{
}
// destructor
LargeIntegers::~LargeIntegers()
{
}
		
// save for LargeIntegers.cpp
/*
// destructor
LargeIntegers::~LargeIntegers()
{
	cout << "inside the destructor" << endl;
	_getch();
}
*/
// accessors

// mutators
		
// helping methods
void LargeIntegers::run()
{
	setNumber1();
	setNumber2();
	calcSum();
}

/*
	string str = "aardvark";
	string temp = "";
	int tempNumber = 0;

	cout << str << endl;	// display string
	cout << str.length() << endl;	// display string length

	for (int i=0; i<str.length(); i++)
	{
		cout << str.at(i) << endl;	// display 1 character string each time
		temp = str.at(i);
		tempNumber = atoi(temp.c_str());	//convert to old c string to integer
		cout << temp << endl;	// display 1 character string each time
	}

	_getch();
	return 0;
	*/

//------------------------------------------------------------------------

	/*
	int num1 = 15;
	int left;
	int right;

	left = num1/10;		// <-- 10's spot
	right = num1%10;	// <-- 1's spot

	cout << num1 << endl;
	cout << left << endl;
	cout << right << endl;

	int intArray[10];
	for (int i=0; i<10; i++)
	{
		cout << intArray[i] << endl;
	}
	*/