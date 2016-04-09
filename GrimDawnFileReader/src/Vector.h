#pragma once

#include <vector>
class GDCFile;

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
	void read(GDCFile *);
	void write(GDCFile *);
	std::vector<T> *vector;
};
