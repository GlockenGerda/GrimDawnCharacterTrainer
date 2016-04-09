#pragma once
#include "Vector.h"
#include "UID.h"

namespace GDFR {
	class GDCFile;

	public class TeleportList
	{
	public:
		Vector<UID> uids[3];

		void read(GDCFile *);
		void write(GDCFile *);
	};
}