#pragma once

#include <string>
namespace GDFR {
	class GDCFile;

	public class WString
	{
	private:
		std::wstring *string;
	public:
		void read(GDCFile *);
		void write(GDCFile *);
	};
}