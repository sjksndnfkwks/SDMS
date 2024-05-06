#include "viewData.h"

using namespace std;

// Implementation of utility function to split strings by delimiter
static std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = input.find(delimiter);
    
    while (end != std::string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    }
    
    result.push_back(input.substr(start));
    return result;
}


void viewChoice(){
    system("cls");
    int password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tStudent management system";
    cout << "\n\n\n\t\t\t\t\t1: See all data";
    cout << "\n\n\n\t\t\t\t\t2: Search by Name";
    cout << "\n\n\n\t\t\t\t\t3: Search by Student_ID";
    cout << "\n\n\n\t\t\t\t\t4: Admin Menu";
    while (true)
    {
        cout << "\n\n\n\t\t\t\t\tEnter your choice: ";
        cin >> password;
        if (password == 1 || password == 2 || password == 3 || password == 4){
            break;
        }
        else
        {
            MessageBox(NULL, "Invalid Choice!", "Error", MB_OK | MB_ICONERROR);
        }
    }

    do
    {
        if (password == 1)
        {
            system("cls");
            // cout << "\n\n\n\n\n\t\t"
            //      << "admin";
            //cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            viewData();
        }

        if (password == 2)
        {
            system("cls");
            //cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tstudent";
            string lo;
            cout << "\n\n\n\t\t\t\tStudent Name: ";
            cin >> lo; 
            viewName(lo);

            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }

            // exit(0);
        }
        if (password == 3)
        {
            system("cls");
            //cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tstudent";
            string lo;
            cout << "\n\n\n\t\t\t\tStudent ID: ";
            cin >> lo; 
            viewID(lo);

            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }

            // exit(0);
        }
        if(password == 4){
            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }
            return;
        }

    }
    while(password == 5);//{ cout<<"wrong choice";}
}

void viewData()
{
    system("cls");

    cout<<"\n\n\n\n"<<endl;

    fstream file("..\\res\\Data.csv");

    if (!file)
    {
        cout << "\n\n\n\t\t\tfail in opening the file";
    }

    string Name, Student_ID, Gender, Age, Major, College, Password, Job;
    //int i = 0;
    // cout << left << setw(12) << "Name" << setw(12) << "Student_ID" << setw(12) << "Gender" 
    //      << setw(12) << "Age" << setw(12) << "Major" << setw(12) << "College" 
    //      << setw(12) << "Password" << setw(12) << "Job" << endl;
    // cout<<endl;
    while (!file.eof()){
        cout<<"   ";
        string line;
        getline(file, line); 
        vector<string> info = splitString(line, ',');
        for(int j = 0; j < info.size(); j++){
            cout<< left << setw(12) <<info[j];
            // cout<<" "<<setw(5);
            //cout<< std::right << setw(8) <<info[j];
        }
        cout<<endl;
        cout<<endl;
        // getline(file, Name, ',');
        // getline(file, Student_ID, ',');
        // getline(file, Gender, ',');
        // getline(file, Age, ',');
        // getline(file, Major, ',');
        // getline(file, College, ',');
        // getline(file, Password, ',');
        // getline(file, Job, '\n');
        //cout<<line<<endl;
        //cout << Name << " \t " << Student_ID << "\t" << Gender << " \t" << Age << " \t" << Major << " \t" << College << " \t" << Password << " \t" << Job << endl;
        //cout << "  "<< i << "  "<<endl;
        //i++;
    }

    file.close();

    int ch;
    cout<<"\n\n\n\t\t\t\t1, Last Page"<<endl;
    cout<<"\n\t\t\t\t2, Admin Menu"<<endl;
    
    while (true)
    {
        cout<<"\n\t\t\t\tEnter your choice: ";
        cin>>ch;
        if (ch == 1 || ch == 2)
        {
            break;
        }
        else
        {
            MessageBox(NULL, "Wrong choice!", "Error", MB_OK);
        }
    }

    do
    {
        if (ch == 1)
        {
            system("cls");
            // cout << "\n\n\n\n\n\t\t"
            //      << "admin";
            //cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            viewChoice();
        }

        if(ch == 2){
            for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }
            return;
        }

    }
    while(ch == 5);//{ cout<<"wrong choice";}


}
void viewName(string lo)
{
    system("cls");

    string s = lo;

    cout<<"\n\n\n\n"<<endl;

    fstream file("..\\res\\Data.csv");

    if (!file)
    {
        cout << "\n\n\n\t\t\t\tfail in opening the file";
    }

    //string Name, Student_ID, Gender, Age, Major, College, Password, Job;
    int i = 0;
    cout << "   ";
    cout << left << setw(12) << "Name" << setw(12) << "Student_ID" << setw(12) << "Gender" 
         << setw(12) << "Age" << setw(12) << "Major" << setw(12) << "College" 
         << setw(12) << "Password" << setw(12) << "Job" << endl;
    cout<<endl;
    while (!file.eof()){
        cout<<"   ";
        string line;
        getline(file, line); 
        vector<string> info = splitString(line, ',');
        for(int j = 0; j < info.size(); j++){
            if(info[0]==s){
                cout << left << setw(12) << info[j];
                i = 1;
            }
        }
        cout<<endl;
    }

    file.close();

    if(i == 0){
        cout<<"\n\n\n\t\t\t\tSorry, we can't find student "<<lo<<endl;
    }

    int ch;
    cout<<"\n\n\n\t\t\t\t1, Last Page"<<endl;
    cout<<"\n\t\t\t\t2, Admin Menu"<<endl;

    while (true)
    {
        cout<<"\n\t\t\t\tEnter your choice: ";
        cin>>ch;
        if (ch == 1 || ch == 2)
        {
            break;
        }
        else
        {
            MessageBox(NULL, "Wrong choice!", "Error", MB_OK);
        }
    }

    do
    {

        if (ch == 1)
        {
            system("cls");
            // cout << "\n\n\n\n\n\t\t"
            //      << "admin";
            //cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            viewChoice();
        }

        if(ch == 2){
            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }
            return;
        }

    }
    while(ch == 5);//{ cout<<"wrong choice";}

}

