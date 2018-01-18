//Animation.h
#pragma once

class Animation {
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void DeleteFrames();
	void RunFrames();
};

