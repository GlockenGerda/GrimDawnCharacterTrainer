#pragma once
class TutorialPages
{
public:
	Vector<size_t> pages;

	void read(GDCFile *);
	void write(GDCFile *);
};