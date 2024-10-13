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
    in >> ws;
    getline(in, p.Name);


    cout << "Enter pipe length: ";
    while (!(in >> p.Length) || p.Length <= 0)
    {
        ClearInput();
        cout << "Enter pipe length: ";
    }


    cout << "Enter pipe diameter: ";
    while (!(in >> p.Diameter) || p.Diameter <= 0)
    {
        ClearInput();
        cout << "Enter pipe diameter: ";
    }


    cout << "Set InRepair state: ";
    while (!(in >> p.InRepair))
    {
        ClearInput();
        cout << "Set InRepair state: ";
    }
    cout << "\n";
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
