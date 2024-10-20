#include "Utils.h"

using namespace std;

void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}

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
        << "2. Filter menu" << endl
        << "0. Back" << endl
        << "Choose action: ";
}

void StationMenu()
{
    cout << "1. Create compressor station" << endl
        << "2. Filter menu" << endl
        << "0. Back" << endl
        << "Choose action: ";
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

//unordered_map<int, CompressorStation> FilterStations(unordered_map<int, CompressorStation>& UnfilteredStations, unordered_map<int, CompressorStation>& FilterdStations)
//{
//    FilterdStations.clear();
//    if (UnfilteredStations.size() == 0)
//    {
//        cout << "There is no objects to filter" << endl << endl;
//    }
//
//    else
//    {
//        string NameFilter;
//        float percent;
//        cout << "1. Filter by name" << endl
//            << "2. Filter by percent of unworking workshops" << endl
//            << "Choose action: ";
//
//        switch (GetCorrectNumber(1, 2))
//        {
//        case 1:
//            cout << "Enter a name to find: ";
//            cin >> ws;
//            getline(cin, NameFilter);
//            cout << endl;
//
//            for (auto& station : UnfilteredStations)
//            {
//                if ((station.second.GetName()).find(NameFilter) != string::npos)
//                {
//                    FilterdStations.emplace(station.second.GetId(), station.second);
//                }
//            }
//            break;
//            //ÈÌß
//        case 2:
//            //Â ÐÅÌÎÍÒÅ
//            cout << "Enter a percent of unworking workshops: ";
//            percent = GetCorrectNumber(0, 100);
//
//            for (auto& station : UnfilteredStations)
//            {
//                if (station.second.GetPercent() == percent)
//                {
//                    FilterdStations.emplace(station.second.GetId(), station.second);
//                }
//            }
//            break;
//            //Â ÐÅÌÎÍÒÅ
//        }
//        PrintCompressorStations(FilterdStations);
//    }
//    return FilterdStations;
//}
//
//unordered_map<int, CompressorStation> EditStations(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations, const char sign)
//{
//    if (ChoosedStations.size() == 0)
//    {
//        cout << "There is no stations to edit" << endl << endl;
//    }
//
//    else
//    {
//        for (auto& station : ChoosedStations)
//        {
//            Stations.at(station.second.GetId()).EditWorkingWorkshops(sign);
//        }
//        cout << "Amount of working workstations successfully edited" << endl << endl;
//    }
//
//    return Stations;
//}
//
//unordered_map<int, CompressorStation> ChooseStation(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations)
//{
//    cout << "Enter an id of pipe to choose: ";
//    int ChoosedId = GetCorrectNumber(1, int(Stations.size()));
//    if (Stations.contains(ChoosedId))
//    {
//        ChoosedStations.emplace(Stations.at(ChoosedId).GetId(), Stations.at(ChoosedId));
//        cout << "Pipe successfully added" << endl << endl;
//    }
//    else
//        cout << "Therse is no pipe with this id" << endl << endl;
//    return ChoosedStations;
//}
//
//unordered_map<int, CompressorStation> DeleteStations(unordered_map<int, CompressorStation>& ChoosedStations, unordered_map<int, CompressorStation>& Stations)
//{
//    if (ChoosedStations.size() == 0)
//    {
//        cout << "There is no pipes to delete" << endl << endl;
//    }
//
//    else
//    {
//        for (auto& station : ChoosedStations)
//        {
//            Stations.erase(station.second.GetId());
//        }
//        cout << "Pipes successfully deleted" << endl << endl;
//    }
//    ChoosedStations.clear();
//    return Stations;
//}

void ClearChoosedPipes(set<int>& PipeIds)
{
    PipeIds.clear();
    cout << "Filter successfully cleraed" << endl << endl;
}

void ClearChoosedStations(set<int>& StationIds)
{
    StationIds.clear();
    cout << "Filter successfully cleraed" << endl << endl;
}

//Pipes
template<typename T>
using FilterP = bool(*)(Pipe& p, T param);
bool CheckByName(Pipe& p, string param)
{
    return !p.GetName().find(param);
}
bool CheckByStatement(Pipe& p, bool param)
{
    return p.GetStatement() == param;
}

template<typename T>
void FindPipesByFilter(unordered_map<int, Pipe>& Pipes, FilterP<T> f, T param, set<int>& PipeIds)
{
    for (auto& p : Pipes)
    {
        if (f(p.second, param))
        {
            PipeIds.emplace(p.first);
            cout << p.second;
        }
    }
}


using EADP = void(*)(unordered_map<int, Pipe>& Pipes, set<int>& PipeIds);
void EditPipe(unordered_map<int, Pipe>& Pipes, set<int>& PipeIds)
{
    for (auto& id : PipeIds)
    {
        Pipes[id].EditPipeInRepair();
    }
}
void Delete(unordered_map<int, Pipe>& Pipes, set<int>& PipeIds)
{
    for (auto& id : PipeIds)
    {
        Pipes.erase(id);
    }
}

void EditAndDelete(unordered_map<int, Pipe>& Pipes, EADP f, set<int>& PipeIds)
{
    if (PipeIds.empty())
    {
        cout << "There is no choosed pipes to interact with" << endl << endl;
    }
    else
    {
        f(Pipes, PipeIds);
    }
}


void ChooseAndFilterPipes(unordered_map<int, Pipe>& Pipes)
{
    set<int> PipeIds;
    string NameFilter;
    bool statement;
    bool cycle = 1;
    while (cycle)
    {
        cout << "1. Filter by name" << endl
            << "2. Filter by InRepair statement" << endl
            << "3. Select by id" << endl
            << "4. Delete selected" << endl
            << "5. Edit TnRapair statement of selected" << endl
            << "6. Print choosed pipes" << endl
            << "7. Clear filter" << endl
            << "0. Back" << endl
            << "Choose action: ";
        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            cout << "Enter a name to find: ";
            cin >> ws;
            getline(cin, NameFilter);
            cout << endl;
            FindPipesByFilter(Pipes, CheckByName, NameFilter, PipeIds);
            break;
        }
        case 2:
        {
            cout << "Enter a statement to find: ";
            statement = GetCorrectNumber(0, 1);
            cout << endl;
            FindPipesByFilter(Pipes, CheckByStatement, statement, PipeIds);
            break;
        }
        case 3:
        {
            cout << "Enter an id of pipe to choose: ";
            int ChoosedId = GetCorrectNumber(1, int(Pipes.size()));
            if (Pipes.contains(ChoosedId))
            {
                PipeIds.emplace(ChoosedId);
                cout << "Pipe successfully selected" << endl << endl;
            }
            else
                cout << "Therse is no pipe with this id" << endl << endl;
            break;
        }
        case 4:
        {
            EditAndDelete(Pipes, Delete, PipeIds);
            cout << "Pipes successfully deleted" << endl << endl;
            PipeIds.clear();
            break;
        }
        case 5:
        {
            EditAndDelete(Pipes, EditPipe, PipeIds);
            cout << "InRepair state of pipes successfully changed" << endl << endl;
            break;
        }
        case 6:
        {
            if (PipeIds.empty())
                cout << "There is no selected pipes" << endl << endl;
            else
            {
                for (auto& id : PipeIds)
                    cout << Pipes[id];
            }
            break;
        }
        case 7:
        {
            ClearChoosedPipes(PipeIds);
            break;
        }
        case 0:
            cycle = 0;
            break;
        }
    }
}


