/***************************************************************************************************************************************************
Filename			: Frame.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 2
Due Date			: Dec 09 2017
Submission Date		: Dec 09 2017
Professor			: Andrew Tylor
Purpose				: concatenate two frames, and display them
****************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Display.h"
#include "Frame.h"

/***************************************************************************************************************************************************
Function name	: operator+
Purpose			: used to concatenate two frames, add their file names togther, and their displays
In parameters	: Frame f
Out parameters	: return new_Frame object
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
 Frame Frame ::operator+ (Frame& f) {
	
	 string  new_fileName = fileName + "_" + f.fileName; /*add file names together*/
	 vector <Display> frame_display =  displays;
	 vector <Display> old_display = f.displays;
	 vector <Display> new_display;
	
	 new_display.reserve(frame_display.size() + frame_display.size()); // preallocate memory
	 new_display.insert(new_display.end(), frame_display.begin(), frame_display.end()); /*insert old frame display to new one*/
	 new_display.insert(new_display.end(), old_display.begin(), old_display.end()); /* insert new display to new one*/
	
	 Frame new_Frame = Frame(new_fileName, new_display);/* constructs new frame object with the new fileName and the newDisplay*/
	 return new_Frame;	 
}
 /***************************************************************************************************************************************************
 Function name	: operator<<
 Purpose		: displays the fileName of the frame object, and its display
 In parameters	: ostream os, Frame f
 Out parameters	: return os
 Version		: 1.0
 Author			: Hasan Skaiky
 **************************************************************************************************************************************************/
 ostream& operator<<(ostream& os , Frame& f) {
	 int counter = 0;
	 os << "\tFile Name = " << f.fileName << endl;
	 vector<Display>::iterator it; /* to iterate through the Display vector*/
	
	 for (it = f.displays.begin(); it < f.displays.end(); it++) {
		 os << "\tDisplay #" << counter << ":\t";
		 counter++;
		 os << *it;
	 }
	 return os;
}