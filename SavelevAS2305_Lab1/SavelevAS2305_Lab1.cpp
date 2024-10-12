#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"
#include "InputAndOutput.h"

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

void PipeMenu()
{
    cout << "1. Create pipe" << endl;
}


int main()
{
    Pipe p;
    CompressorStation s;

    unordered_map<int, Pipe> Pipes;
    unordered_map<int, CompressorStation> Stations;

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
                CreatePipe(Pipes);
                break;
            }
            //Input compressor station
            case 2:
            {
                CreateCompressorStation(Stations);
                break;
            }
            //Print pipe and compressor station
            case 3:
            {
                PrintPipes(Pipes);
                PrintCompressorStations(Stations);
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
                SaveToFile(Pipes, Stations);
                break;
            }
            //Load objects from file
            case 7:
            {
                LoadFromFile(Pipes, Stations);
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


