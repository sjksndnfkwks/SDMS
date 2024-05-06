#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <Windows.h>

class CSVManager {
public:
    CSVManager();
    ~CSVManager();

    void readCSV();
    void deleteByIndex(int index);
    void deleteByField(int filedIdx, const std::string &name);

private:
    std::vector<std::string> split(const std::string &s, char delimiter);
    void writeCSV();

    std::string filePath_;
    std::vector<std::vector<std::string>> csvData_;
};

#endif // CSV_MANAGER_H
