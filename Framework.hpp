#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logfile.h"
#include <Maploader.h>
#include <vector>
#ifndef Neues_SFML_Projekt_Framework_hpp
#define Neues_SFML_Projekt_Framework_hpp


class Framework
{
    
    
protected:
private:
    //--------------PRIVATE VARIABLEN-------------------------
    sf::RenderWindow *pRenderWindow;
    sf::Event *pMainEvent;
    sf::Clock *pClock;
    Logfile *pLog;
    double mFrameTime;
    bool mRun;
    Maploader *pMap;
    int Mapheigth;
    int Mapwidth;
    
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
};


#endif
