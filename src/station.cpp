#include "../include/station.h"
#include <iostream>

TrainStation::TrainStation() {
    // Initialize tracks
    for(int i = 0; i < 8; i++) {
        tracks[i] = {i, false, true}; // id, occupied, light_status
    }
   
    // Initialize switches
    for(int i = 0; i < 4; i++) {
        switches[i] = {i, false}; // id, position
    }
   
    // Initialize entry points
    left_entries = {0, 1, 2, 3};
    right_entries = {4, 5, 6, 7};
}

bool TrainStation::allocateTrack(int train_id) {
    // Find first available track
    for(int i = 0; i < 8; i++) {
        if(!tracks[i].occupied) {
            tracks[i].occupied = true;
            tracks[i].light_status = false;
            return true;
        }
    }
    return false;
}

void TrainStation::updateSwitches() {
    for(auto& sw : switches) {
        // Simple toggle for demonstration
        sw.position = !sw.position;
    }
}
bool TrainStation::allocateTrack(int train_id, const std::string& entry_point) {
    std::vector<int>& entries = (entry_point == "WEST") ? left_entries : right_entries;
    
    for(int track_id : entries) {
        if(!tracks[track_id].occupied) {
            tracks[track_id].occupied = true;
            tracks[track_id].light_status = false;
            return true;
        }
    }
    return false;
}

void TrainStation::releaseTrack(int track_id) {
    if(track_id >= 0 && track_id < 8) {
        tracks[track_id].occupied = false;
        tracks[track_id].light_status = true;
    }
}
int TrainStation::getTrainTrack(int train_id) const {
    for(size_t i = 0; i < tracks.size(); i++) {
        if(tracks[i].occupied) return i;
    }
    return -1;
}

void TrainStation::printStatus() const {
    std::cout << "Track Status:\n";
    for(const auto& track : tracks) {
        std::cout << "Track " << track.id << ": "
                 << (track.occupied ? "Occupied" : "Free") << " - Light: "
                 << (track.light_status ? "Green" : "Red") << "\n";
    }
}
