#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>


class Menu : public sf::Drawable
{
    public :
    Menu();

    private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

   
};

#endif