//Stations
template<typename T>
using FilterS = bool(*)(CompressorStation& s, T param);
bool CheckByName(CompressorStation& s, string param)
{
    return !s.GetName().find(param);
}
bool CheckByPercent(CompressorStation& s, int param)
{
    return s.GetPercent() == param;
}

template<typename T>
void FindStationsByFilter(unordered_map<int, CompressorStation>& Stations, FilterS<T> f, T param, set<int>& StationIds)
{
    for (auto& s : Stations)
    {
        if (f(s.second, param))
        {
            StationIds.emplace(s.first);
            cout << s.second;
        }
    }
}


using EADS = void(*)(unordered_map<int, CompressorStation>& Stations, set<int>& StationIds, const char sign);
void EditStations(unordered_map<int, CompressorStation>& Stations, set<int>& StationIds, const char sign)
{
    for (auto& id : StationIds)
    {
        Stations[id].EditWorkingWorkshops(sign);
    }
}
void DeleteS(unordered_map<int, CompressorStation>& Stations, set<int>& StationIds, const char sign)
{
    for (auto& id : StationIds)
    {
        Stations.erase(id);
    }
}

void EditAndDeleteS(unordered_map<int, CompressorStation>& Stations, EADS f, set<int>& StationIds, const char sign)
{
    if (StationIds.empty())
    {
        cout << "There is no choosed stations to interact with" << endl << endl;
    }
    else
    {
        f(Stations, StationIds, sign);
    }
}

void ChooseAndFilterStations(unordered_map<int, CompressorStation>& Stations)
{
    set<int> StationIds;
    string NameFilter;
    int percent = 0;
    bool cycle = 1;
    while (cycle)
    {
        cout << "1. Filter by name" << endl
            << "2. Filter by percent of unworking workshops" << endl
            << "3. Select by id" << endl
            << "4. Delete selected" << endl
            << "5. +1 working worksop to choosed stations" << endl
            << "6. -1 working worksop to choosed stations" << endl
            << "7. Print choosed stations" << endl
            << "8. Clear filter" << endl
            << "0. Back" << endl
            << "Choose action: ";
        switch (GetCorrectNumber(0, 8))
        {
        case 1:
        {
            cout << "Enter a name to find: ";
            cin >> ws;
            getline(cin, NameFilter);
            cout << endl;
            FindStationsByFilter(Stations, CheckByName, NameFilter, StationIds);
            break;
        }
        case 2:
        {
            cout << "Enter a percent to find: ";
            percent = GetCorrectNumber(0, 100);
            cout << endl;
            FindStationsByFilter(Stations, CheckByPercent, percent, StationIds);
            break;
        }
        case 3:
        {
            cout << "Enter an id of station to choose: ";
            int ChoosedId = GetCorrectNumber(1, int(Stations.size()));
            if (Stations.contains(ChoosedId))
            {
                StationIds.emplace(ChoosedId);
                cout << "Station successfully selected" << endl << endl;
            }
            else
                cout << "Therse is no station with this id" << endl << endl;
            break;
        }
        case 4:
        {
            EditAndDeleteS(Stations, DeleteS, StationIds, char("*"));
            cout << "Stations successfully deleted" << endl << endl;
            StationIds.clear();
            break;
        }
        case 5:
        {
            EditAndDeleteS(Stations, EditStations, StationIds, char("+"));
            cout << "Amount of working workstations successfully edited" << endl << endl;
            break;
        }
        case 6:
        {
            EditAndDeleteS(Stations, EditStations, StationIds, char("-"));
            cout << "Amount of working workstations successfully edited" << endl << endl;
            break;
        }
        case 7:
        {
            if (StationIds.empty())
                cout << "There is no selected pipes" << endl << endl;
            else
            {
                for (auto& id : StationIds)
                    cout << Stations[id];
            }
            break;
        }
        case 8:
        {
            ClearChoosedStations(StationIds);
            break;
        }
        case 0:
            cycle = 0;
            break;
        }
    }
}