#include "Utils.h"

using namespace std;

void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type number from " << min << " to " << max << ": ";
    }
    cout << endl;
    return x;
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

unordered_map<int, Pipe> EditPipes(unordered_map<int, Pipe>& ChoosedPipes, unordered_map<int, Pipe>& Pipes)
{
    if (ChoosedPipes.size() == 0)
    {
        cout << "There is no pipes to edit" << endl << endl;
    }

    else
    {
        for (auto& pipe : ChoosedPipes)
        {
            Pipes.at(pipe.second.GetId()).EditPipeInRepair();
        }
        cout << "Pipe InRepair state successfully changed" << endl << endl;
    }
 
    return Pipes;
}

unordered_map<int, CompressorStation> EditStations(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations, const char sign)
{
    if (ChoosedStations.size() == 0)
    {
        cout << "There is no stations to edit" << endl << endl;
    }

    else
    {
        for (auto& station : ChoosedStations)
        {
            Stations.at(station.second.GetId()).EditWorkingWorkshops(sign);
        }
        cout << "Amount of working workstations successfully edited" << endl << endl;
    }

    return Stations;
}

unordered_map<int, Pipe> ChoosePipe(unordered_map<int, Pipe>& ChoosedPipes, unordered_map<int, Pipe>& Pipes)
{
    cout << "Enter an id of pipe to choose: ";
    int ChoosedId = GetCorrectNumber(1, int(Pipes.size()));
    if (Pipes.contains(ChoosedId))
    {
        ChoosedPipes.emplace(Pipes.at(ChoosedId).GetId(), Pipes.at(ChoosedId));
        cout << "Pipe successfully added" << endl << endl;
    }
    else
        cout << "Therse is no pipe with this id" << endl << endl;
    return ChoosedPipes;
}

unordered_map<int, CompressorStation> ChooseStation(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations)
{
    cout << "Enter an id of pipe to choose: ";
    int ChoosedId = GetCorrectNumber(1, int(Stations.size()));
    if (Stations.contains(ChoosedId))
    {
        ChoosedStations.emplace(Stations.at(ChoosedId).GetId(), Stations.at(ChoosedId));
        cout << "Pipe successfully added" << endl << endl;
    }
    else
        cout << "Therse is no pipe with this id" << endl << endl;
    return ChoosedStations;
}

unordered_map<int, Pipe> DeletePipes(unordered_map<int, Pipe>& ChoosedPipes, unordered_map<int, Pipe>& Pipes)
{
    if (ChoosedPipes.size() == 0)
    {
        cout << "There is no pipes to delete" << endl << endl;
    }

    else
    {
        for (auto& pipe : ChoosedPipes)
        {
            Pipes.erase(pipe.second.GetId());
        }
        cout << "Pipes successfully deleted" << endl << endl;
    }
    ChoosedPipes.clear();
    return Pipes;
}

unordered_map<int, CompressorStation> DeleteStations(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations)
{
    if (ChoosedStations.size() == 0)
    {
        cout << "There is no pipes to delete" << endl << endl;
    }

    else
    {
        for (auto& station : ChoosedStations)
        {
            Stations.erase(station.second.GetId());
        }
        cout << "Pipes successfully deleted" << endl << endl;
    }
    ChoosedStations.clear();
    return Stations;
}

void ClearChoosedPipes(unordered_map<int, Pipe>& ChoosedPipes)
{
    ChoosedPipes.clear();
    cout << "Filter successfully cleraed" << endl << endl;
}

void ClearChoosedStations(unordered_map<int, CompressorStation>& ChoosedStations)
{
    ChoosedStations.clear();
    cout << "Filter successfully cleraed" << endl << endl;
}