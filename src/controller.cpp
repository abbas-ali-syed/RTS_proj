#include "../include/controller.h"
#include <thread>
#include <chrono>

Controller::Controller(TrainStation& s, Scheduler& sch)
    : station(s), scheduler(sch) {}

void Controller::update() {
    vis.clearScreen();
   
    // Draw station infrastructure
    vis.drawStation();
   
    // Draw all tracks
    for(int i = 0; i < 8; i++) {
        vis.drawTrack(i, station.isTrackOccupied(i), station.getTrackLightStatus(i));
    }
   
    // Draw switches
    for(int i = 0; i < 4; i++) {
        vis.drawSwitch(i, station.getSwitchPosition(i));
    }
   
    // Update and draw trains
    for(auto& [trainId, position] : trainPositions) {
        position += 2.0f; // Move trains
        int trackNum = station.getTrainTrack(trainId);
        if(trackNum >= 0) {
            vis.drawTrain(trackNum, position);
        }
    }
   
    // Process next train if available
   Train* next_train = scheduler.getNextTrain();
if(next_train) {
    if(station.allocateTrack(next_train->getId(), next_train->getEntryPoint())) {
        float initial_pos = next_train->getEntryPoint() == "WEST" ? 0.0f : 800.0f;
        trainPositions[next_train->getId()] = initial_pos;
    }
}
   
    vis.updateDisplay();
}

void Controller::run() {
    while(true) {
        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
       
        // For demonstration purposes, break after some time
        static int updates = 0;
        if(++updates >= 500) break;
    }
}
