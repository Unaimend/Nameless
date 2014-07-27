#include "Framework.hpp"

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
    pLog->writeToFile("Restliche Grundfunktionen initialisiert");
    
    Mapheigth       = 0;
    Mapwidth        = 0;
    pMap = new Maploader("Map.txt", Mapheigth, Mapwidth);
   
    pLog->writeToFile(pLog->toString( 5)+ " HI");

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
        if (pMainEvent->type == sf::Event::Closed || (pMainEvent->type == sf::Event::KeyPressed   && pMainEvent->key.code == sf::Keyboard::Escape)) {
            mRun = false;
            pLog->writeToFile("mRun = false");
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
