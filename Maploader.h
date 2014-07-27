
#ifndef __Nameless__Maploader__
#define __Nameless__Maploader__

#include <iostream>
#include <fstream>
#include "vector"
class   Maploader
{
public:
    Maploader(std::string filepath, int Mapheigth, int Mapwidth);
    ~Maploader();
    std::vector<float> getMapVektor(){return mMapVektor;};
protected:
private:
    void loadMap();
    
    std::ifstream *pMap;
    std::string mFilepath;
    int mMapheigth, mMapwidth, temporaryMap;
    std::vector<float> mMapVektor;
    
};
#endif /* defined(__Nameless__Maploader__) */
