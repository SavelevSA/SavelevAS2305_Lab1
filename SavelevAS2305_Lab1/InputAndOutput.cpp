#include "InputAndOutput.h"
#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"

using namespace std;


unordered_map<int, Pipe> CreatePipe(unordered_map<int, Pipe>& Pipes)
{
    Pipe p;

    cin >> p;
    Pipes.emplace(p.GetId(), p);
    return Pipes;
}

void PrintPipes(unordered_map<int, Pipe>& Pipes)
{
    if (Pipes.size() == 0)
    {
        cout << "There is no pipes" << endl << endl;
    }
    else
    {
        for (const auto& pipe : Pipes)
        {
            cout << pipe.second;
        }
    }
}


unordered_map<int, CompressorStation> CreateCompressorStation(unordered_map<int, CompressorStation>& Stations)
{
    CompressorStation p;

    cin >> p;
    Stations.emplace(p.GetId(), p);
    return Stations;
}

void PrintCompressorStations(unordered_map<int, CompressorStation>& Stations)
{
    if (Stations.size() == 0)
    {
        cout << "There is no stations" << endl << endl;
    }
    else
    {
        for (const auto& station : Stations)
        {
            cout << station.second;
        }
    }
}


void SaveToFile(unordered_map<int, Pipe>& Pipes, unordered_map<int, CompressorStation>& Stations)
{
    ofstream fout;
    string file;

    cout << "Enter name of file to save: ";
    cin >> ws;
    getline(cin, file);
    cout << endl;

    fout.open(file);

    if (fout.is_open())
    {
        fout << Pipes.size() << endl;
        fout << Stations.size() << endl;

        for (const auto& pipe : Pipes)
        {
            fout << pipe.second;
        }

        for (const auto& station : Stations)
        {
            fout << station.second;
        }

        fout.close();
        cout << "Data successfully saved" << endl << endl;
    }
}


unordered_map<int, Pipe> LoadPipe(unordered_map<int, Pipe>& Pipes, int count, ifstream& fin)
{
    for (int i = 0; i < count; i++)
    {
        Pipe p;
        fin >> p;
        Pipes.emplace(p.GetId(), p);
    }
    return Pipes;
}

unordered_map<int, CompressorStation> LoadCompressorStation(unordered_map<int, CompressorStation>& Stations, int count, ifstream& fin)
{
    for (int i = 0; i < count; i++)
    {
        CompressorStation s;
        fin >> s;
        Stations.emplace(s.GetId(), s);
    }
    return Stations;
}

void LoadFromFile(unordered_map<int, Pipe>& Pipes, unordered_map<int, CompressorStation>& Stations)
{
    ifstream fin;
    string file;

    cout << "Enter name of file to load from: ";
    cin >> ws;
    getline(cin, file);
    cout << endl;

    fin.open(file);

    if (fin.is_open())
    {
        int CountOfPipes;
        fin >> CountOfPipes;

        int CountOfCS;
        fin >> CountOfCS;

        LoadPipe(Pipes, CountOfPipes, fin);
        LoadCompressorStation(Stations, CountOfCS, fin);
    }
    fin.close();
    cout << "Data successfully loaded" << endl << endl;
}