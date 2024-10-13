#include "CompressorStation.h"
#include "Utils.h"
using namespace std;

int CompressorStation::maxId = 0;

CompressorStation::CompressorStation()
{
    id = 0;
    Name = "None";
    AmountOfWorkshops = 0;
    WorkshopsInWork = 0;
    EfficiencyLevel = 0;
}

ifstream& operator >> (ifstream& fin, CompressorStation& s)
{
    fin >> s.id;
    s.maxId = s.id;
    fin >> ws;
    getline(fin, s.Name);
    fin >> s.AmountOfWorkshops;
    fin >> s.WorkshopsInWork;
    fin >> s.EfficiencyLevel;

    return fin;
}

ofstream& operator << (ofstream& fout, const CompressorStation& s)
{
    if (s.Name != "None");
    {
        fout << s.id << endl
        << s.Name << endl
        << s.AmountOfWorkshops << endl
        << s.WorkshopsInWork << endl
        << s.EfficiencyLevel << endl;
    }
    return fout;
}

istream& operator >> (istream& in, CompressorStation& s)
{
    s.id = ++s.maxId;
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
    out << "ID: " << s.id << endl
    << "Compressor station name: " << s.Name << endl
    << "Amount of compressor station workshops: " << s.AmountOfWorkshops << endl
    << "Amount of working compressor station workshops: " << s.WorkshopsInWork << endl
    << "Effeciency level of compressor station: " << s.EfficiencyLevel << "%" << endl
    << "\n";
    return out;
}


void CompressorStation::EditWorkingWorkshops(const char sign)
{
    if (sign == char("+") && WorkshopsInWork + 1 <= AmountOfWorkshops)
        WorkshopsInWork += 1;
    else if (sign == char("-") && WorkshopsInWork - 1 >= 0)
        WorkshopsInWork -= 1;
}

int CompressorStation::GetId()
{
    return id;
}

string CompressorStation::GetName()
{
    return Name;
}

int CompressorStation::GetWorkhops()
{
    return AmountOfWorkshops;
}

int CompressorStation::GetWorkingWorkhops()
{
    return WorkshopsInWork;
}

int CompressorStation::GetPercent()
{
    return (AmountOfWorkshops - WorkshopsInWork) * 100 / (AmountOfWorkshops);
}