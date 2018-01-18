/***************************************************************************************************************************************************
Filename			: Frame.cpp
Version				: 1.0
Author				: Hasan Skaiky
Student Number		: 040-## ###
Course Name/Number	: C++ CST8219
Lab Section			: 303
Assignment #		: 3
Due Date			: Jan 06 2018
Submission Date		: Jan 06 2018
Professor			: Andrew Tylor
Purpose				: constructs new frame object after dynamic casting it to check the Ploymorphism if it's (SystemMemory or gpuMemory)
****************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include<typeinfo>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"

/***************************************************************************************************************************************************
Function name	:Frame()
Purpose			: constructs the frame in a deepCopy based on it's type -using dynamic cast, & constructs the frame fileName
In parameters	: Frame f
Out parameters	:
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
Frame::Frame(const Frame& f) {
	SystemMemoryDisplay * sys_ptr = nullptr;
	GPUMemoryDisplay * gpu_ptr = nullptr;
	fileName = f.fileName;
	unsigned int i = 0;

	while (i < f.displays.size()) { /*loops through the vector*/
									/*constructs new SystemMemory display if its found*/
		if ((sys_ptr = dynamic_cast<SystemMemoryDisplay *>(f.displays[i])) != nullptr) {
			displays.push_back(new SystemMemoryDisplay(*sys_ptr));
		}
		/*constructs new gpyMemory display if its found*/
		else if ((gpu_ptr = dynamic_cast<GPUMemoryDisplay *>(f.displays[i])) != nullptr) {
			displays.push_back(new GPUMemoryDisplay(*gpu_ptr));
		}
		i++;
	}
}
/***************************************************************************************************************************************************
Function name	: operator<<
Purpose			: displays the fileName of the frame object, and its display
In parameters	: ostream os, Frame f
Out parameters	: return os
Version			: 1.0
Author			: Hasan Skaiky
**************************************************************************************************************************************************/
ostream& operator<<(ostream& os, Frame& f) {
	unsigned int i = 0; /*unsigned to remove warnings*/
	SystemMemoryDisplay * sys_ptr;
	GPUMemoryDisplay * gpu_ptr;

	os << "\tfileName = " << f.fileName << endl;
	for (; i < f.displays.size(); i++) {

		os << "\tDisplay #" << i << ": ";
		/*checks if it's SystemMemoryDisplay object then display it */
		if ((sys_ptr = dynamic_cast<SystemMemoryDisplay *>(f.displays[i])) != nullptr) {
			os << "System Memory Display" << "\n" << *sys_ptr << endl;
		}
		/*checks if it's GPUMemoryDisplay object then display it */
		else if ((gpu_ptr = dynamic_cast<GPUMemoryDisplay *>(f.displays[i])) != nullptr) {
			os << "GPU Memory Display. Shader = " << gpu_ptr->GetShader() << "\n" << *gpu_ptr << endl;
		}
	}
	return os;
}