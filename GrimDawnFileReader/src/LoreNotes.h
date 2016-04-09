#pragma once

#include "Vector.h"
#include "String.h"
namespace GDFR {
	ref class GDCFile;

	public ref class LoreNotes
	{
	public:
		Vector<String>^ names;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}