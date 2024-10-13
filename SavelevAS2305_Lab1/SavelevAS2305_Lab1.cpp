#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"
#include "InputAndOutput.h"

using namespace std;

void MainMenu()
{
    cout << "1. Open pipe menu" << endl
        << "2. Open station menu" << endl
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
    cout << "1. Create pipe" << endl
        << "2. Filter pipes" << endl
        << "0. Back" << endl
        << "Choose action: ";
}

void StationMenu()
{
    cout << "1. Create station" << endl
        << "2. Filter stations" << endl
        << "0. Back" << endl
        << "Choose action: ";
}


int main()
{
    Pipe p;
    CompressorStation s;

    unordered_map<int, Pipe> Pipes;
    unordered_map<int, CompressorStation> Stations;

    unordered_map<int, Pipe> FilteredPipes;
    unordered_map<int, CompressorStation> FilteredStations;

    while (1)
    {
        MainMenu();
        switch (GetCorrectNumber(0, 7))
        {
            //Input pipe
            case 1:
            {
                while (1)
                {
                    PipeMenu();
                    int PipeSelection;
                    PipeSelection = GetCorrectNumber(0, 2);

                    if (PipeSelection == 0)
                        break;
                    switch (PipeSelection)
                    {
                        case 1:
                            CreatePipe(Pipes);
                            break;
                        case 2:
                            FilterPipes(Pipes, FilteredPipes);
                            break;
                        default:
                            cout << "Wrong action" << endl << endl;
                    }
                }
                break;
            }
            //Input compressor station
            case 2:
            {
                while (1)
                {
                    StationMenu();
                    int StationSelection;
                    StationSelection = GetCorrectNumber(0, 2);

                    if (StationSelection == 0)
                        break;
                    switch (StationSelection)
                    {
                    case 1:
                        CreateCompressorStation(Stations);
                        break;
                    case 2:
                        FilterStations(Stations, FilteredStations);
                        break;
                    default:
                        cout << "Wrong action" << endl << endl;
                    }
                }
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


