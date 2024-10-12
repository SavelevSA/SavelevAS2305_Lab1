#include "CompressorStation.h"
#include "Utils.h"
using namespace std;

//int CompressorStation::CSID = 0;

CompressorStation::CompressorStation()
{
    //id = CSID++;
    Name = "None";
    AmountOfWorkshops = 0;
    WorkshopsInWork = 0;
    EfficiencyLevel = 0;
}

ifstream& operator >> (ifstream& fin, CompressorStation& s)
{
    string Marker;
    fin >> ws;
    getline(fin, Marker);
    if (Marker == "-") return fin;
    else if (Marker == "CS")
    {
        fin >> s.Name;
        fin >> s.AmountOfWorkshops;
        fin >> s.WorkshopsInWork;
        fin >> s.EfficiencyLevel;

        return fin;
    }
}

ofstream& operator << (ofstream& fout, const CompressorStation& s)
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
    return fout;
}

istream& operator >> (istream& in, CompressorStation& s)
{
    cout << "Enter compressor station name: ";
    in >> ws;
    getline(in, s.Name);

    cout << "Enter amount of compressor station workshops: ";
    while (!(in >> s.AmountOfWorkshops) || s.AmountOfWorkshops <= 0)
    {
        ClearInput();
        cout << "Enter amount of compressor station workshops: ";
    }

    cout << "Enter amount of working compressor station workshops: ";
    while (!(in >> s.WorkshopsInWork) || s.WorkshopsInWork < 0 || s.WorkshopsInWork > s.AmountOfWorkshops)
    {
        ClearInput();
        cout << "Enter amount of working compressor station workshops: ";
    }

    cout << "Enter effeciency level of compressor station: ";
    while (!(in >> s.EfficiencyLevel) || s.EfficiencyLevel < 0 || s.EfficiencyLevel > 100)
    {
        ClearInput();
        cout << "Enter effeciency level of compressor station: ";
    }
    cout << "\n";
    return in;
}

ostream& operator << (ostream& out, const CompressorStation& s)
{
    if (s.Name == "None") cout << "Compressor station does not exists" << endl << endl;
    else
    {
        out << "Compressor station name: " << s.Name << endl
        << "Amount of compressor station workshops: " << s.AmountOfWorkshops << endl
        << "Amount of working compressor station workshops: " << s.WorkshopsInWork << endl
        << "Effeciency level of compressor station: " << s.EfficiencyLevel << "%" << endl
        << "\n";
        return out;
    }
}

void CompressorStation::EditCompressorStationWorkhopsInWork()
{
    int AddWorkshops;
    cout << "Enter change of working workstations: ";
    while (!(cin >> AddWorkshops) || (WorkshopsInWork + AddWorkshops) > AmountOfWorkshops
        || (WorkshopsInWork + AddWorkshops) < 0 || AddWorkshops == 0)
    {
        ClearInput();
        cout << "Enter change of working workstations: ";
    }
    WorkshopsInWork += AddWorkshops;
    cout << "Amount of working workstations successfully edited" << "\n" << "\n";
}
