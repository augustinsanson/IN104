#include "utils.h"
#include <cmath>
#include <stdlib.h>
#include <stdbool.h>

void setOriginToCenter(sf::Sprite &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2.f, rect.height/2.f);
}

void setOriginToCenter_Shape(sf::Shape &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2.f, rect.height/2.f);
}

void scaleToMinSize(sf::Sprite &sp, double size_x, double size_y){
    auto rect = sp.getGlobalBounds();
    float R_x = size_x/rect.height;
    float R_y = size_y/rect.width;
    if (R_x > R_y){ //Mutliplication par le rapport L/l le plus grand
        sp.setScale(R_x,R_x); //Multiplication largeur et longueur par H/h
    }
    else {
        sp.setScale(R_y,R_y);
    }
}

void scaleToMaxSize(sf::Sprite &sp, double size_x, double size_y){
    auto rect = sp.getGlobalBounds();
    float R_x = size_x/rect.height;
    float R_y = size_y/rect.width;
    if (R_x < R_y){ //Multiplication par le rapport L/l le plus petit
        sp.setScale(R_x,R_x); // multiplication largeur et longueur par H/h
    }
    else {
        sp.setScale(R_y,R_y); 
    }
}

void scaleByRadius(sf::Sprite &sp, int radius)
{
    double scalingFactor = 2*radius/std::sqrt(sp.getTextureRect().width*sp.getTextureRect().width + sp.getTextureRect().height*sp.getTextureRect().height);
    sp.scale(scalingFactor, scalingFactor);
}

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center)
{
    sf::Vector2f offset;
    offset.x = txt.getPosition().x - txt.getGlobalBounds().left - txt.getGlobalBounds().width/2.;
    offset.y = txt.getPosition().y - txt.getGlobalBounds().top - txt.getGlobalBounds().height/2.;

    txt.setPosition(center + offset);
}

float norm(sf::Vector2f u){
    return sqrt(pow(u.x,2)+pow(u.y,2));
}

float arg(sf::Vector2f v){
    if (v.x == 0) return v.y/abs(v.y)*M_PI/2; // + pi/2 ou - pi/2, dépend du signe de y
    else if (v.x < 0 && v.y >= 0) return atan(v.y/v.x) + M_PI;
    else if (v.x < 0 && v.y < 0) return atan(v.y/v.x) - M_PI; // Conserver dans l'intervalle ]-pi,pi]
    else return atan(v.y/v.x);
}

std::vector<sf::Vector2f> coord_CP(int nbCP){

    std::vector<sf::Vector2f> Coord_CP;

    if (nbCP == 9)
        nbCP = rand()%7 + 2;
        
    Coord_CP.reserve(nbCP+1);

    
    for (int i=0; i<nbCP+1; ++i)
    {
        bool collision;
        float x;
        float y;
        do{
            x = rand()%14801 + 600; // x dans [600,15400]
            y = rand()%7801 + 600; // y dans [600, 8400]
            collision = false;
            
            // Possible collision ?
            for(int j=0; j<i; ++j){
                if (norm(sf::Vector2f(x,y)-Coord_CP[j])<1200)
                {   collision = true;
                    printf("collision entre %d et %d\n",i,j);
                }    
            }
        } while (collision);
        
        //Sinon, on ajoute les coordonnées du checkpoint
        Coord_CP.emplace_back(sf::Vector2f(x,y));
    }
    return Coord_CP;
}



sf::Vector2f Angle_Checking(sf::Vector2f target, sf::Vector2f pos, float angle, float angleMax)
{
    sf::Vector2f D = target-pos;
    
    if (abs(arg(D)-angle)<angleMax)
        return target;   
    else
    {
        int n = -1;
        float d = angle - arg(D) + 2*n*M_PI;
        while ((d <= -M_PI || d > M_PI) && n<2)
        {
            n = n+1;
            d = angle - arg(D) + 2*n*M_PI;
        }

        float beta;

        if (0<=d && d<=M_PI) {
            beta = d - angleMax; // > 0
        }
        else {
            beta = d + angleMax; // < 0
        }

        sf::Vector2f CPrime = sf::Vector2f(D.x*cos(beta)-D.y*sin(beta), D.x*sin(beta)+D.y*cos(beta));
        return CPrime + pos;
    }
} 

float puissance(sf::Vector2f target , sf::Vector2f pos, float angle, float MaxPower)
{
    float theta = abs(arg(target-pos)-angle);
    if (theta > M_PI) theta = 2*M_PI - theta ; // Angle modulo pi
    
    float power = (M_PI-theta)/M_PI*MaxPower;
    return power;
}
