#ifndef ADMINF_H
#define ADMINF_H

#include<string>
#include<iostream>
#include<Windows.h>
#include"adminInterface.h"

using namespace std;

void adminLogin(){
    string name;
    string password;
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tStudent management system";
    cout<<"\n\n\t\t\t\t\tAdmin Login";
    cout<<"\n\n\n\t\t\t\t\tUser's name: ";
    cin >> name;
    cout<<"\n\n\n\t\t\t\t\tPassword: ";
    cin >> password;
    if(name == "name" && password == "password" ){
        system("cls");
        adminInterface();
    }
    else
    {
        system("cls");
        MessageBox(NULL, "Wrong name or password!", "Error", MB_OK);
        adminLogin();
    }
}

#endif
