#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "train.h"
#include <vector>
#include <string>

class Scheduler {
public:
    bool loadSchedule(const std::string& filename);
    Train* getNextTrain();
    void updateSchedule();

private:
    std::vector<Train> trains;
    size_t current_index = 0;
};

#endif