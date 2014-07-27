#include "Logfile.h"

template<class T>
std::string Logfile::toString( T Wert)
{
    mParameter = std::to_string(Wert);
    return mParameter;
};
