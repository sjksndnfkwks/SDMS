#include "delete.h"

CSVManager::CSVManager() {
    filePath_ = "..\\res\\Data.csv";
    readCSV();
}

CSVManager::~CSVManager() {
    writeCSV();
}

void CSVManager::readCSV() {
    std::ifstream file(filePath_);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath_ << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        csvData_.push_back(split(line, ','));
    }
    file.close();
}


void CSVManager::deleteByIndex(int index) {
    if (index >= 0 && index < csvData_.size()) {
        csvData_.erase(csvData_.begin() + index);
        writeCSV();
        std::cout << "\n\t\t\t\t\tSuccessfully deleted!\n";
        Sleep(2000);
        return;
    }
    else{
        std::cout << "\n\t\t\t\t\tNot found!\n";
        Sleep(2000);
        return;
    }
}


void CSVManager::deleteByField(int fieldIdx, const std::string& name) {
    bool found = false;
    for (auto it = csvData_.begin(); it != csvData_.end();) {
        if ((*it)[fieldIdx] == name) {
            it = csvData_.erase(it);
            found = true;
        } else {
            ++it;
        }
    }
    if (found){
        writeCSV();
        std::cout << "\n\t\t\t\t\tSuccessfully deleted!\n";
        Sleep(1500);
    }
    else{
        std::cout << "\n\t\t\t\t\tNot found!\n";
        Sleep(1500);
    }
    return;
}


std::vector<std::string> CSVManager::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void CSVManager::writeCSV() {
    std::ofstream file(filePath_);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath_ << std::endl;
        return;
    }

    for (const auto& row : csvData_) {
        for (const auto& cell : row) {
            file << cell << ',';
        }
        file << '\n';
    }

    file.close();
}
