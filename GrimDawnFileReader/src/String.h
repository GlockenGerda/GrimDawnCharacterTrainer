#pragma once

#include <string>
class GDCFile;

class String : public std::string
{
public:
	void read(GDCFile *);
	void write(GDCFile *);
};
