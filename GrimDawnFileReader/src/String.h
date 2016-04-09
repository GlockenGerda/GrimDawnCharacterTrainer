#pragma once

#include <string>
#include "GDCFile.h"

class String : public std::string
{
public:
	void read(GDCFile *);
	void write(GDCFile *);
};
