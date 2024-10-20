#pragma once
#include <iostream>
#include <unordered_map>
#include <set>
#include "Pipe.h"
#include "CompressorStation.h"
#include "InputAndOutput.h"

void ClearInput();
void MainMenu();
void PipeMenu();
void StationMenu();

template <typename T>
T GetCorrectNumber(T min, T max);

//std::unordered_map<int, CompressorStation> FilterStations(std::unordered_map<int, CompressorStation>& UnfilteredStations, std::unordered_map<int, CompressorStation>& FilterdStations);
//
//std::unordered_map<int, CompressorStation> EditStations(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations, const char sign);
//
//std::unordered_map<int, CompressorStation> ChooseStation(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations);
//
//std::unordered_map<int, CompressorStation> DeleteStations(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations);

void ClearChoosedPipes(std::set<int>& PipeIds);
void ClearChoosedStations(std::set<int>& StationIds);

template<typename T>
using FilterP = bool(*)(Pipe& p, T param);
bool CheckByName(Pipe& p, std::string param);
bool CheckByStatement(Pipe& p, bool param);

template<typename T>
void FindPipesByFilter(std::unordered_map<int, Pipe>& Pipes, FilterP<T> f, T param, std::set<int>& PipeIds);

using EADP= void(*)(std::unordered_map<int, Pipe>& Pipes, std::set<int>& PipeIds);
void EditPipe(std::unordered_map<int, Pipe>& Pipes, std::set<int>& PipeIds);
void Delete(std::unordered_map<int, Pipe>& Pipes, std::set<int>& PipeIds);

void EditAndDelete(std::unordered_map<int, Pipe>& Pipes, EADP f, std::set<int>& PipeIds);
void ChooseAndFilterPipes(std::unordered_map<int, Pipe>& Pipes);


template<typename T>
using FilterS = bool(*)(CompressorStation& s, T param);
bool CheckByName(CompressorStation& s, std::string param);
bool CheckByPercent(CompressorStation& s, int param);

template<typename T>
void FindStationsByFilter(std::unordered_map<int, CompressorStation>& Stations, FilterS<T> f, T param, std::set<int>& StationIds);

using EADS = void(*)(std::unordered_map<int, CompressorStation>& Stations, std::set<int>& StationIds, const char sign);
void EditStations(std::unordered_map<int, CompressorStation>& Stations, std::set<int>& StationIds, const char sign);
void DeleteS(std::unordered_map<int, CompressorStation>& Stations, std::set<int>& StationIds, const char sign);

void EditAndDeleteS(std::unordered_map<int, CompressorStation>& Stations, EADS f, std::set<int>& StationIds, const char sign);
void ChooseAndFilterStations(std::unordered_map<int, CompressorStation>& Stations);