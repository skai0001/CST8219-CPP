/***************************************************************************************************************************************************
Filename			: Display.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 2
Due Date			: Dec 09 2017
Submission Date		: Dec 09 2017
Professor			: Andrew Tylor
Purpose				: Constructs a vector Display , deconstruct it , and display it 
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
Purpose			: Copy constructor , used to copy attributes  in a deep copy instead of shallow copy, because of the name array
In parameters	: Display d
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
Display:: Display(const Display& d) { 
	pixel_x = d.pixel_x;
	pixel_y = d.pixel_y;
	duration = d.duration;
	name = new char[strlen(d.name)+1];
	strcpy(name, d.name);
}
/***************************************************************************************************************************************************
Function name	: ~Display
Purpose			: Deconstructor used to delete the attributes of an object
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
Display::~Display() {
	delete name;
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
	
	os << "name = " << d.name << "; pixel_x = " << d.pixel_x << ";" << " pixel_y = " << d.pixel_y << "; duration = " << d.duration << endl;
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
	os << endl;
	return os;
}