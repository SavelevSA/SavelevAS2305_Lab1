#include <iostream>
#include <fstream>
using namespace std;

void ClearInput();

//Pipe structure
struct Pipe
{
    string Name;
    int Length;
    int Diameter;
    bool InRepair;
};


//Compressor station structure
struct CompressorStation
{
    string Name;
    int AmountOfWorkshops;
    int WorkshopsInWork;
    int EfficiencyLevel;
};


//Functions of pipe
Pipe CreatePipe()
{
    Pipe p;

    cout << "Enter pipe name: ";
    cin >> p.Name;


    cout << "Enter pipe length: ";
    while (!(cin >> p.Length) || p.Length <= 0)
    {
        ClearInput();
        cout << "Enter pipe length: ";
    }


    cout << "Enter pipe diameter: ";
    while (!(cin >> p.Diameter) || p.Diameter <= 0)
    {
        ClearInput();
        cout << "Enter pipe diameter: ";
    }


    cout << "Set InRepair state: ";
    while (!(cin >> p.InRepair))
    {
        ClearInput();
        cout << "Set InRepair state: ";
    }
    cout << "\n";
    return p;
}

void PipeInformation(const Pipe& p)
{
    cout << "Pipe name: " << p.Name << endl;
    cout << "Pipe length: " << p.Length << endl;
    cout << "Pipe diameter: " << p.Diameter << endl;
    cout << "InRepair state: ", (p.InRepair==1) ? (cout << "In repair\n") : (cout << "In work\n");
    cout << "\n";
}

void EditPipeInRepair(Pipe& p)
{
    p.InRepair = !(p.InRepair);
    cout << "Pipe InRepair state successfully changed" << "\n" << "\n";
}


//Functions of compressor station
CompressorStation CreateCompressorStation()
{
    CompressorStation s;

    cout << "Enter compressor station name: ";
    cin >> s.Name;

    cout << "Enter amount of compressor station workshops: ";
    while (!(cin >> s.AmountOfWorkshops) || s.AmountOfWorkshops <= 0)
    {
        ClearInput();
        cout << "Enter amount of compressor station workshops: ";
    }

    cout << "Enter amount of working compressor station workshops: ";
    while (!(cin >> s.WorkshopsInWork) || s.WorkshopsInWork < 0 || s.WorkshopsInWork > s.AmountOfWorkshops)
    {
        ClearInput();
        cout << "Enter amount of working compressor station workshops: ";
    }

    cout << "Enter effeciency level of compressor station: ";
    while (!(cin >> s.EfficiencyLevel) || s.EfficiencyLevel < 0 || s.EfficiencyLevel > 100)
    {
        ClearInput();
        cout << "Enter effeciency level of compressor station: ";
    }
    cout << "\n";
    return s;
}

void CompressorStationInformation(const CompressorStation& s)
{
    cout << "Compressor station name: " << s.Name << endl;
    cout << "Amount of compressor station workshops: " << s.AmountOfWorkshops << endl;
    cout << "Amount of working compressor station workshops: " << s.WorkshopsInWork << endl;
    cout << "Effeciency level of compressor station: " << s.EfficiencyLevel << "%" << endl;
    cout << "\n";
}

void EditCompressorStationWorkhopsInWork(CompressorStation& s)
{
    int AddWorkshops;
    cout << "Enter change of working workstations: ";
    while (!(cin >> AddWorkshops) || (s.WorkshopsInWork + AddWorkshops) > s.AmountOfWorkshops
        || (s.WorkshopsInWork + AddWorkshops) < 0 || AddWorkshops == 0)
    {
        ClearInput();
        cout << "Enter change of working workstations: ";
    }
    s.WorkshopsInWork += AddWorkshops;
    cout << "Amount of working workstations successfully edited" << "\n" << "\n";
}


//Function for clear input
void ClearInput()
{
    cout << "Entered incorrect value\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}

void PrintMenu()
{
    cout << "1. Input pipe" << endl
        << "2. Input compressor station" << endl
        << "3. Print pipe and compressor station" << endl
        << "4. Edit InRepair state of pipe" << endl
        << "5. Edit amount of working workshops of compressor station" << endl
        << "6. Save objects to file" << endl
        << "7. Load objects from file" << endl
        << "0. Exit" << endl
        << "Choose action: ";
}


//Function for save pipe and compessor station to file
void SaveObjects(ofstream& fout, const Pipe& p, const CompressorStation& s)
{
    fout << p.Name << endl;
    fout << p.Length << endl;
    fout << p.Diameter << endl;
    fout << p.InRepair << endl;
    fout << s.Name << endl;
    fout << s.AmountOfWorkshops << endl;
    fout << s.WorkshopsInWork << endl;
    fout << s.EfficiencyLevel << endl;
}


//Two functions that load pipe and compressor station from file
Pipe LoadPipe(ifstream& fin)
{
    Pipe p;

    fin >> p.Name;
    fin >> p.Length;
    fin >> p.Diameter;
    fin >> p.InRepair;
    
    return p;
}

CompressorStation LoadCompressorStation(ifstream& fin)
{
    CompressorStation s;

    fin >> s.Name;
    fin >> s.AmountOfWorkshops;
    fin >> s.WorkshopsInWork;
    fin >> s.EfficiencyLevel;

    return s;
}


int main()
{
    Pipe p = { "None", 0, 0, 0 };
    CompressorStation s = { "None", 0, 0, 0 };

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
                p = CreatePipe();
                break;
            }
            //Input compressor station
            case 2:
            {
                s = CreateCompressorStation();
                break;
            }
            //Print pipe and compressor station
            case 3:
            {
                PipeInformation(p);
                CompressorStationInformation(s);
                break;
            }
            //Edit InRepair state of pipe
            case 4:
            {
                if (p.Name != "None")
                {
                    EditPipeInRepair(p);
                    break;
                }
                else
                {
                    cout << "Pipe does not exists" << endl << endl;
                    break;
                }
            }
            //Edit amount of working workshops of compressor station
            case 5:
            {
                if (s.Name != "None")
                {
                    EditCompressorStationWorkhopsInWork(s);
                    break;
                }
                else
                {
                    cout << "Compressor station does not exists" << endl << endl;
                    break;
                }
            }
            //Save objects to file
            case 6:
            {
                ofstream fout;
                fout.open("data.txt", ios::out);
                SaveObjects(fout, p, s);
                fout.close();
                cout << "Data successfully saved" << endl << endl;
                break;
            }
            //Load objects from file
            case 7:
            {
                ifstream fin;
                fin.open("data.txt", ios::in);
                p = LoadPipe(fin);
                s = LoadCompressorStation(fin);
                fin.close();
                cout << "Data successfully loaded" << endl << endl;
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


