#pragma once
class ItemSkill
{
public:

	String name;
	String autoCastSkill;
	String autoCastController;

	void read(GDCFile *);
	void write(GDCFile *);
};