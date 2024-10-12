#pragma once
#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"

std::unordered_map<int, Pipe> CreatePipe(std::unordered_map<int, Pipe>& pipes);
void PrintPipes(std::unordered_map<int, Pipe>& pipes);

std::unordered_map<int, CompressorStation> CreateCompressorStation(std::unordered_map<int, CompressorStation>& Stations);
void PrintCompressorStations(std::unordered_map<int, CompressorStation>& Stations);

void SaveToFile(std::unordered_map<int, Pipe>& Pipes, std::unordered_map<int, CompressorStation>& Stations);

std::unordered_map<int, Pipe> LoadPipe(std::unordered_map<int, Pipe>& Pipes, int count, std::ifstream& fin);
std::unordered_map<int, CompressorStation> LoadCompressorStation(std::unordered_map<int, CompressorStation>& Stations, int count, std::ifstream& fin);
void LoadFromFile(std::unordered_map<int, Pipe>& Pipes, std::unordered_map<int, CompressorStation>& Stations);