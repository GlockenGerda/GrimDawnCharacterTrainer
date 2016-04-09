#pragma once
#include <cstdio>
namespace GDFR {
	public class File
	{
	public:
		FILE *fp;

		File(const char *name, const char *mode)
		{
			fopen_s(&fp, name, mode);
		}

		~File()
		{
			if (fp) fclose(fp);
		}

	private:
		File(const File &) = delete;
		File &operator=(const File &) = delete;
	};
}