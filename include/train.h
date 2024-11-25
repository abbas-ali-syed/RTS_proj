#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
public:
    Train(int id, int priority, std::string entry, std::string exit);
   
    int getId() const { return train_id; }
    int getPriority() const { return priority; }
    std::string getEntryPoint() const { return entry_point; }
    std::string getExitPoint() const { return exit_point; }

private:
    int train_id;
    int priority;
    std::string entry_point;
    std::string exit_point;
};

#endif