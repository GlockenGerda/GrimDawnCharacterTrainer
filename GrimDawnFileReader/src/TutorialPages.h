#pragma once

#include "Vector.h"
namespace GDFR {
	class GDCFile;

	public class TutorialPages
	{
	public:
		Vector<size_t> pages;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}