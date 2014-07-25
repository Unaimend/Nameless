#include <iostream>
#include "Framework.hpp"
#include <Logfile.h>
#include <SFML/Graphics.hpp>
//Version 0.0.1


Framework::Framework()
{
    pLog = new Logfile("Logfile.log");
    
    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(800,600,32), "TITLE");
    pLog->writeToFile("Fenster initialisiert");
   
    pRenderWindow->setFramerateLimit(60);
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRun            = true;
    pLog->writeToFile("Restliche Grrundfunktionen initialisiert");
    
}



Framework::~Framework()
{   pLog->writeToFile("Fensterinstanz geshlossen");
    pLog->closeFile();
    
}



void Framework::Run()
{
    while (mRun)
    {
        Update(mFrameTime);
        EventHandling();
        Render();
        GetFrameTime();
        Quit();
    }
    
}



void Framework::Update(double frametime)
{
   
   // std::cout << mFrameTime << std::endl;
}



void Framework::EventHandling()
{
    while (pRenderWindow->pollEvent(*pMainEvent)) {
        if (pMainEvent->type == sf::Event::Closed) {
            mRun = false;
        }
    }
    
}



void Framework::Render()
{
    pRenderWindow->clear(sf::Color(120,120,120));
    
    pRenderWindow->display();
  
}



float Framework::GetFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();


    return mFrameTime;
    
}



void Framework::Quit()
{
    if (!mRun ) {
        pRenderWindow->close();
    }
    
}
