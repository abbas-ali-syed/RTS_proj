#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "train.h"
#include <vector>
#include <string>

class Scheduler {
public:
    bool loadSchedule(const std::string& filename);
    Train* getNextTrain();
    Train* getTrain(int id);
    void updateSchedule();
    bool hasTrainsToProcess() const;

private:
    std::vector<Train> trains;
    std::vector<size_t> pending_trains;
    std::time_t simulation_time;
    
    void sortPendingTrains();
};

#endif
