#pragma once
class LoreNotes
{
public:
	Vector<String> names;

	void read(GDCFile *);
	void write(GDCFile *);
};