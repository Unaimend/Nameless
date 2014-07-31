#include "DialogSystem.h"
DialogSystem::DialogSystem(std::string text, int xpos, int ypos,unsigned int ChraracterSize)
{
    mFont.loadFromFile("sansation.ttf");
    mText.setFont(mFont);
    mText.setString(text);
    mText.setPosition(xpos, ypos);
    mText.setCharacterSize(ChraracterSize);
    

};

DialogSystem::~DialogSystem(){};

void DialogSystem::render(sf::RenderWindow *window)
{
    window->draw(mText);
};