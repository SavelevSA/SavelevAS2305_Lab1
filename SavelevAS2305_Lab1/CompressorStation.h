#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <unordered_map>

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

	int GetId();
	void EditCompressorStationWorkhopsInWork();

	friend std::ifstream& operator >> (std::ifstream& fin, CompressorStation& s);
	friend std::ofstream& operator << (std::ofstream& fout, const CompressorStation& s);

	friend std::istream& operator >> (std::istream& in, CompressorStation& s);
	friend std::ostream& operator << (std::ostream& out, const CompressorStation& s);

};
