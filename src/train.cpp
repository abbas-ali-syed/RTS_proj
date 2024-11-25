#include "../include/train.h"

Train::Train(int id, int priority, std::string entry, std::string exit)
    : train_id(id), priority(priority), entry_point(entry), exit_point(exit) {}