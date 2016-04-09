#pragma once
#include "Vector.h"
#include "UID.h"

namespace GDFR {
	ref class GDCFile;

	public ref class TeleportList
	{
	public:
		array<Vector<UID> ^>^ uids = gcnew array<Vector<UID> ^>(3);

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}