#include <iostream>
#include <fstream>
#include <string>
#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"

using namespace std;

void PrintMenu()
{
    cout << "1. Open pipe menu" << endl
        << "2. Input compressor station" << endl
        << "3. Print pipe and compressor station" << endl
        << "4. Edit InRepair state of pipe" << endl
        << "5. Edit amount of working workshops of compressor station" << endl
        << "6. Save objects to file" << endl
        << "7. Load objects from file" << endl
        << "0. Exit" << endl
        << "Choose action: ";
}


int main()
{
    Pipe p;
    CompressorStation s;

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
                cin >> s;
                break;
            }
            //Print pipe and compressor station
            case 3:
            {
                cout << p;
                cout << s;
                break;
            }
            //Edit InRepair state of pipe
            case 4:
            {
                p.EditPipeInRepair();
                break;
            }
            //Edit amount of working workshops of compressor station
            case 5:
            {
                s.EditCompressorStationWorkhopsInWork();
                break;
            }
            //Save objects to file
            case 6:
            {
                ofstream fout;
                fout.open("data.txt", ios::out);
                if (fout.is_open())
                {
                    fout << p;
                    fout << s;
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
                    fin >> s;
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


