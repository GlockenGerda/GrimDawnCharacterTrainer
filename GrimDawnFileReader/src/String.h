#pragma once

#include <string>
namespace GDFR {
	class GDCFile;

	public class String : public std::string
	{
	public:
		void read(GDCFile *);
		void write(GDCFile *);
	};
}