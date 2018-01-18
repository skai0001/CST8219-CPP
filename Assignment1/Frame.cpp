/***************************************************************************************************************************************************
Filename			: ass1.c
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 1
Due Date			: Novemner  25 2017
Submission Date		: Novemner  25 20177
Professor			: Mohamed Abou Seif
Purpose				: C++ program that holds data of Animation application using singly linked list in a dynamic memory
****************************************************************************************************************************************************/

#include "Frame.h"
#include "Animation.h"
#include <iostream>
using namespace std;

/***************************************************************************************************************************************************
Function name : Frame()
Purpose		  : The purpose of this constructor is to reset fileName and pNext to null
In parameters :
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
Frame::Frame(){
	fileName = (nullptr);
	pNext = (nullptr);
}
/***************************************************************************************************************************************************
Function name : ~Frame()
Purpose		  : The purpose of this destructor is to delete fileName of the frame and points pNext to null
In parameters :
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
Frame::~Frame() {
	delete [] fileName;
	delete pNext;
}

