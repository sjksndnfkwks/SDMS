#ifndef ADDDATA_H
#define ADDDATA_H

#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <Windows.h> 

using namespace std;

void addData() {
    system("cls");
    string name, id, gender, age, major, college, password, job;
    cout << "\n\n\n\t\t\t\tStudent management system";
    cout << "\n\n\n\t\t\t\t\t";
    cout << "\n\t\t\t\tPlease enter the student name:";
    if(cin.peek() == '\n') cin.ignore();
    getline(cin, name);
    cout << "\n\t\t\t\tPlease enter the student ID:";
    getline(cin, id);
    cout << "\n\t\t\t\tPlease enter the student gender:";
    getline(cin, gender);
    cout << "\n\t\t\t\tPlease enter the students' age:";
    getline(cin, age);
    cout << "\n\t\t\t\tPlease enter the student major:";
    getline(cin, major);
    cout << "\n\t\t\t\tPlease enter the college:";
    getline(cin, college);
    cout << "\n\t\t\t\tPlease enter the password:";
    getline(cin, password);
    cout << "\n\t\t\t\tPlease enter the job:";
    getline(cin, job);

    string fname = "..\\res\\Data.csv";
    ofstream outFile(fname, ios::app);  // Always append to the file

    if (!outFile.is_open()) {
        cout << "Error: Opening file error" << endl;
        exit(1);
    }

    outFile << name << ',' << id << ',' << gender << ',' << age << ',' 
            << major << ',' << college << ',' << password << ',' << job << endl;

    outFile.close();
    cout<<"\n\n\n\t\t\t\tSuccessfully added!";
    Sleep(2000);
    system("cls");
}

	
#endif