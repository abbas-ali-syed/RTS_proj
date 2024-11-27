#ifndef STATION_H
#define STATION_H

#include <vector>
#include <array>

struct Track {
    int id;
    bool occupied;
    bool light_status;
};

struct Switch {
    int id;
    bool position;
};

class TrainStation {
public:
    TrainStation();
   
   // bool allocateTrack(int train_id);
    void updateSwitches();
    void printStatus() const;
   
    bool isTrackOccupied(int track) const { return tracks[track].occupied; }
    bool getTrackLightStatus(int track) const { return tracks[track].light_status; }
    bool getSwitchPosition(int sw) const { return switches[sw].position; }
    int getTrainTrack(int train_id) const;
  //  bool allocateTrack(int train_id, const std::string& entry_point);
    bool allocateTrack(int train_id, const std::string& entry_point);
    void releaseTrack(int track_id);
private:
    std::array<Track, 8> tracks;
    std::array<Switch, 4> switches;
    std::vector<int> left_entries;
    std::vector<int> right_entries;
};

#endif
