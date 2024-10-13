#include <iostream>
#include "Utils.h"

using namespace std;

void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}

unordered_map<int, Pipe> FilterPipes(unordered_map<int, Pipe>& UnfilteredPipes, unordered_map<int, Pipe>& FilterdPipes)
{   
    FilterdPipes.clear();
    if (UnfilteredPipes.size() == 0)
    {
        cout << "There is no objects to filter" << endl << endl;
    }

    else 
    {   
        string NameFilter;
        bool statement;
        cout << "1. Filter by name" << endl
            << "2. Filter by statemnt" << endl
            << "Choose action: ";

        switch (GetCorrectNumber(1, 2))
        {
        case 1:
            cout << "Enter a name to find: ";
            cin >> ws;
            getline(cin, NameFilter);
            cout << endl;

            for (auto& pipe : UnfilteredPipes)
            {
                if ((pipe.second.GetName()).find(NameFilter) != string::npos)
                {
                    FilterdPipes.emplace(pipe.second.GetId(), pipe.second);
                }
            }
            break;
            //ÈÌß
        case 2:
            //Â ÐÅÌÎÍÒÅ
            cout << "Enter a statement to find: ";
            statement = GetCorrectNumber(0, 1);
            cout << endl;

            for (auto& pipe : UnfilteredPipes)
            {
                if (pipe.second.GetStatement() == statement)
                {
                    FilterdPipes.emplace(pipe.second.GetId(), pipe.second);
                }
            }
            break;
            //Â ÐÅÌÎÍÒÅ
        }
        PrintPipes(FilterdPipes);
    }
    return FilterdPipes;
}

unordered_map<int, CompressorStation> FilterStations(unordered_map<int, CompressorStation>& UnfilteredStations, unordered_map<int, CompressorStation>& FilterdStations)
{
    FilterdStations.clear();
    if (UnfilteredStations.size() == 0)
    {
        cout << "There is no objects to filter" << endl << endl;
    }

    else
    {
        string NameFilter;
        float percent;
        cout << "1. Filter by name" << endl
            << "2. Filter by percent of unworking workshops" << endl
            << "Choose action: ";

        switch (GetCorrectNumber(1, 2))
        {
        case 1:
            cout << "Enter a name to find: ";
            cin >> ws;
            getline(cin, NameFilter);
            cout << endl;

            for (auto& station : UnfilteredStations)
            {
                if ((station.second.GetName()).find(NameFilter) != string::npos)
                {
                    FilterdStations.emplace(station.second.GetId(), station.second);
                }
            }
            break;
            //ÈÌß
        case 2:
            //Â ÐÅÌÎÍÒÅ
            cout << "Enter a percent of unworking workshops: ";
            percent = GetCorrectNumber(0, 100);

            for (auto& station : UnfilteredStations)
            {
                if (station.second.GetPercent() == percent)
                {
                    FilterdStations.emplace(station.second.GetId(), station.second);
                }
            }
            break;
            //Â ÐÅÌÎÍÒÅ
        }
        PrintCompressorStations(FilterdStations);
    }
    return FilterdStations;
}
