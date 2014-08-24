#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logfile.h"
#include "Player.h"
#include "Maploader.h"
#include <vector>
#include "NPC.h"
#include "Zombie.h"
#include "MagicSystem.h"
#ifndef Neues_SFML_Projekt_Framework_hpp
#define Neues_SFML_Projekt_Framework_hpp


class Framework : Sprites
{
public:
    Framework();
    ~Framework();
    void Run();
    int getAuflösungsHöhe(){return mAuflösungsHöhe;};
    int getAuflösungsBreite(){return mAuflösungsBreite;};
private:
    void        Update(double frametime);
    void        EventHandling();
    void        Render();
    void        Quit();
    void        loadMap();
    float       getFrameTime();
    float       getFPS();
    
    
    sf::RenderWindow    *pRenderWindow;
    sf::Event           *pMainEvent;
    sf::Clock           *pClock;
    sf::Clock           clock2;
    Logfile     *pLog;
    Player      mPlayer1;
    Maploader   *pMap;
    NPC         *pNPC_01;
    MagicSystem mPlayerMagicSystem;
    Zombie      *pZombie;
    double      mFrameTime;
    bool        mRun;
    int         Mapheigth;
    int         Mapwidth;
    int         mAuflösungsBreite;
    int         mAuflösungsHöhe;
};


#endif
