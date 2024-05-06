#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<string>> readDataCSV();

// Display student information based on their name
void viewStudentInformation(const string &studentName, const string &studentID, const vector<vector<string>> &data);

void writeDataToCSV(const vector<vector<string>>& data);

void changePassword(const string &studentName, const string &studentID, vector<vector<string>>& data);

void studentInterface(const string &studentName, const string &studentID);

void studentLogin();

void changeJob(const string &studentName, const string &studentID, vector<vector<string>>& data);

#endif