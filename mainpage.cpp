#include<iostream>
#include<string>
#include<Windows.h>
#include"adminf.h"
#include"student.h"
//#include"adminInterface.h"

using namespace std;

//void mainmenu(void);

// void mainmenu()
// {
//     system("cls");

//     int role;
//     cout << "\n\n\n\n\n\t\t\t\t\t";
//     cout << "\n\n\n\t\t\t\t\t1, Log in as Admin";
//     cout << "\n\n\n\t\t\t\t\t2, Log in as student";
//     cout << "\n\n\n\t\t\t\t\tEnter your choice";

//     do
//     {
//         cin >> role;

//         if(role == 1){
//             cout<< "Admin";
//         }
//         if(role == 2){
//             cout<< "Student";
//         }
//         else{
//             cout<<"Wrong choice";
//         }
//     }
// }


void passwordVerification()
{
    system("cls");

    int password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tStudent management system";
    cout << "\n\n\n\t\t\t\t\t1, Log in as Admin";
    cout << "\n\n\n\t\t\t\t\t2, Log in as student";
    cout << "\n\n\n\t\t\t\t\t3, Exit";
    cout << "\n\n\n\t\t\t\t\tEnter your choice: ";

    do
    {
        cin >> password;

        if (password == 1)
        {
            system("cls");
            // cout << "\n\n\n\n\n\t\t"
            //      << "admin";
            //cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            adminf();
        }

        if (password == 2)
        {
            system("cls");
            //cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tstudent";
            studentLogin_account();

            // for (int i = 0; i < 4; i++)
            // {

            //     Sleep(1000); // 1 second pause;
            //     cout << ".";
            // }

            // exit(0);
        }
        if(password == 3){
            for (int i = 0; i < 4; i++)
            {

                Sleep(1000); // 1 second pause;
                cout << ".";
            }
            return;
        }

    }
    while(password == 3);//{ cout<<"wrong choice";}

}




int main(){
    system("color 9F");

    passwordVerification();
    //mainmenu();
    return 0;
}