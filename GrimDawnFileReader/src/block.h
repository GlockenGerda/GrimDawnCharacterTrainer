#pragma once
#include <exception>

namespace GDFR {
	ref struct block
	{
		size_t len;
		long end;
	};

	static std::exception e;
}