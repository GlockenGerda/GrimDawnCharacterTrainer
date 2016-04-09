#pragma once
#include <stdint.h>

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

template<typename T>
Vector<T>::Vector()
{
	vector = new std::vector<T>();
}

template<typename T>
Vector<T>::~Vector()
{
	delete vector;
}

template <typename T>
void Vector<T>::read(GDCFile *gdc)
{
	uint32_t n = gdc->read_int();

	vector->resize(n);
	T *ptr = vector->data();

	for (uint32_t i = 0; i < n; i++)
	{
		ptr[i].read(gdc);
	}
}

template <typename T>
void Vector<T>::write(GDCFile *gdc)
{
	uint32_t n = vector->size();
	gdc->write_int(n);

	T *ptr = vector->data();
	for (uint32_t i = 0; i < n; i++)
	{
		ptr[i].write(gdc);
	}
}
