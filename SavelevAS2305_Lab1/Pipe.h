#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>

class Pipe
{
private:
	std::string Name;
	int Length;
	int Diameter;
	//static int PipeID;
	//int id;
	
public:
	bool InRepair;

	Pipe();

	void EditPipeInRepair(Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);

};