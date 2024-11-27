#include "../include/scheduler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool Scheduler::loadSchedule(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Failed to open schedule file: " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip header
   
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
                row[2],           // arrival_time
                row[3],           // departure_time
                row[4],           // entry_point
                row[5]            // exit_point
            );
            pending_trains.push_back(trains.size() - 1);
        }
    }
    
    simulation_time = std::time(nullptr);
    sortPendingTrains();
    return true;
}

void Scheduler::sortPendingTrains() {
    std::sort(pending_trains.begin(), pending_trains.end(),
        [this](size_t a, size_t b) {
            if (trains[a].getArrivalTime() == trains[b].getArrivalTime()) {
                return trains[a].getPriority() > trains[b].getPriority();
            }
            return trains[a].getArrivalTime() < trains[b].getArrivalTime();
        });
}

Train* Scheduler::getNextTrain() {
    if(pending_trains.empty()) {
        return nullptr;
    }

    size_t next_index = pending_trains[0];
    if(trains[next_index].getArrivalTime() <= simulation_time) {
        pending_trains.erase(pending_trains.begin());
        return &trains[next_index];
    }
    
    return nullptr;
}

Train* Scheduler::getTrain(int id) {
    for(auto& train : trains) {
        if(train.getId() == id) {
            return &train;
        }
    }
    return nullptr;
}

void Scheduler::updateSchedule() {
    simulation_time += 1;
}

bool Scheduler::hasTrainsToProcess() const {
    return !pending_trains.empty();
}
