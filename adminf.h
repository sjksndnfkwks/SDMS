#include<string>
#include<iostream>
#include<Windows.h>
#include"adminInterface.h"

using namespace std;

void adminf(){
    //system("cls");
    string name;
    string password;
    cout<<"\n\n\n\n\t\t\t\tUser's name: ";
    cin >> name;
    cout<<"\n\n\n\n\t\t\t\tPassword: ";
    cin >> password;
    if(name == "name" && password == "password" ){
        // cout << "Password: "<<endl;
        // cin >> password;
        // if(password=="password"){
        //     cout<<"next"<<endl;
        // }
        // else{
        //     cout<<"wrong password";
        // }
        //cout<<"next"<<endl;
        system("cls");
        adminInterface();
        // for (int i = 0; i < 4; i++)
        //     {

        //         Sleep(1000); // 1 second pause;
        //         cout << ".";
        //     }
    }
    else{
        cout<<"wrong"<<endl;
    }
}