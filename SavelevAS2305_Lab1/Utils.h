#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "Pipe.h"
#include "CompressorStation.h"
#include "InputAndOutput.h"

#define INPUT_LINE(in, str) getline(in >> std::ws, str); \
							std::cerr << str << std::endl

class redirect_output_wrapper
{
	std::ostream& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ostream& src)
		:old_buf(src.rdbuf()), stream(src)
	{
	}
	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}
	void redirect(std::ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};

void MainMenu();
void PipeMenu();
void StationMenu();

template <typename T>
T GetCorrectNumber(T min, T max);

void ClearChoosedPipes(std::unordered_set<int>& PipeIds);
void ClearChoosedStations(std::unordered_set<int>& StationIds);

template<typename T>
using FilterP = bool(*)(Pipe& p, T param);
bool CheckByName(Pipe& p, std::string param);
bool CheckByStatement(Pipe& p, bool param);

template<typename T>
void FindPipesByFilter(std::unordered_map<int, Pipe>& Pipes, FilterP<T> f, T param, std::unordered_set<int>& PipeIds);

using EADP= void(*)(std::unordered_map<int, Pipe>& Pipes, std::unordered_set<int>& PipeIds);
void EditPipe(std::unordered_map<int, Pipe>& Pipes, std::unordered_set<int>& PipeIds);
void Delete(std::unordered_map<int, Pipe>& Pipes, std::unordered_set<int>& PipeIds);

void EditAndDelete(std::unordered_map<int, Pipe>& Pipes, EADP f, std::unordered_set<int>& PipeIds);
void ChooseAndFilterPipes(std::unordered_map<int, Pipe>& Pipes);


template<typename T>
using FilterS = bool(*)(CompressorStation& s, T param);
bool CheckByName(CompressorStation& s, std::string param);
bool CheckByPercent(CompressorStation& s, int param);

template<typename T>
void FindStationsByFilter(std::unordered_map<int, CompressorStation>& Stations, FilterS<T> f, T param, std::unordered_set<int>& StationIds);

using EADS = void(*)(std::unordered_map<int, CompressorStation>& Stations, std::unordered_set<int>& StationIds, const char sign);
void EditStations(std::unordered_map<int, CompressorStation>& Stations, std::unordered_set<int>& StationIds, const char sign);
void DeleteS(std::unordered_map<int, CompressorStation>& Stations, std::unordered_set<int>& StationIds, const char sign);

void EditAndDeleteS(std::unordered_map<int, CompressorStation>& Stations, EADS f, std::unordered_set<int>& StationIds, const char sign);
void ChooseAndFilterStations(std::unordered_map<int, CompressorStation>& Stations);