#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "station.h"
#include "scheduler.h"
#include "visualization.h"
#include <map>

class Controller {
public:
    Controller(TrainStation& station, Scheduler& scheduler);
    void update();
    void run();

private:
    TrainStation& station;
    Scheduler& scheduler;
    Visualization vis;
    std::map<int, float> trainPositions;
};

#endif
