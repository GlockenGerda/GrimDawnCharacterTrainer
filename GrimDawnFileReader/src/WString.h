#pragma once

class WString
{
private:
	std::wstring *string;
public:
	void read(GDCFile *);
	void write(GDCFile *);
};