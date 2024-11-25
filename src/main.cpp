#include "../include/controller.h"
#include <iostream>

int main() {
    TrainStation station;
    Scheduler scheduler;
   
    if (!scheduler.loadSchedule("../data/schedule.txt")) {
        std::cerr << "Failed to load schedule\n";
        return 1;
    }

    Controller controller(station, scheduler);
    controller.run();

    return 0;
}