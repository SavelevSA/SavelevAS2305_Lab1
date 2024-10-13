#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <unordered_map>

class Pipe
{
private:
	static int maxId;
	int id;
	std::string Name;
	int Length;
	int Diameter;
	bool InRepair;
	
public:
	Pipe();

	int GetId();
	std::string GetName();
	bool GetStatement();

	void EditPipeInRepair();

	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
};