#include "Logfile.h"
#include <sstream>
#include <fstream>
#include <sstream>
Logfile::Logfile(std::string filepath)
{
    mFilepath = filepath;
    pLog = new std::ofstream(mFilepath);
};



void Logfile::writeToFile(std::string parameter)
{
    this->setmTime();
    std::string string =   mTime + parameter + "\n";
    //std::cout << parameter << std::endl;
    *pLog << string;
}
void Logfile::closeFile()
{
    Logfile::~Logfile();
};

Logfile::~Logfile()
{
    pLog->close();
    delete pLog;
    pLog = nullptr;
};

void Logfile::setmTime()
{
  
    t = time(NULL);
    tm *ts = localtime(&t);
    mTime = std::string(asctime(ts));
};

