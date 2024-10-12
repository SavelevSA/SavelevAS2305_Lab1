#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>

class CompressorStation
{
private:
	std::string Name;
	int AmountOfWorkshops;
	int WorkshopsInWork;
	int EfficiencyLevel;
	int id;

public:

	CompressorStation();

	void EditCompressorStationWorkhopsInWork();
	friend std::ifstream& operator >> (std::ifstream& fin, CompressorStation& p);
	friend std::ofstream& operator << (std::ofstream& fout, const CompressorStation& p);

	friend std::istream& operator >> (std::istream& in, CompressorStation& p);
	friend std::ostream& operator << (std::ostream& out, const CompressorStation& p);

};
