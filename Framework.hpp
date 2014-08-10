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
    
    
protected:
private:
    //--------------PRIVATE VARIABLEN-------------------------
    sf::RenderWindow *pRenderWindow;
    sf::Event   *pMainEvent;
    sf::Clock   *pClock;
    Logfile     *pLog;
    double      mFrameTime;
    bool        mRun;
    Maploader   *pMap;
    Player      mPlayer1;
    
//    Fireball<Enemy> *pBall;
    int         Mapheigth;
    int         Mapwidth;
    int         mAuflösungsBreite;
    int         mAuflösungsHöhe;
     sf::Clock clock2;
    NPC *pNPC_01;
	Zombie *pZombie;
    //std::vector<Enemy> mEnemyVektor;
    MagicSystem mPlayerMagicSystem;
    //--------------PRIVATE FUNKTIONEN------------------------
    //Die Funktion behandelt alle Spielereingaben
    void Update(double frametime);
    void EventHandling();
    void Render();
    float GetFrameTime();
    void Quit();

 
    
    
public:
    //Konstruktor
    Framework();
    //Destruktor
    ~Framework();
    //UpdateFunktion in der alles Zusammengeführt wird, wird pro Frame aufgerufen,
    void Run();
    
    int getAuflösungsHöhe(){return mAuflösungsHöhe;};
    int getAuflösungsBreite(){return mAuflösungsBreite;};
};


#endif
