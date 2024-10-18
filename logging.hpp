#include <iostream>
#include <fstream>
enum LogLevel { DEBUG, ERROR, INFO, WARNING, CRITICAL };

class Logger
{
private:
    std::fstream log_file;
    std::string level_to_str(LogLevel level);
public:
    bool verborse = false;
    Logger(std::string name);
    ~Logger();
    void log(LogLevel level,std::string text);
};
