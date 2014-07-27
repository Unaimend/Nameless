
#ifndef __Nameless__Maploader__
#define __Nameless__Maploader__

#include <iostream>
#include <fstream>
class   Maploader
{
public:
    Maploader(std::string filepath);
    ~Maploader();
    
protected:
private:
    void loadMap();
    
    std::ifstream *pMap;
    std::string mFilepath;
};
#endif /* defined(__Nameless__Maploader__) */
