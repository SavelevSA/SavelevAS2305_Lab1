#pragma once
#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"

void SaveToFile(const std::unordered_map<int, Pipe>& Pipes, const std::unordered_map<int, CompressorStation>& Stations);

void LoadFromFile(std::unordered_map<int, Pipe>& Pipes, std::unordered_map<int, CompressorStation>& Stations);

template <typename T>
void PrintObject(const std::unordered_map<int, T>& Objects)
{
    if (Objects.empty())
    {
        if (typeid(T).name() == typeid(Pipe).name())
            std::cout << "There is no pipes" << std::endl;
        else
            std::cout << "There is no compressor stations" << std::endl;
    }
    else
        for (const auto& o : Objects)
            std::cout << o.second;
}

template <typename T>
std::unordered_map<int, T> CreateObject(std::unordered_map<int, T>& Objects)
{
    T obj{};

    std::cin >> obj;
    Objects.emplace(obj.GetId(), obj);
    return Objects;
};

template <typename T>
std::unordered_map<int, T> LoadObject(std::unordered_map<int, T>& Objects, int count, std::ifstream& fin)
{
    for (int i = 0; i < count; i++)
    {
        T obj{};
        fin >> obj;
        Objects.emplace(obj.GetId(), obj);
    }
    return Objects;
}