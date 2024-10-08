#include "Pipe.h"
#include "Utils.h"
using namespace std;

//int Pipe::PipeID = 0;

Pipe::Pipe()
{
    //id = PipeID++;
    Name = "None";
    Length = 0;
    Diameter = 0;
    InRepair = 0;
}

ifstream& operator >> (ifstream& fin, Pipe& p)
{
    string Marker;
    fin >> ws;
    getline(fin, Marker);
    if (Marker == "-") return fin;
    else if (Marker == "Pipe")
    {
        fin >> p.Name;
        fin >> p.Length;
        fin >> p.Diameter;
        fin >> p.InRepair;

        return fin;
    }
}

ofstream& operator << (ofstream& fout, const Pipe& p)
{
    string Marker = "-";
    if (p.Name == "None") fout << Marker << endl;
    else
    {
        fout << "Pipe" << endl;
        fout << p.Name << endl;
        fout << p.Length << endl;
        fout << p.Diameter << endl;
        fout << p.InRepair << endl;
    }
    return fout;
}

istream& operator >> (istream& in, Pipe& p)
{
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
    if (p.Name == "None") cout << "Pipe does not exists" << endl << endl;
    else
    {
        out << "Pipe name: " << p.Name << endl
            << "Pipe length: " << p.Length << endl
            << "Pipe diameter : " << p.Diameter << endl
            << "InRepair state: " << (p.InRepair ? "In repair\n" : "In work\n") << endl;
        return out;
    }
}

void Pipe::EditPipeInRepair(Pipe& p)
{
    if (p.Name != "None")
    {
        p.InRepair = !(p.InRepair);
        cout << "Pipe InRepair state successfully changed" << "\n" << "\n";
    }
    else cout << "Pipe does not exists" << endl << endl;;
}

