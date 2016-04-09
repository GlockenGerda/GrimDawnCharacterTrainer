#include "pch.h"
#include "GDCFile.h"
#include "block.h"
#using<system.dll>
#include <stdio.h>
#include <cstdint>

using namespace System;
using namespace System::IO;

namespace GDFR {
	void GDCFile::read_key()
	{
		uint32_t k = br->ReadInt32();

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
		uint32_t ret = br->ReadInt32();

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
		uint32_t val = br->ReadInt32();

		uint32_t ret = val ^ key;

		update_key(&val, 4);

		return ret;
	}

	uint16_t  GDCFile::read_short()
	{
		uint16_t val = br->ReadInt16();

		uint16_t ret = val ^ key;

		update_key(&val, 2);

		return ret;
	}

	uint8_t GDCFile::read_byte()
	{
		uint16_t val = br->ReadByte();

		uint8_t ret = val ^ key;

		update_key(&val, 1);

		return ret;
	}
	float GDCFile::read_float()
	{
		u.i = read_int();
		return u.f;
	}

	uint32_t GDCFile::read_block_start(block ^b)
	{
		uint32_t ret = this->read_int();

		b->len = next_int();
		b->end = ftell(fp) + b->len;

		return ret;
	}

	void GDCFile::read_block_end(block ^b)
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
		bw->Write(val);
	}

	void GDCFile::write_short(uint16_t val)
	{
		bw->Write(val);
	}

	void GDCFile::write_byte(uint8_t val)
	{
		bw->Write(val);
	}

	void GDCFile::write_float(float val)
	{
		bw->Write(val);
	}

	void GDCFile::write_block_start(block ^b, uint32_t n)
	{
		bw->Write(n);
		bw->Write(0);
		b->end = ftell(fp);
	}

	void GDCFile::write_block_end(block ^b)
	{
		long pos = ftell(fp);

		if (fseek(fp, b->end - 4, SEEK_SET))
			throw e;

		write_int(pos - b->end);

		if (fseek(fp, pos, SEEK_SET))
			throw e;

		write_int(0);
	}

	void GDCFile::read(String^ filename)
	{
		fs = gcnew FileStream(filename->s, FileMode::Open);
		br = gcnew BinaryReader(fs);

		read_key();

		if (read_int() != 0x58434447)
			throw e;

		if (read_int() != 1)
			throw e;

		hdr->read(this);

		if (next_int())
			throw e;

		if (read_int() != 6) // version
			throw e;

		id->read(this);

		info->read(this);
		bio->read(this);
		inv->read(this);
		stash->read(this);
		respawns->read(this);
		teleports->read(this);
		markers->read(this);
		shrines->read(this);
		skills->read(this);
		notes->read(this);
		factions->read(this);
		ui->read(this);
		tutorials->read(this);
		stats->read(this);
	}

	void GDCFile::write(String^ filename)
	{
		fs = gcnew FileStream(filename, FileMode::Create);
		bw = gcnew BinaryWriter(fs);

		write_int(0x55555555);
		write_int(0x58434447);
		write_int(1);

		hdr->write(this);

		write_int(0);

		write_int(6); // version
		id->write(this);

		info->write(this);
		bio->write(this);
		inv->write(this);
		stash->write(this);
		respawns->write(this);
		teleports->write(this);
		markers->write(this);
		shrines->write(this);
		skills->write(this);
		notes->write(this);
		factions->write(this);
		ui->write(this);
		tutorials->write(this);
		stats->write(this);

		if (fflush(fp))
			throw e;
	}
}