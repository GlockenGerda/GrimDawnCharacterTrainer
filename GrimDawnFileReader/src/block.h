#pragma once
#include <exception>

namespace GDFR {
	struct block
	{
		size_t len;
		long end;
	};

	static std::exception e;
}