#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Student {
    std::string name;
    int studentId;
    std::string gender;
    int age;
    std::string major;
    std::string college;
    std::string password;
};

std::vector<Student> database;

void addData() {
    Student newStudent;
    std::cout << "\n\n\n\t\t\t\t\tEnter name: ";
    std::cin >> newStudent.name;

    while (true) {
        std::cout << "\n\n\n\t\t\t\t\tEnter student ID (integer only): ";
        if (std::cin >> newStudent.studentId) {
            break;
        } else {
            std::cout << "\n\n\n\t\t\t\t\tInvalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
        }
    }

    std::cout << "\n\n\n\t\t\t\t\tEnter gender: ";
    std::cin >> newStudent.gender;

    while (true) {
        std::cout << "\n\n\n\t\t\t\t\tEnter age (integer only): ";
        if (std::cin >> newStudent.age) {
            break;
        } else {
            std::cout << "\n\n\n\t\t\t\t\tInvalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "\n\n\n\t\t\t\t\tEnter major: ";
    std::cin >> newStudent.major;
    std::cout << "\n\n\n\t\t\t\t\tEnter college: ";
    std::cin >> newStudent.college;
    std::cout << "\n\n\n\t\t\t\t\tEnter password: ";
    std::cin >> newStudent.password;

    database.push_back(newStudent);
}


void deleteData(int studentId) {
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->studentId == studentId) {
            database.erase(it);
            return;
        }
    }
}

void modifyData() {
    int studentId;
    while (true) {
        std::cout << "\n\n\n\t\t\t\t\tEnter student ID to modify (integer only): ";
        if (std::cin >> studentId) {
            break;
        } else {
            std::cout << "\n\n\n\t\t\t\t\tInvalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    for (auto& student : database) {
        if (student.studentId == studentId) {
            std::string input;
            std::cout << "\n\n\n\t\t\t\t\tModify name? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                std::cout << "\n\n\n\t\t\t\t\tModified name: ";
                std::cin >> student.name;
            }

            std::cout << "\n\n\n\t\t\t\t\tModify gender? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                std::cout << "\n\n\n\t\t\t\t\tModified gender: ";
                std::cin >> student.gender;
            }

            std::cout << "\n\n\n\t\t\t\t\tModify age? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                while (true) {
                    std::cout << "\n\n\n\t\t\t\t\tModified age (integer only): ";
                    if (std::cin >> student.age) {
                        break;
                    } else {
                        std::cout << "\n\n\n\t\t\t\t\tInvalid input. Please enter an integer." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }

            std::cout << "\n\n\n\t\t\t\t\tModify major? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                std::cout << "\n\n\n\t\t\t\t\tModified major: ";
                std::cin >> student.major;
            }

            std::cout << "\n\n\n\t\t\t\t\tModify college? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                std::cout << "\n\n\n\t\t\t\t\tModified college: ";
                std::cin >> student.college;
            }

            std::cout << "\n\n\n\t\t\t\t\tModify password? (Y/N): ";
            std::cin >> input;
            if (input == "Y") {
                std::cout << "\n\n\n\t\t\t\t\tModified password: ";
                std::cin >> student.password;
            }

            return;
        }
    }
    std::cout << "\n\n\n\t\t\t\t\tStudent ID not found." << std::endl;
}


void viewAll() {
    for (const auto& student : database) {
        std::cout << "\n\n\n\t\t\t\t\tName: " << student.name << ", Student ID: " << student.studentId
                  << ", Gender: " << student.gender << ", Age: " << student.age
                  << ", Major: " << student.major << ", College: " << student.college
                  << ", Password: " << student.password << std::endl;
    }
}

void adminInterface() {
    while (true) {
        int choice;
        std::cout << "\n\n\n\t\t\t\t\tAdmin Menu: \n"
                  << "\n\n\n\t\t\t\t\t1. Add data\n"
                  << "\n\n\n\t\t\t\t\t2. Delete data\n"
                  << "\n\n\n\t\t\t\t\t3. Modify data\n"
                  << "\n\n\n\t\t\t\t\t4. View all data\n"
                  << "\n\n\n\t\t\t\t\t5. Exit\n"
                  << "\n\n\n\t\t\t\t\tEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addData();
                break;
            case 2:
                int studentId;
                std::cout << "\n\n\n\t\t\t\t\tEnter Student ID to delete: ";
                std::cin >> studentId;
                deleteData(studentId);
                break;
            case 3:
                modifyData();
                break;
            case 4:
                viewAll();
                break;
            case 5:
                return;
            default:
                std::cout << "\n\n\n\t\t\t\t\tInvalid choice, please try again." << std::endl;
        }
    }
}