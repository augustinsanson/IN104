#ifndef INC_UTILS_H
#define INC_UTILS_H

#include <SFML/Graphics.hpp>

void setOriginToCenter(sf::Sprite &object);
void setOriginToCenter_Shape(sf::Shape &object);

void scaleToMinSize(sf::Sprite &sp, double size_x, double size_y);
void scaleToMaxSize(sf::Sprite &sp, double size_x, double size_y);
void scaleByRadius(sf::Sprite &sp, int radius);

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center);

float norm(sf::Vector2f u);

float arg(sf::Vector2f v);

std::vector<sf::Vector2f> coord_CP(int nbCP);

sf::Vector2f Angle_Checking(sf::Vector2f target, sf::Vector2f pos, float angle, float angleMax);

float puissance(sf::Vector2f target , sf::Vector2f pos, float angle, float MaxPower);

#endif