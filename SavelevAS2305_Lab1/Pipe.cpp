#include "Pipe.h"
#include "Utils.h"
using namespace std;

int Pipe::maxId = 0;

Pipe::Pipe()
{
    id = 0;
    Name = "None";
    Length = 0;
    Diameter = 0;
    InRepair = 0;
}


ifstream& operator >> (ifstream& fin, Pipe& p)
{
    fin >> p.id;
    p.maxId = p.id;
    fin >> ws;
    getline(fin, p.Name);
    fin >> p.Length;
    fin >> p.Diameter;
    fin >> p.InRepair;

    return fin;
}

ofstream& operator << (ofstream& fout, const Pipe& p)
{
    if (p.Name != "None");
    {
        fout << p.id << endl
        << p.Name << endl
        << p.Length << endl
        << p.Diameter << endl
        << p.InRepair << endl;
    }
    return fout;
}

istream& operator >> (istream& in, Pipe& p)
{
    p.id = ++p.maxId;
    cout << "Enter pipe name: ";
    INPUT_LINE(in, p.Name);

    cout << "Enter pipe length: ";
    p.Length = GetCorrectNumber(100, 1500);

    cout << "Enter pipe diameter: ";
    p.Diameter = GetCorrectNumber(200, 700);

    cout << "Set InRepair state: ";
    p.InRepair = GetCorrectNumber(0, 1);

    return in;
}

ostream& operator << (ostream& out, const Pipe& p)
{
    out << "ID: " << p.id << endl
        << "Pipe name: " << p.Name << endl
        << "Pipe length: " << p.Length << endl
        << "Pipe diameter : " << p.Diameter << endl
        << "InRepair state: " << (p.InRepair ? "In repair\n" : "In work\n") << endl;
    return out;
}


void Pipe::EditPipeInRepair()
{
    InRepair = !(InRepair);
}

int Pipe::GetId()
{
    return id;
}

string Pipe::GetName()
{
    return Name;
}

bool Pipe::GetStatement()
{
    return InRepair;
}
