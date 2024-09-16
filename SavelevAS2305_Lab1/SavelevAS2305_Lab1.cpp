// SavelevAS2305_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void ClearInput();

//Структура труба, её свойства и функции
struct Pipe
{
    string Name;
    int Length;
    int Diameter;
    bool InRepair;
};

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

void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}


void PipeInformation(const Pipe& p)
{
    cout << "Pipe name: " << p.Name << endl;
    cout << "Pipe length: " << p.Length << endl;
    cout << "Pipe diameter: " << p.Diameter << endl;
    cout << "InRepair state: ", (p.InRepair==1) ? (cout << "In repair\n") : (cout << "In work\n");
    cout << "\n";
}

void EditInRepair(Pipe& p)
{
    p.InRepair = !(p.InRepair);
}

int main()
{
    Pipe p = CreatePipe();
    PipeInformation(p);
    EditInRepair(p);
    PipeInformation(p);
    return 0;
}


