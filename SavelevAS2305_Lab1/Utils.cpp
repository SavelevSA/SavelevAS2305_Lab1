#include "Utils.h"

using namespace std;

void MainMenu()
{
    cout << endl << "1. Open pipe menu" << endl
        << "2. Open station menu" << endl
        << "3. Print pipes and compressor stations" << endl
        << "4. Save objects to file" << endl
        << "5. Load objects from file" << endl
        << "0. Exit" << endl
        << "Choose action: ";
}

void PipeMenu()
{
    cout << endl << "1. Create pipe" << endl
        << "2. Filter menu" << endl
        << "0. Back" << endl
        << "Choose action: ";
}

void StationMenu()
{
    cout << endl << "1. Create compressor station" << endl
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
    cerr << x << endl;
    return x;
}

void ClearChoosedPipes(unordered_set<int>& PipeIds)
{
    PipeIds.clear();
    cout << "Filter successfully cleraed" << endl;
}

void ClearChoosedStations(unordered_set<int>& StationIds)
{
    StationIds.clear();
    cout << "Filter successfully cleraed" << endl;
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
void FindPipesByFilter(unordered_map<int, Pipe>& Pipes, FilterP<T> f, T param, unordered_set<int>& PipeIds)
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


using EADP = void(*)(unordered_map<int, Pipe>& Pipes, unordered_set<int>& PipeIds);
void EditPipe(unordered_map<int, Pipe>& Pipes, unordered_set<int>& PipeIds)
{
    for (auto& id : PipeIds)
    {
        Pipes[id].EditPipeInRepair();
    }
}
void Delete(unordered_map<int, Pipe>& Pipes, unordered_set<int>& PipeIds)
{
    for (auto& id : PipeIds)
    {
        Pipes.erase(id);
    }
}

void EditAndDelete(unordered_map<int, Pipe>& Pipes, EADP f, unordered_set<int>& PipeIds)
{
    if (PipeIds.empty())
    {
        cout << endl << "There is no choosed pipes to interact with" << endl;
    }
    else
    {
        f(Pipes, PipeIds);
        if (f == EditPipe)
            cout << "InRepair state of pipes successfully changed" << endl;
        else
            cout << "Pipes successfully deleted" << endl;
        
    }
}


void ChooseAndFilterPipes(unordered_map<int, Pipe>& Pipes)
{
    unordered_set<int> PipeIds;
    string NameFilter;
    bool statement;
    bool cycle = 1;
    while (cycle)
    {
        cout << endl << "1. Filter by name" << endl
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
            INPUT_LINE(cin, NameFilter);
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
                cout << "Pipe successfully selected" << endl;
            }
            else
                cout << "Therse is no pipe with this id" << endl;
            break;
        }
        case 4:
        {
            EditAndDelete(Pipes, Delete, PipeIds);
            PipeIds.clear();
            break;
        }
        case 5:
        {
            EditAndDelete(Pipes, EditPipe, PipeIds);
            break;
        }
        case 6:
        {
            if (PipeIds.empty())
                cout << "There is no selected pipes" << endl;
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
void FindStationsByFilter(unordered_map<int, CompressorStation>& Stations, FilterS<T> f, T param, unordered_set<int>& StationIds)
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


using EADS = void(*)(unordered_map<int, CompressorStation>& Stations, unordered_set<int>& StationIds, const char sign);
void EditStations(unordered_map<int, CompressorStation>& Stations, unordered_set<int>& StationIds, const char sign)
{
    for (auto& id : StationIds)
    {
        Stations[id].EditWorkingWorkshops(sign);
    }
}
void DeleteS(unordered_map<int, CompressorStation>& Stations, unordered_set<int>& StationIds, const char sign)
{
    for (auto& id : StationIds)
    {
        Stations.erase(id);
    }
}

void EditAndDeleteS(unordered_map<int, CompressorStation>& Stations, EADS f, unordered_set<int>& StationIds, const char sign)
{
    if (StationIds.empty())
    {
        cout << endl << "There is no choosed stations to interact with" << endl;
    }
    else
    {
        f(Stations, StationIds, sign);
        if (f == DeleteS)
            cout << "Stations successfully deleted" << endl;
        else
            cout << "Amount of working workstations successfully edited" << endl;
    }
}

void ChooseAndFilterStations(unordered_map<int, CompressorStation>& Stations)
{
    unordered_set<int> StationIds;
    string NameFilter;
    int percent = 0;
    bool cycle = 1;
    while (cycle)
    {
        cout << endl << "1. Filter by name" << endl
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
            INPUT_LINE(cin, NameFilter);
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
                cout << "Station successfully selected" << endl;
            }
            else
                cout << "Therse is no station with this id" << endl;
            break;
        }
        case 4:
        {
            EditAndDeleteS(Stations, DeleteS, StationIds, char("*"));
            StationIds.clear();
            break;
        }
        case 5:
        {
            EditAndDeleteS(Stations, EditStations, StationIds, char("+"));
            break;
        }
        case 6:
        {
            EditAndDeleteS(Stations, EditStations, StationIds, char("-"));
            break;
        }
        case 7:
        {
            if (StationIds.empty())
                cout << "There is no selected pipes" << endl;
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