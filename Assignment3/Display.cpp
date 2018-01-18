/***************************************************************************************************************************************************
Filename			: Display.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 3
Due Date			: Jan 06 2018
Submission Date		: Jan 06 2018
Professor			: Andrew Tylor
Purpose				: Constructs a vector Display pointer &display it
****************************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#include "Display.h"

/***************************************************************************************************************************************************
Function name	: Display
Purpose			: constructor a vector with foru attributes
In parameters	: int x , int y, int d, char* n
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
Display::Display(int x, int y, int d, char* n) {
	pixel_x = x;
	pixel_y = y;
	duration = d;
	name = n;
}
/***************************************************************************************************************************************************
Function name	: Display
Purpose			: Copy constructor , used to copy attributes in a deep copy
In parameters	: Display d
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
Display::Display(const Display& d) {
	pixel_x = d.pixel_x;
	pixel_y = d.pixel_y;
	duration = d.duration;
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
}
/***************************************************************************************************************************************************
Function name	: operator<<
Purpose			: The purpose of this function is to display the Display vector attributes and counts the seconds for the duration specified
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
ostream& operator<<(ostream& os, Display& d) {
	time_t startsec, oldsec, newsec;
	startsec = oldsec = time(NULL);
	newsec = time(NULL);
	int counter = 1;

	os << "\tDisplay name = " << d.name << "; pixel_x = " << d.pixel_x << ";" << " pixel_y = " << d.pixel_y << "; duration = " << d.duration << endl;
	cout << "\tCounting the seconds for this Display: ";
	while (counter <= d.duration)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			os << " " << counter++ << ", ";
			oldsec = newsec;
		}
	}
	os << "\n\tMemory requirements = " << d.BufferSize() << " bytes" << endl;/*calls Buffersize funtion and prints number of bytes*/
	return os;
}