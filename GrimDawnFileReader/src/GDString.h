#pragma once
using namespace System;
namespace GDFR {
	ref class GDCFile;

	public ref class GDString
	{
	public:
		String^ s;
		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}