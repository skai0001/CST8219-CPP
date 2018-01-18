/***************************************************************************************************************************************************
Filename			: Animation.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 3
Due Date			: Jan 06 2018
Submission Date		: Jan 06 2018
Professor			: Andrew Tylor
Purpose				: insert frames in a forward list, deletes list from the animation, and display the list using Polymorphism & Inheritance
****************************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS /* had to use it to reduce some errors*/
#include <iostream>
#include <forward_list>
#include <vector>
#include <string>

using namespace std;

#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
#include "Frame.h"
#include "Animation.h"

/***************************************************************************************************************************************************
Function name	: insertFrame
Purpose			: The purpose of this function is to insert frames in the animation, add the name of the frames to a forwardList, add a type of inherited
object display to the frame , then allow the user to add the frames at any position in the List.
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
***************************************************************************************************************************************************/
void Animation::InsertFrame() {
	string fileName;      /*fiLeName*/
	char displayName[100]; /*displayName*/
	char shaderName[100]; /*shaderName*/
	char* inputName; /* generates C4700 warning ( uninitialized local variable used) */
	int userInput, counter, pixelInputX, pixelInputY, duration, framePosition, displayType, x, i;

	vector <Display*> new_Display; /*temporary vector of pointers*/
	forward_list<Frame> ::iterator it = frames.begin();

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame fileName: ";
	cin >> fileName; /* get the fileName from the user*/

	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays: ";
	cin >> userInput; /* get number of displays from user */

	counter = 0; /*display counter*/
				 /* loops for number of displays and contents*/
	while (counter < userInput) {
		cout << "Please enter pixel x-width for Display #" << counter << " pixel_x:";
		cin >> pixelInputX;
		cout << "Please enter pixel y-width for Display #" << counter << " pixel_y:";
		cin >> pixelInputY;
		cout << "Please enter the duration for this display:";
		cin >> duration;
		cout << "Please enter the name of this display: ";
		cin >> displayName;
		cout << "Please enter the type for this display (1 = SystemMemoryDisplay, 2 = GPUMemoryDisplay) : ";
		cin >> displayType;

		inputName = new char[strlen(displayName) + 1];
		strcpy(inputName, displayName);  /* copy name to displayName*/

		if (displayType == 1) {	/*checks for valid option*/
			new_Display.push_back(new SystemMemoryDisplay(pixelInputX, pixelInputY, duration, inputName));	/*adds new vector display to the temp one*/
		}
		else if (displayType == 2) {/*checks for valid option*/
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> shaderName;
			new_Display.push_back(new GPUMemoryDisplay(pixelInputX, pixelInputY, duration, inputName, shaderName));/*adds new vector display to the temp one*/
		}
		else {
			cout << "Please choose valid option 1 or 2" << endl;
			return;
		}
		counter++;
	}
	Frame *new_Frame = new Frame(fileName, new_Display); /*declare& intsantiate newFrame object*/
	if (frames.empty()) { /* checks if forward list is empty*/
		cout << "This is the first frame in the List\n" << endl;
		frames.push_front(*new_Frame);
	}
	else {
		x = 0;
		while (it != frames.end()) { /* counts how many frames in the list*/
			++it;
			x++;
		}

		if (x <= 1) {
			it = frames.begin(); /* restes iterator*/
			frames.insert_after(it, *new_Frame); /* adds 2nd object*/
		}
		else {
			cout << "There are " << x << " Frame(s) in the list" << endl;
			cout << "Please specify the position, between 0 and " << x - 1 << " to insert after : "; /* get position from user*/
			cin >> framePosition;

			if (framePosition > x || framePosition < 0) { /* boundary check*/
				return;
			}
			it = frames.begin(); /*resets iterator*/

			for (i = 0; i < framePosition; i++) { /* counters frames in list*/
				++it;
			}
			if (x == framePosition) { /* insert frame at specified position*/
				it = frames.begin();
				frames.insert_after(it, *new_Frame);
			}
			else {
				frames.insert_after(it, *new_Frame);
				it = frames.begin();
			}
		}
	}
	delete new_Frame; /*deletes the frame pointer to avoid memory leaks*/
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
	}
	else {
		frames.clear(); /* delete all frames*/
		cout << "Frames are deleted" << endl;
	}
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
	os << "Animation A\n" << "Run the Animation" << endl;
	for (it = a.frames.begin(); it != a.frames.end(); it++) { /* loops through the list and print the frames*/
		os << "Frame #" << counter << ":";
		counter++;
		os << *it << endl;
	}
	os << "Output finished" << endl;
	return os;
}