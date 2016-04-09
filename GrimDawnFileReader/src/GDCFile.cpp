#include "pch.h"
#include "GDCFile.h"
#include "File.h"
#include "block.h"

#include <stdio.h>
#include <cstdint>
namespace GDFR {
	void GDCFile::read_key()
	{
		uint32_t k;

		if (fread(&k, 4, 1, fp) != 1)
			throw e;

		k ^= 0x55555555;

		key = k;

		for (unsigned i = 0; i < 256; i++)
		{
			k = (k >> 1) | (k << 31);
			k *= 39916801;
			table[i] = k;
		}
	}

	uint32_t GDCFile::next_int()
	{
		uint32_t ret;

		if (fread(&ret, 4, 1, fp) != 1)
			throw e;

		ret ^= key;

		return ret;
	}

	void GDCFile::update_key(void *ptr, uint32_t len)
	{
		uint8_t *p = (uint8_t *)ptr;

		for (uint32_t i = 0; i < len; i++)
		{
			key ^= table[p[i]];
		}
	}

	uint32_t GDCFile::read_int()
	{
		uint32_t val;

		if (fread(&val, 4, 1, fp) != 1)
			throw e;

		uint32_t ret = val ^ key;

		update_key(&val, 4);

		return ret;
	}

	uint16_t  GDCFile::read_short()
	{
		uint16_t val;

		if (fread(&val, 2, 1, fp) != 1)
			throw e;

		uint16_t ret = val ^ key;

		update_key(&val, 2);

		return ret;
	}

	uint8_t GDCFile::read_byte()
	{
		uint8_t val;

		if (fread(&val, 1, 1, fp) != 1)
			throw e;

		uint8_t ret = val ^ key;

		update_key(&val, 1);

		return ret;
	}

	float GDCFile::read_float()
	{
		union { float f; int i; } u;
		u.i = read_int();
		return u.f;
	}

	uint32_t GDCFile::read_block_start(block *b)
	{
		uint32_t ret = this->read_int();

		b->len = next_int();
		b->end = ftell(fp) + b->len;

		return ret;
	}

	void GDCFile::read_block_end(block *b)
	{
		if (ftell(fp) != b->end)
		{
			throw e;
		}

		if (next_int())
			throw e;
	}

	void GDCFile::write_int(uint32_t val)
	{
		if (fwrite(&val, 4, 1, fp) != 1)
			throw e;
	}

	void GDCFile::write_short(uint16_t val)
	{
		if (fwrite(&val, 2, 1, fp) != 1)
			throw e;
	}

	void GDCFile::write_byte(uint8_t val)
	{
		if (fwrite(&val, 1, 1, fp) != 1)
			throw e;
	}

	void GDCFile::write_float(float val)
	{
		if (fwrite(&val, 4, 1, fp) != 1)
			throw e;
	}

	void GDCFile::write_block_start(block *b, uint32_t n)
	{
		write_int(n);
		write_int(0);
		b->end = ftell(fp);
	}

	void GDCFile::write_block_end(block *b)
	{
		long pos = ftell(fp);

		if (fseek(fp, b->end - 4, SEEK_SET))
			throw e;

		write_int(pos - b->end);

		if (fseek(fp, pos, SEEK_SET))
			throw e;

		write_int(0);
	}

	void GDCFile::read(const char *filename)
	{
		File f(filename, "rb");

		if (!(fp = f.fp))
			throw e;

		if (fseek(fp, 0, SEEK_END))
			throw e;

		long end = ftell(fp);

		if (fseek(fp, 0, SEEK_SET))
			throw e;

		read_key();

		if (read_int() != 0x58434447)
			throw e;

		if (read_int() != 1)
			throw e;

		hdr.read(this);

		if (next_int())
			throw e;

		if (read_int() != 6) // version
			throw e;

		id.read(this);

		info.read(this);
		bio.read(this);
		inv.read(this);
		stash.read(this);
		respawns.read(this);
		teleports.read(this);
		markers.read(this);
		shrines.read(this);
		skills.read(this);
		notes.read(this);
		factions.read(this);
		ui.read(this);
		tutorials.read(this);
		stats.read(this);

		if (ftell(fp) != end)
			throw e;
	}

	void GDCFile::write(const char *filename)
	{
		File f(filename, "wb");

		if (!(fp = f.fp))
			throw e;

		write_int(0x55555555);
		write_int(0x58434447);
		write_int(1);

		hdr.write(this);

		write_int(0);

		write_int(6); // version
		id.write(this);

		info.write(this);
		bio.write(this);
		inv.write(this);
		stash.write(this);
		respawns.write(this);
		teleports.write(this);
		markers.write(this);
		shrines.write(this);
		skills.write(this);
		notes.write(this);
		factions.write(this);
		ui.write(this);
		tutorials.write(this);
		stats.write(this);

		if (fflush(fp))
			throw e;
	}
}