#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <ctime>

class Train {
public:
    Train(int id, int priority, const std::string& arrival, 
          const std::string& departure, std::string entry, std::string exit);
   
    int getId() const { return train_id; }
    int getPriority() const { return priority; }
    std::string getEntryPoint() const { return entry_point; }
    std::string getExitPoint() const { return exit_point; }
    std::time_t getArrivalTime() const { return arrival_time; }
    std::time_t getDepartureTime() const { return departure_time; }

private:
    int train_id;
    int priority;
    std::string entry_point;
    std::string exit_point;
    std::time_t arrival_time;
    std::time_t departure_time;
};

#endif
