#pragma once

#include "Vector.h"
namespace GDFR {
	ref class GDCFile;

	public ref class TutorialPages
	{
	public:
		Vector<size_t>^ pages;

		void read(GDCFile^);
		void write(GDCFile^);
	};
}