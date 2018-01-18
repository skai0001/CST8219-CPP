/***************************************************************************************************************************************************
Filename			: ass1.c
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-### ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 1
Due Date			: Novemner  25 2017
Submission Date		: Novemner  25 2017
Professor			: Mohamed Abou Seif
Purpose				: C++ program that holds data of Animation application using singly linked list in a dynamic memory
****************************************************************************************************************************************************/

#include "Frame.h"
#include "Animation.h"
#include <iostream>
#include <time.h>

using namespace std;

/***************************************************************************************************************************************************
Function name : Animation()
Purpose		  : The purpose of this constructor is point head of linkedlist to null
In parameters : 
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
Animation::Animation() {
	frames = (nullptr); /*points frameHead to null*/
}
/***************************************************************************************************************************************************
Function name : ~Animation()
Purpose		  : The purpose of this destructor is to delete all frames in the singly linkedList
In parameters :
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
***************************************************************************************************************************************************/
Animation::~Animation() {
	delete frames; /*deletes frames*/
}

/***************************************************************************************************************************************************
Function name	: insertFrame
Purpose			: The purpose of this function is to insert frames in the animation, then add the name of the frames to an array, then allow the 
user to add the frames at any position in the animation.
In parameters	:
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
***************************************************************************************************************************************************/
void Animation::InsertFrame() {
	char name[100]; /*arrayname*/
	int userInput, counter, i;
	Frame* fNew; /*pointer to new frame*/
	Frame* temp = frames; /*temp pointer points to frames*/
	
	cout <<"Insert a Frame in the Animation" << endl;
	fNew = new Frame; /*adds new frame*/
	cout <<"Please enter the Frame filename: ";
	cin >> name; /* gets name from user*/
	
	fNew->GetfileName() = new char [strlen(name)+1]; /*get name from user after callng getFileName function*/
	strcpy(fNew->GetfileName(), name); /*copy name to array*/
	fNew->GetpNext() = nullptr;	/* point next frame to null */

	if (frames == nullptr) { /*checks if linkedList is empty*/
		frames = fNew; /* frame is added on head */
		cout <<"This is the first Frame in the List\n" << endl;
		return;
	}
	else {
		counter = 0; /* to count existing frames*/
		/*count how many frames exist*/
		while (temp != NULL) {
			counter++;
			temp = temp->GetpNext(); /* temp points to next frame*/
		}
		cout << "There are " << counter << " Frame(s) in the list. Please specify the position (<= " << counter << " to insert at: ";
		cin >> userInput;  /* get location from user*/


			if (userInput > counter || userInput < 0) {  /*checks for parameters*/
				cout << "Invalid" << endl;
				delete[] fNew->GetfileName(); /* delete fileName*/	
				/*delete fNew;*/
				return;
		}	

		if (userInput == 0) { /* adds at head*/
			fNew->GetpNext() = frames; /*points new frame to frames*/
			frames = fNew; /*adds new frame*/

			return;
		}

		temp = frames;  /* resets temp pointing to the first Frame */

		i = 1; 
		while (i < userInput ) { 	/*checks if position gets from user is greater than index then move index */
			temp = temp->GetpNext();
			i++;
		}
			fNew->GetpNext() = temp->GetpNext(); /*linking temp and new frame to the linkedlist */
			temp->GetpNext() = fNew;
	} 
}
/*******************************************************************************************************************************************************************
Function name	: DeleteFrames
Purpose			: This method will delete all the frames in the list when it is called , then free the space of the memory
In parameters	: 
Out parameters	: void
Version			: 1.0
Author			: Hasan Skaiky
*******************************************************************************************************************************************************************/
void Animation:: DeleteFrames() {
	Frame *temp = frames; /*points temp to head */
	Frame* temp2; /* to keep track on the list */


	if (frames == (nullptr)) { /* checks if frames is pointing to NULL means that there's no frames exist */
		cout << "Animation is empty\n" << endl;
	} else {
		
		while (temp != nullptr) {
			temp2 = temp;	/* pointing temp2 to temp */
			temp = temp->GetpNext(); /* pointing temp to next frame */
			delete temp2; /* freeing frame that temp2 pointing to*/ 
		}
		cout << "Delete all the Frames from the Animation" << endl;
		frames = nullptr; /* setting head of the list to null */
	}
}
/*******************************************************************************************************************************************************************
Function name : runFrames
Purpose		  : The purpose of this method is to display the frames in the animation , at which location and their names
In parameters : It takes a pointer pA which points to animation
Out parameters: void
Version		  : 1.0
Author		  : Hasan Skaiky
*******************************************************************************************************************************************************************/
void Animation::RunFrames() {

	int counter = 0;
	time_t startsec, oldsec, newsec;
	Frame* iterator = frames;

	if (frames == 0) { /*checks if animation is empty*/
		cout << "No frames in the animation\n" << endl;
		return;
	}

	cout << "Run the Animation\n";
	startsec = oldsec = time(NULL);
	while (iterator) { /* counter for frames*/
	
		newsec = time(NULL);
		if (newsec > oldsec) {
		
			cout << "Frame #"<< counter++<<", time " <<newsec - startsec << " sec" << endl; /* keep track of time and frames in animation*/
			cout << "Image file name = " << iterator->GetfileName() << endl; /*printout filename got from user*/
			iterator = iterator->GetpNext(); /* iteratres through frames*/
			oldsec = newsec; 
		}
	} 
}
/******************************************************************************************************************************************************************/