#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"
#include "InputAndOutput.h"

using namespace std;

int main()
{
    unordered_map<int, Pipe> Pipes;
    unordered_map<int, CompressorStation> Stations;

    while (1)
    {
        MainMenu();
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            PipeMenu();

            switch (GetCorrectNumber(0, 2))
            {
            case 1:
            {
                CreatePipe(Pipes);
                break;
            }
            case 2:
            {
                if (Pipes.empty())
                {
                    cout << "There is no pipes to interact with" << endl << endl;
                }
                else
                    ChooseAndFilterPipes(Pipes);
                break;
            }
            case 0:
                break;
            }
        break;
        }
            //Input compressor station
        case 2:
        {
            StationMenu();

            switch (GetCorrectNumber(0, 2))
            {
            case 1:
            {
                CreateCompressorStation(Stations);
                break;
            }
            case 2:
            {
                if (Stations.empty())
                {
                    cout << "There is no stations to interact with" << endl << endl;
                }
                else
                    ChooseAndFilterStations(Stations);
                break;
            }
            case 0:
                break;
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
                //p.EditPipeInRepair();
                break;
            }
            //Edit amount of working workshops of compressor station
            case 5:
            {
                //s.EditCompressorStationWorkhopsInWork();
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


