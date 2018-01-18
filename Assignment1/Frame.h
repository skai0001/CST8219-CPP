// Frame.h
#pragma once

class Frame {
	char* fileName;
	Frame* pNext;
public:
	Frame();
	~Frame();
	char*& GetfileName() { return fileName; }
	Frame*& GetpNext() { return pNext; };
};