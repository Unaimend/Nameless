#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logfile.h"
#include "Player.h"
#include "Maploader.h"
#include <vector>
#include "NPC.h"
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
    Player      *pPlayer1;
    int         Mapheigth;
    int         Mapwidth;
    int         mAuflösungsBreite;
    int         mAuflösungsHöhe;
     sf::Clock clock2;
    NPC *ptest;
	
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
