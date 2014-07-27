#include "Maploader.h"
#include <Logfile.h>
Maploader::Maploader(std::string filepath, int Mapheigth, int Mapwidth)
{
    mMapheigth = Mapheigth;
    mMapwidth = Mapwidth;
    mFilepath = filepath;
    temporaryMap = 0;
    pMap = new std::ifstream(mFilepath);
    this->loadMap();
    
};

Maploader::~Maploader(){};

void Maploader::loadMap()
{
    for (int it = 0; it < mMapheigth * mMapwidth; it++)
    {
        *pMap >> temporaryMap;
        mMapVektor.push_back(temporaryMap);
        if (temporaryMap == 99) {
            break;
        }
    }
    

};