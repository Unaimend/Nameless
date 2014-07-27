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
std::string Logfile::toString( int Peter)
{
    std::cout << Peter << std::endl;
    std::stringstream sstr;
    sstr << Peter;
    
    mParameter = sstr.str();
    std::cout << mParameter << std::endl;
    return mParameter;
};
