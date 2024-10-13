#pragma once
#include <iostream>
#include <unordered_map>
#include "Pipe.h"
#include "CompressorStation.h"
#include "InputAndOutput.h"

void ClearInput();

template <typename T>
T GetCorrectNumber(T min, T max);

std::unordered_map<int, Pipe> FilterPipes(std::unordered_map<int, Pipe>& UnfilteredPipes, std::unordered_map<int, Pipe>& FilterdPipes);
std::unordered_map<int, CompressorStation> FilterStations(std::unordered_map<int, CompressorStation>& UnfilteredStations, std::unordered_map<int, CompressorStation>& FilterdStations);

std::unordered_map<int, Pipe> EditPipes(std::unordered_map<int, Pipe>& ChoosedPipes, std::unordered_map<int, Pipe>& Pipes);
std::unordered_map<int, CompressorStation> EditStations(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations, const char sign);

std::unordered_map<int, Pipe> ChoosePipe(std::unordered_map<int, Pipe>& ChoosedPipes, std::unordered_map<int, Pipe>& Pipes);
std::unordered_map<int, CompressorStation> ChooseStation(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations);

std::unordered_map<int, Pipe> DeletePipes(std::unordered_map<int, Pipe>& ChoosedPipes, std::unordered_map<int, Pipe>& Pipes);
std::unordered_map<int, CompressorStation> DeleteStations(std::unordered_map<int, CompressorStation>& ChoosedStations, std::unordered_map<int, CompressorStation>& Stations);

void ClearChoosedPipes(std::unordered_map<int, Pipe>& ChoosedPipes);
void ClearChoosedStations(std::unordered_map<int, CompressorStation>& ChoosedStations);