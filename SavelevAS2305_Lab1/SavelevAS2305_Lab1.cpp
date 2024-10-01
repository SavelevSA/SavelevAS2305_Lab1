#include <iostream>
#include <fstream>
#include <string>
#include "Pipe.h"

void ClearInput();

using namespace std;

//Compressor station structure
struct CompressorStation
{
    string Name;
    int AmountOfWorkshops;
    int WorkshopsInWork;
    int EfficiencyLevel;
};


//Functions of compressor station
CompressorStation CreateCompressorStation()
{
    CompressorStation s;

    cout << "Enter compressor station name: ";
    cin >> ws;
    getline(cin, s.Name);

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
    cout << "Amount of working workstations successfully edited" << "\n" << "\n";
}


void PrintMenu()
{
    cout << "1. Input pipe" << endl
        << "2. Input compressor station" << endl
        << "3. Print pipe and compressor station" << endl
        << "4. Edit InRepair state of pipe" << endl
        << "5. Edit amount of working workshops of compressor station" << endl
        << "6. Save objects to file" << endl
        << "7. Load objects from file" << endl
        << "0. Exit" << endl
        << "Choose action: ";
}

void SaveCompressorStation(ofstream& fout, const CompressorStation& s)
{
    string Marker = "-";
    if (s.Name == "None") fout << Marker << endl;
    else
    {
        fout << "CS" << endl;
        fout << s.Name << endl;
        fout << s.AmountOfWorkshops << endl;
        fout << s.WorkshopsInWork << endl;
        fout << s.EfficiencyLevel << endl;
    }
}

CompressorStation LoadCompressorStation(ifstream& fin)
{
    CompressorStation s;


    string Marker;
    fin >> ws;
    getline(fin, Marker);
    if (Marker == "-") return s = { "None", 0, 0, 0 };
    else if (Marker == "CS")
    {
        fin >> s.Name;
        fin >> s.AmountOfWorkshops;
        fin >> s.WorkshopsInWork;
        fin >> s.EfficiencyLevel;

        return s;
    }
}


int main()
{
    Pipe p;
    CompressorStation s = { "None", 0, 0, 0 };

    while (1)
    {
        PrintMenu();

        int MenuSelection;

        while (!(cin >> MenuSelection))
        {
            ClearInput();
            PrintMenu();
        }
        cout << "\n";

        switch (MenuSelection)
        {
            //Input pipe
            case 1:
            {
                cin >> p;
                break;
            }
            //Input compressor station
            case 2:
            {
                s = CreateCompressorStation();
                break;
            }
            //Print pipe and compressor station
            case 3:
            {
                cout << p;
                if (s.Name == "None") cout << "Compressor station does not exists" << endl << endl;
                else CompressorStationInformation(s);
                break;
            }
            //Edit InRepair state of pipe
            case 4:
            {
                p.EditPipeInRepair(p);
                break;
            }
            //Edit amount of working workshops of compressor station
            case 5:
            {
                if (s.Name != "None")
                {
                    EditCompressorStationWorkhopsInWork(s);
                    break;
                }
                else
                {
                    cout << "Compressor station does not exists" << endl << endl;
                    break;
                }
            }
            //Save objects to file
            case 6:
            {
                ofstream fout;
                fout.open("data.txt", ios::out);
                if (fout.is_open())
                {
                    fout << p;
                    SaveCompressorStation(fout, s);
                    fout.close();
                    cout << "Data successfully saved" << endl << endl;
                }
                break;
            }
            //Load objects from file
            case 7:
            {
                ifstream fin;
                fin.open("data.txt", ios::in);
                if (fin.is_open())
                {
                    fin >> p;
                    s = LoadCompressorStation(fin);
                    fin.close();
                    cout << "Data successfully loaded" << endl << endl;
                }
                break;
            }
            //Exit
            case 0:
            {
                return 0;
            }
            default:
            {
                cout << "Wrong action" << endl << endl;
            }
        }
    }
    return 0;
}


