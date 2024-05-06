#ifndef MODIFY_DATA_H
#define MODIFY_DATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string studentID;
    string name;
    string gender;
    string age;
    string major;
    string college;
    string password;
    string job;
};

// Function to modify the element based on Student ID
void modifyElement()
{
    system("cls");

    // Read data from CSV file
    // Open the file
    ifstream file("..\\res\\Data.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    // Create a vector to store the data
    vector<Student> students;
    // Read and parse the CSV file
    string line;
    //getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        Student student;
        int column = 1;
        while (getline(ss, item, ',')) {
            switch (column) {
                case 1: student.name = item; break;
                case 2: student.studentID = item; break;
                case 3: student.gender = item; break;
                case 4: student.age = item; break;
                case 5: student.major = item; break;
                case 6: student.college = item; break;
                case 7: student.password = item; break;
                case 8: student.job = item; break;
                default: break;
            }
            column++;
        }
        students.push_back(student);
    }
    file.close();

    cout << "\n\n\n\t\t\t\t\tStudent management system" ;
    
    string studentID;

    while(true)
    {
        cout << "\n\n\n\t\t\t\t\tEnter Student ID to modify: ";
        cin >> studentID;
        // Find the student with the given ID
        auto it = find_if(students.begin(), students.end(), [&](const Student& s){return s.studentID == studentID;});
        if (it == students.end()) {
            MessageBox(NULL, "Student not found. Please enter a valid Student ID.", "Error", MB_OK);
        }
        else {
            break;
        }
    }


    cout << "\n\n\n\t\t\t\t\t1: name" << endl;
    cout << "\t\t\t\t\t2: studentID" << endl;
    cout << "\t\t\t\t\t3: gender" << endl;
    cout << "\t\t\t\t\t4: age" << endl;
    cout << "\t\t\t\t\t5: major" << endl;
    cout << "\t\t\t\t\t6: college" << endl;
    cout << "\t\t\t\t\t7: password" << endl;
    cout << "\t\t\t\t\t8: job" << endl;
    int columnIndex;
    while(true) {
        cout << "\n\n\n\t\t\t\t\tEnter column index to modify: ";
        cin >> columnIndex;
        if (columnIndex >= 1 && columnIndex <= 8) {
            break;
        }
        else{
            MessageBox(NULL, "Invalid column index. Please enter a number between 1 and 8.", "Error", MB_OK);
        }
    }
    cout << "\n\n\n\t\t\t\t\tEnter new value: ";
    string newValue;
    cin >> newValue;


    // Find and modify the element based on studentID
    for (auto& student : students) {
        if (student.studentID == studentID) {
            switch (columnIndex) {
                case 1: student.name = newValue; break;
                case 2: student.studentID = newValue; break; 
                case 3: student.gender = newValue; break;
                case 4: student.age = newValue; break;
                case 5: student.major = newValue; break;
                case 6: student.college = newValue; break;
                case 7: student.password = newValue; break;
                case 8: student.job = newValue; break;
                default: break;
            }
            break;
        }
    }

    // Write the modified data back to the file
    ofstream outFile("..\\res\\Data.csv");
    if (!outFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return;
    }

    // Write the header
    //outFile << "StudentID,Name,Gender,Age,Major,College,Password,Job" << endl;

    // Write the modified data
    for (const auto& student : students) {
        outFile << student.name << ","
                << student.studentID << ","
                << student.gender << ","
                << student.age << ","
                << student.major << ","
                << student.college << ","
                << student.password << ","
                << student.job << endl;
    }
    outFile.close();
    cout<<"\n\n\t\t\t\t\tSuccessfully modified!"<<endl;
    Sleep(1000);
    system("cls");
}

#endif