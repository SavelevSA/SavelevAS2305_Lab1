#pragma once
#include <iostream>
#include <unordered_map>
#include "Pipe.h"
#include "CompressorStation.h"
#include "InputAndOutput.h"

void ClearInput();

std::unordered_map<int, Pipe> FilterPipes(std::unordered_map<int, Pipe>& UnfilteredPipes, std::unordered_map<int, Pipe>& FilterdPipes);
std::unordered_map<int, CompressorStation> FilterStations(std::unordered_map<int, CompressorStation>& UnfilteredStations, std::unordered_map<int, CompressorStation>& FilterdStations);

template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((std::cin >> x).fail()
		|| std::cin.peek() != '\n'
		|| x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Type number from " << min << " to " << max << ": ";
	}
	std::cout << std::endl;
	return x;
}