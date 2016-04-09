#pragma once

template <typename T>
class Vector
{
private:
	std::vector<T> *vector;
public:
	Vector();
	void read(GDCFile *);
	void write(GDCFile *);
};
