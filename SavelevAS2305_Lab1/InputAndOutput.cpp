#include "InputAndOutput.h"
#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"

using namespace std;

void SaveToFile(const unordered_map<int, Pipe>& Pipes, const unordered_map<int, CompressorStation>& Stations)
{
    ofstream fout;
    string file;

    cout << "Enter name of file to save: ";
    INPUT_LINE(cin, file);
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
        cout << "Data successfully saved" << endl;
    }
}

void LoadFromFile(unordered_map<int, Pipe>& Pipes, unordered_map<int, CompressorStation>& Stations)
{
    ifstream fin;
    string file;

    cout << "Enter name of file to load from: ";
    INPUT_LINE(cin, file);
    cout << endl;

    fin.open(file);

    if (fin.is_open())
    {
        int CountOfPipes;
        fin >> CountOfPipes;

        int CountOfCS;
        fin >> CountOfCS;

        LoadObject(Pipes, CountOfPipes, fin);
        LoadObject(Stations, CountOfCS, fin);
        cout << "Data successfully loaded" << endl;
    }
    else
        cout << "There is no file with that name" << endl;
    fin.close();
    
}