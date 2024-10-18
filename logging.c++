#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iostream>

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

Logger::Logger(std::string name)
{
    std::string filename(name);
    filename.append(".log");
    this->log_file.open(filename,std::ios_base::out);
    
}

Logger::~Logger()
{
    this->log_file.close();
}
void Logger::log(LogLevel level,std::string text){
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    this->log_file.write("[",1);
    this->log_file.write(timestamp,19);
    this->log_file.write("] ",2);
    this->log_file.write(level_to_str(level).c_str(),level_to_str(level).length());
    this->log_file.write(": ",2);
    this->log_file.write(text.c_str(),text.length());
    if (this->verborse)
    {
    std::cout << "[" << timestamp << "] " << level_to_str(level) << ": " << text;
    }
    

}
std::string Logger::level_to_str(LogLevel level){
    switch (level)
    {
    case 0:
        return "DEBUG";
        break;
    case 1:
        return "ERROR";
        break;
    case 2:
        return "WARNING";
        break;
    case 3:
        return "INFO";
        break;
    case 4:
        return "CRITICAL";
        break;
    default:
        return "DEBUG";
        break;
    }
}

