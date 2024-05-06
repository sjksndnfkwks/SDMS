#include "student.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstdio> 


using namespace std;

static std::vector<std::string> splitString(const std::string& s)
{
    char delimiter = ',';
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<vector<string>> readDataCSV(){
    vector<vector<string>> data;
    fstream file("..\\res\\Data.csv");
    if(!file.is_open()){
        cout<<"\n\n\n\t\t\t\tFailed to open file: Data.csv"<<endl;
        return data;
    }

    string line;
    while(getline(file, line)){
        vector<string> lineData = splitString(line);
        data.push_back(lineData);
    }

    file.close();
    return data;
}

// Display student information based on their name
void viewStudentInformation(const string &studentID, const string &studentName, const vector<vector<string>> &data) {
    system("cls");
    cout << "\n\n\n\n" << endl;

    bool found = false;
    cout << "   " << left << setw(12) << "Name" << setw(12) << "Student_ID" << setw(12) << "Gender" 
         << setw(12) << "Age" << setw(12) << "Major" << setw(12) << "College" 
         << setw(12) << "Password" << setw(12) << "Job" << endl;

    for (const auto& row : data)
    {
        if (row[1] == studentID)
        {
            found = true;
            cout << "   ";
            for (const auto& col : row)
            {
                cout << left << setw(12) << col;
            }
            cout << endl;
        }
    }

    if (!found) {
        cout << "\n\n\n\t\t\t\tSorry, we can't find student with ID " << studentID << endl;
    }

    cout << "\n\n\n\t\t\t\tPress any key to go back.";
    cin.ignore(); // Ignore the newline left in the input buffer
    cin.get(); // Wait for user input
    studentInterface(studentID, studentName);
}

void writeDataToCSV(const vector<vector<string>>& data) {
    ofstream file("../res/Data.csv");
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); i++) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

void changePassword(const string &studentID, const string &studentName, vector<vector<string>>& data) {
    system("cls");
    string newPassword;
    cout << "\n\n\n\t\t\t\tEnter new password: ";
    if(cin.peek() == '\n') cin.ignore();
    getline(cin, newPassword);

    bool found = false;
    for (auto& row : data) {
        if (row[1] == studentID) {
            row[6] = newPassword;  // Assuming the password is at index 6
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n\n\n\t\t\t\tPassword changed successfully!" << endl;
        writeDataToCSV(data); // Update the CSV file with new data
    } else {
        cout << "\n\n\n\t\t\t\tStudent not found!" << endl;
    }

    cout << "\n\n\n\t\t\t\tReturning to the main menu..." << endl;
    Sleep(1000); // Pause for 1 second
    studentInterface(studentID, studentName);
}

void studentInterface(const string &studentID, const string &studentName) {
    vector<vector<string>> data = readDataCSV();
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\tHello! " << studentName << endl;
    cout << "\n\n\n\t\t\t\t1: View personal information\n";
    cout << "\n\t\t\t\t2: Change password\n";
    cout << "\n\t\t\t\t3: Change job\n";
    cout << "\n\t\t\t\t4: Exit\n";
    int choice;
    while (true)
    {
        cout << "\n\t\t\t\tEnter Choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        else
        {
            MessageBox(NULL, "Wrong Choice!", "Error", MB_OK | MB_ICONERROR);
        }
    }
    switch (choice)
    {
        case 1:
            viewStudentInformation(studentID, studentName, data);
            break;
        case 2:
            // Change password function to be implemented
            changePassword(studentID, studentName, data);
            break;
        case 3:
            changeJob(studentID, studentName, data);
            break;
        default:
            break;
    }
    writeDataToCSV(data);
}


void studentLogin() {
    system("cls");
    string studentID, studentName, password, truePassword;

    cout << "\n\n\n\n\n\t\t\t\tEnter your ID: ";
    cin >> studentID;
    // Get true Password from CSV file
    vector<vector<string>> data = readDataCSV();
    auto it = find_if(data.begin(), data.end(),
                      [&](const vector<string>& row) { return row[1] == studentID; });
    if (it != data.end()) {
        truePassword = it->at(6);
        studentName = it->at(0);
    }
    cout << "\n\n\n\n\n\t\t\t\tEnter your password: ";
    cin >> password;
    if (password == truePassword) {  // Example validation
        studentInterface(studentID, studentName);
    } else {
        MessageBox(NULL, "Wrong password!", "Error", MB_OK);
        studentLogin();  // Recursive call on wrong password
    }
}

void changeJob(const string &studentID, const string &studentName, vector<vector<string>>& data) {
    system("cls");
    string newJob;
    cout << "\n\n\n\t\t\t\tEnter new job: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, newJob);

    bool found = false;
    for (auto& row : data) {
        if (row[1] == studentID) {
            row[7] = newJob;  // Assuming the password is at index 6
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n\n\n\t\t\t\tPassword changed successfully!" << endl;
        writeDataToCSV(data); // Update the CSV file with new data
    } else {
        cout << "\n\n\n\t\t\t\tStudent not found!" << endl;
    }

    cout << "\n\n\n\t\t\t\tReturning to the main menu..." << endl;
    Sleep(1000); // Pause for 1 second
    studentInterface(studentID, studentName);
}