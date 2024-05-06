#include<iostream>
#include<string>
#include<Windows.h>
#include"adminf.h"
#include"student.h"

using namespace std;

void mainPage()
{
    system("cls");

    string choice;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tStudent management system";
    cout << "\n\n\n\t\t\t\t\t1: Log in as Admin";
    cout << "\n\n\n\t\t\t\t\t2: Log in as student";
    cout << "\n\n\n\t\t\t\t\t3: Exit";

    while (true)
    {
        cout << "\n\n\n\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        if (choice == "1")
        {
            system("cls");
            adminLogin();
            break;
        }
        else if (choice == "2")
        {
            system("cls");
            studentLogin();
            break;
        }
        else if(choice == "3"){
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000); // 1 second pause;
                cout << "...";
            }
            break;
        }
        else
        {
            MessageBox(NULL, "Wrong choice!", "Error", MB_OK);
        }
    }
}


int main(){
    system("color 9F");

    mainPage();
    //mainmenu();
    return 0;
}