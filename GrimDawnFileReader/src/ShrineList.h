#pragma once

#include "Vector.h"
#include "UID.h"
namespace GDFR {
	ref class GDCFile;

	public ref class ShrineList
	{
	public:
		array<Vector<UID>^ >^ uids = gcnew array<Vector<UID>^ >(6);

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}
