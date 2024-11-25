#include "../include/scheduler.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Scheduler::loadSchedule(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Failed to open schedule file: " << filename << "\n";
        return false;
    }

    std::string line;
    // Skip header
    std::getline(file, line);
   
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> row;
       
        while(std::getline(ss, item, ',')) {
            row.push_back(item);
        }
       
        if(row.size() >= 6) {
            trains.emplace_back(
                std::stoi(row[0]), // id
                std::stoi(row[1]), // priority
                row[4],           // entry_point
                row[5]            // exit_point
            );
        }
    }
   
    return true;
}

Train* Scheduler::getNextTrain() {
    if(current_index >= trains.size()) {
        return nullptr;
    }
    return &trains[current_index++];
}

void Scheduler::updateSchedule() {
    // Update schedule logic here
}