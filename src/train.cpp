#include "../include/train.h"
#include <sstream>
#include <iomanip>

std::time_t parseTime(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%H:%M");
    
    std::time_t now = std::time(nullptr);
    std::tm* today = std::localtime(&now);
    
    tm.tm_year = today->tm_year;
    tm.tm_mon = today->tm_mon;
    tm.tm_mday = today->tm_mday;
    
    return std::mktime(&tm);
}

Train::Train(int id, int priority, const std::string& arrival, 
            const std::string& departure, std::string entry, std::string exit)
    : train_id(id), priority(priority), entry_point(entry), exit_point(exit) {
    arrival_time = parseTime(arrival);
    departure_time = parseTime(departure);
}
