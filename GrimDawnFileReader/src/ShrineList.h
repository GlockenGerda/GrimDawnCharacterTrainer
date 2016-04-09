#pragma once

#include "Vector.h"
#include "UID.h"
namespace GDFR {
	class GDCFile;

	public class ShrineList
	{
	public:
		Vector<UID> uids[6];

		void read(GDCFile *);
		void write(GDCFile *);
	};
}
