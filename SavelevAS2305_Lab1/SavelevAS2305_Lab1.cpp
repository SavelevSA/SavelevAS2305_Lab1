#include "Pipe.h"
#include "CompressorStation.h"
#include "Utils.h"
#include "InputAndOutput.h"
#include <chrono>
#include <format>
using namespace std;

int main()
{
    redirect_output_wrapper cerr_out(cerr);
    string time = format("{:%d_%m_%Y %H_%M_%OS}", chrono::system_clock::now());
    ofstream logfile("log_" + time);
    if (logfile)
        cerr_out.redirect(logfile);


    unordered_map<int, Pipe> Pipes;
    unordered_map<int, CompressorStation> Stations;

    while (1)
    {
        MainMenu();
        switch (GetCorrectNumber(0, 5))
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
                    cout << "There is no pipes to interact with" << endl;
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
                    cout << "There is no stations to interact with" << endl;
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
            case 3:
            {
                PrintPipes(Pipes);
                PrintCompressorStations(Stations);
                break;
            }
            case 4:
            {
                SaveToFile(Pipes, Stations);
                break;
            }
            case 5:
            {
                LoadFromFile(Pipes, Stations);
                break;
            }
            //Exit
            case 0:
            {
                return 0;
            }
        }
    }
    return 0;
}


