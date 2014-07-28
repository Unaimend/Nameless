#ifndef __Nameless__Logfile__
#define __Nameless__Logfile__
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>

class Logfile
{

public:
        //FUNKTIONEN
        Logfile(std::string filepath);
        ~Logfile();
        void writeToFile(std::string parameter);
        void closeFile();
        template<class T>
        std::string toString(T Wert);

protected:
private:
        void setmTime();
    
        std::ofstream *pLog;
        std::string mFilepath;
        std::time_t mCurrentTime = std::time(nullptr);
        time_t t = time(NULL);
        struct tm *ts = localtime(&t);
        std::string mTime = std::string(asctime(ts));
        std::string mParameter;
    
};



#include "Test.inl"

#endif /* defined(__Nameless__Logfile__) */