void viewID(string lo)
{
    system("cls");

    string s = lo;

    cout<<"\n\n\n\n"<<endl;

    fstream file("..\\res\\Data.csv");

    if (!file)
    {
        cout << "\n\n\n\t\t\tfail in opening the file";
    }

    //string Name, Student_ID, Gender, Age, Major, College, Password, Job;
    int i = 0;
    cout << "   ";
    cout << left << setw(12) << "Name" << setw(12) << "Student_ID" << setw(12) << "Gender" 
         << setw(12) << "Age" << setw(12) << "Major" << setw(12) << "College" 
         << setw(12) << "Password" << setw(12) << "Job" << endl;
    while (!file.eof()){
        cout<<"   ";
        string line;
        getline(file, line); 
        vector<string> info = splitString(line, ',');
        for(int j = 0; j < info.size(); j++){
            if(info[1]==s){
                cout << left << setw(12) << info[j];
                i = 1;
            }
        }
        cout<<endl;
    }

    file.close();

    if(i == 0){
        cout<<"\n\n\n\t\t\t\tSorry, we can't find student "<<lo<<endl;
    }

    int ch;
    cout<<"\n\n\n\t\t\t\t1, Last Page"<<endl;
    cout<<"\n\t\t\t\t2, Admin Menu"<<endl;
    
    while (true)
    {
        cout<<"\n\t\t\t\tEnter your choice: ";
        cin>>ch;
        if (ch == 1 || ch == 2)
        {
            break;
        }
        else
        {
            MessageBox(NULL, "Wrong choice!", "Error", MB_OK);
        }
    }

    do
    {

        if (ch == 1)
        {
            system("cls");
            // cout << "\n\n\n\n\n\t\t"
            //      << "admin";
            //cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            viewChoice();
        }

        if(ch == 2){
            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }
            return;
        }

    }
    while(ch == 5);//{ cout<<"wrong choice";}

}