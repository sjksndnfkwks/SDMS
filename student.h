#include <iostream>
#include <stdlib.h>
#include <windows.h>

void manifestStudentGUI(const std::string studentName) 
{
    system("cls");
    std::cout << "\n\n\n\n\n\t\t\t\tHello!\t" << studentName << std::endl;
    std::cout << "\n\n\n\t\t\t\t\1. Modify personal information\n";
    std::cout << "\n\n\n\t\t\t\t\2. View personal information\n";
    std::cout << "\n\n\n\t\t\t\t\3. Exit\n";
    int choice;
    std::cout << "\n\n\n\t\t\t\tEnter Choice: ";
    std::cin >> choice;
}

void studentLogin_password(string studentName)
{
    std::string password;
    std::cout << "\n\n\n\n\n\t\t\t\tEnter your password: ";
    std::cin >> password;
    manifestStudentGUI(studentName);
}

void studentLogin_account()
{
    std::string studentName;
    std::cout << "\n\n\n\n\n\t\t\t\tEnter your account: ";
    std::cin >> studentName;
    studentLogin_password(studentName);
}