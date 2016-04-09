#pragma once

#include <string>
namespace GDFR {
	ref class GDCFile;

	public ref class WString
	{
	private:
		std::wstring *string;
	public:
		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}