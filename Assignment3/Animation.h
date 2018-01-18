//Animation.h
#pragma once
class Animation
{
	string name;
	forward_list<Frame> frames;
public:
	Animation(string s) : name(s) {}
	void InsertFrame();
	void DeleteFrames();
	friend ostream& operator<<(ostream&, Animation&);
};