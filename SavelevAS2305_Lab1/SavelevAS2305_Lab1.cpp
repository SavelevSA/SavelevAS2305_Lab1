// SavelevAS2305_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


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

    cout << "Enter pipe Length: ";
    cin >> p.Length;


    //Как-то по-другому?
    //Обязательно спросить про проверки
    while (p.Length <= 0)
    {
        cout << "Entered incorrect value\n";
        cout << "Enter pipe length: ";
        cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
        cin >> p.Length;
    }

    cout << "Enter pipe diameter: ";
    cin >> p.Diameter;


    while (p.Diameter <= 0)
    {
        cout << "Entered incorrect value\n";
        cout << "Enter pipe diameter: ";
        cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
        cin >> p.Diameter;
    }

    cout << "Set InRepair state: ";
    cin >> p.InRepair;
    //А вот тут сложно чего-то
    return p;
}

void PipeGetInformation(Pipe& p)
{
    cout << "Pipe name: " << p.Name << endl;
    cout << "Pipe length: " << p.Length << endl;
    cout << "Pipe diameter: " << p.Diameter << endl;
    cout << "InRepair state: " << p.InRepair << endl;
}

void EditInRepair(Pipe& p)
{
    p.InRepair = not(p.InRepair);
}

int main()
{
    Pipe p = CreatePipe();
    PipeGetInformation(p);
    EditInRepair(p);
    PipeGetInformation(p);
    return 0;
}


