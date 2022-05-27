#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "utils.h"

const unsigned int WIDTH_VIEW = 16000;
const unsigned int HEIGHT_VIEW = 9000;

Menu::Menu()
{
    if (!backgroundTexture_.loadFromFile("../repository/Images/Menu.png"))
    {
        printf("error");
    } 
    backgroundSprite_.setTexture(backgroundTexture_);
    setOriginToCenter(backgroundSprite_);
    scaleToMinSize(backgroundSprite_,HEIGHT_VIEW,WIDTH_VIEW);
    backgroundSprite_.setPosition(WIDTH_VIEW/2,HEIGHT_VIEW/2);    
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
}


