﻿// SavelevAS2305_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
using namespace std;

void ClearInput();

//Pipe structure
struct Pipe
{
    string Name;
    int Length;
    int Diameter;
    bool InRepair;
};


//Compressor station structure
struct CompressorStation
{
    string Name;
    int AmountOfWorkshops;
    int WorkshopsInWork;
    int EfficiencyLevel;
};


//Functions of pipe
Pipe CreatePipe()
{
    Pipe p;

    cout << "Enter pipe name: ";
    cin >> p.Name;


    cout << "Enter pipe length: ";
    while (!(cin >> p.Length) || p.Length <= 0)
    {
        ClearInput();
        cout << "Enter pipe length: ";
    }


    cout << "Enter pipe diameter: ";
    while (!(cin >> p.Diameter) || p.Diameter <= 0)
    {
        ClearInput();
        cout << "Enter pipe diameter: ";
    }


    cout << "Set InRepair state: ";
    while (!(cin >> p.InRepair))
    {
        ClearInput();
        cout << "Set InRepair state: ";
    }
    cout << "\n";
    return p;
}

void PipeInformation(const Pipe& p)
{
    cout << "Pipe name: " << p.Name << endl;
    cout << "Pipe length: " << p.Length << endl;
    cout << "Pipe diameter: " << p.Diameter << endl;
    cout << "InRepair state: ", (p.InRepair==1) ? (cout << "In repair\n") : (cout << "In work\n");
    cout << "\n";
}

void EditPipeInRepair(Pipe& p)
{
    p.InRepair = !(p.InRepair);
}


//Functions of compressor station
CompressorStation CreateCompressorStation()
{
    CompressorStation s;

    cout << "Enter compressor station name: ";
    cin >> s.Name;

    cout << "Enter amount of compressor station workshops: ";
    while (!(cin >> s.AmountOfWorkshops) || s.AmountOfWorkshops <= 0)
    {
        ClearInput();
        cout << "Enter amount of compressor station workshops: ";
    }

    cout << "Enter amount of working compressor station workshops: ";
    while (!(cin >> s.WorkshopsInWork) || s.WorkshopsInWork < 0 || s.WorkshopsInWork > s.AmountOfWorkshops)
    {
        ClearInput();
        cout << "Enter amount of working compressor station workshops: ";
    }

    cout << "Enter effeciency level of compressor station: ";
    while (!(cin >> s.EfficiencyLevel) || s.EfficiencyLevel < 0 || s.EfficiencyLevel > 100)
    {
        ClearInput();
        cout << "Enter effeciency level of compressor station: ";
    }
    cout << "\n";
    return s;
}

void CompressorStationInformation(const CompressorStation& s)
{
    cout << "Compressor station name: " << s.Name << endl;
    cout << "Amount of compressor station workshops: " << s.AmountOfWorkshops << endl;
    cout << "Amount of working compressor station workshops: " << s.WorkshopsInWork << endl;
    cout << "Effeciency level of compressor station: " << s.EfficiencyLevel << "%" << endl;
    cout << "\n";
}

void EditCompressorStationWorkhopsInWork(CompressorStation& s)
{
    int AddWorkshops;
    cout << "Enter change of working workstations: ";
    while (!(cin >> AddWorkshops) || (s.WorkshopsInWork + AddWorkshops) > s.AmountOfWorkshops
        || (s.WorkshopsInWork + AddWorkshops) < 0 || AddWorkshops == 0)
    {
        ClearInput();
        cout << "Enter change of working workstations: ";
    }
    s.WorkshopsInWork += AddWorkshops;
}


//Function for clear input
void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}

int main()
{
    CompressorStation s = CreateCompressorStation();
    CompressorStationInformation(s);
    EditCompressorStationWorkhopsInWork(s);
    CompressorStationInformation(s);
    return 0;
}


