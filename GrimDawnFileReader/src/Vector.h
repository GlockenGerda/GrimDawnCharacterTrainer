#pragma once
#include <stdint.h>

#include <vector>
namespace GDFR {
	ref class GDCFile;

	template <class T>
	public ref class Vector
	{
	public:
		Vector();
		~Vector();
		void read(GDCFile ^);
		void write(GDCFile ^);
		array<T>^ vector;
	};

	template<class T>
	Vector<T>::Vector()
	{
		vector = gcnew array<T>(16);
	}

	template<class T>
	Vector<T>::~Vector()
	{
		delete vector;
	}

	template <class T>
	void Vector<T>::read(GDCFile ^gdc)
	{
		uint32_t n = gdc->read_int();

		vector->resize(n);
		T *ptr = vector->data();

		for (uint32_t i = 0; i < n; i++)
		{
			ptr[i]->read(gdc);
		}
	}

	template <class T>
	void Vector<T>::write(GDCFile ^gdc)
	{
		uint32_t n = vector->size();
		gdc->write_int(n);

		T *ptr = vector->data();
		for (uint32_t i = 0; i < n; i++)
		{
			ptr[i]->write(gdc);
		}
	}
}