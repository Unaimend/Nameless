#include "Maploader.h"
#include <Logfile.h>
Maploader::Maploader(std::string filepath)
{
    mFilepath = filepath;
    pMap = new std::ifstream(mFilepath);
    
};

Maploader::~Maploader(){};

void Maploader::loadMap()
{
    

};