/***************************************************************************************************************************************************
Filename			: Animation.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 2
Due Date			: Dec 09 2017
Submission Date		: Dec 09 2017
Professor			: Andrew Tylor
Purpose				: insert frames in a forward list, deletes list from the animation, and display the list
****************************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS /* had to use it to reduce some errors*/
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "Animation.h"

/***************************************************************************************************************************************************
Function name	: insertFrame
Purpose			: The purpose of this function is to insert frames in the animation, then add the name of the frames to a forwardList, then allow the
user to add the frames at any position in the List.
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
***************************************************************************************************************************************************/
void Animation::InsertFrame() {
	string fileName;      /*arrayname*/
	char displayName[100]; /*displayName*/
	char* inputName; /* generates C4700 warning ( uninitialized local variable used) */
	int userInput, counter, pixelInputX, pixelInputY, duration, framePosition, x, i;

	vector <Display> new_Display;
	forward_list<Frame> ::iterator it = frames.begin();

	cout << "Insert a Frame in the Animation";
	cout << "Please enter the Frame fileName: ";
	cin >> fileName; /* get the fileName from the user*/

	cout << "\nEntering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays: ";
	cin >> userInput; /* get number of displays from user */

	counter = 0; /*display counter*/
	/* loops for number of displays and contents*/
	while (counter < userInput) {
		cout << "Please enter pixel x for Display #" << counter << " pixel_x:";
		cin >> pixelInputX;
		cout << "Please enter pixel y for Display #" << counter << " pixel_y:";
		cin >> pixelInputY;
		cout << "Please enter the duration sec for this display:";
		cin >> duration;
		cout << "Please enter the name of this display: ";
		cin >> displayName;

		inputName = new char [strlen (displayName) +1];
		strcpy(inputName, displayName);  /* copy name to displayName*/
		new_Display.push_back(Display(pixelInputX, pixelInputY, duration, inputName)); /* adds display contents to vector*/
		counter++;
	} 

	if (frames.empty()) { /* checks if forward list is empty*/
		cout << "This is the first frame in the List\n" << endl;
		Frame new_Frame = Frame(fileName, new_Display);
		frames.push_front(new_Frame); /* add new frame to the list*/
	
	} else {
		x = 0;	
		while (it != frames.end()) { /* counts how many frames in the list*/
			++it;
			x++;
		}
		if (x <= 1) {
		it = frames.begin(); /* restes iterator*/
		Frame new_Frame = Frame(fileName, new_Display);
		frames.insert_after(it, new_Frame); /* adds 2nd object*/
		}
		else {
			cout << "There are " << x << " Frame(s) in the list" << endl;
			cout << "Please specify the position, between 0 and " << x-1 << " to insert after : "; /* get position from user*/
			cin >> framePosition;
			
			if (framePosition > x || framePosition < 0) { /* checks for boundaries*/
				return;
			}
			it = frames.begin();

			for (i = 0; i < framePosition; i++) { /* counters frames in list*/
				++it;
			}
			if (x == framePosition) { /* insert frame at specified position*/
				it = frames.begin();
				Frame new_Frame = Frame(fileName, new_Display);
				frames.insert_after(it, new_Frame);
			}
			else {
				Frame new_Frame = Frame(fileName, new_Display); /* insert frame after specified position*/
				frames.insert_after(it, new_Frame);
				it = frames.begin();
			}
		}
	} 
}
/***************************************************************************************************************************************************
Function name	: DeleteFrames
Purpose			: This method will delete all the frames in the list when it is called , then free the space of the memory
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
***************************************************************************************************************************************************/
void Animation::DeleteFrames() {
	
	if (frames.empty()) { /* checks if list is empty*/
		cout << "There's no frames in the Animation\n" << endl;
	} else {
		frames.clear(); /* delete all frames*/
		cout << "Frames are deleted" << endl;
	}
}
/***************************************************************************************************************************************************
Function name : operator[]
Purpose		  : gets the frame at the specified index
In parameters : int i 
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
Frame& Animation:: operator[](unsigned int i ) { 
	
	forward_list<Frame>::iterator it = frames.begin();
	unsigned int counter = 0;
	
	while (it != frames.end()) {	/*iterates through list and get index*/
		if (counter == i) {
			return *it;
		}
		++it;
		counter++;	
	}
	return *it; /* checks return value ( used to get rid of some errors)*/
}
/***************************************************************************************************************************************************
Function name : operator+=
Purpose		  : concatenate two frames , and add them at head of the list
In parameters : Frame f
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
void Animation:: operator+=(Frame& f) {
	if (frames.empty()) {
		cout << "There's no frames to concatenate" << endl;
	}
	 frames.push_front(f); /* adds at head*/
}
/***************************************************************************************************************************************************
Function name : operator<<
Purpose		  : displays the animation
In parameters : ostream os , Animation a
Out parameters: return os
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
ostream& operator<<(ostream& os, Animation& a) {
	forward_list<Frame>::iterator it;
	int counter = 0; 
	
	if (a.frames.empty()) { /* checks if list is empty*/
		cout << "Animation is empty" << endl;
		return os;
	}
	os << "Animation A\n"<< "Run the Animation" << endl;
	for (it = a.frames.begin(); it != a.frames.end(); it++) { /* loops through the list and print the frames*/
		os << "Frame #" << counter <<":" << endl;
		counter++;
		os << *it << endl;
	}
	os << "Output finished" << endl;
	return os;
}