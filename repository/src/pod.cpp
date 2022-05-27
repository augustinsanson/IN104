#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>


Decision::Decision(sf::Vector2f target, float power) 
{
    target_ = target;
    power_ = power;
};


Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) 
{
    pos_ = pos;
    angle_ = angle;
    vel_ = vel;
};

// Si l'angle est supérieur à l'angle limite, on doit changer de cible pour que le nouvel angle soit inférieur à l'angle limite
Decision Pod::getDecision(Game myGame, sf::RenderWindow* pwindow) const 
{
    if (!manualPod_)  //Mode auto
    {
        if (version_ == 1) //Version avec et sans "IA"
        {
            if (nextCP_ == 0) //FinalCP
            {
                sf::Vector2f target = myGame.finalCP_.getPosition();   
                target = Angle_Checking(target,pos_,angle_,ROTA_MAX); 
                float pow = puissance(target, pos_, angle_, MAX_POWER);
                return Decision(target, pow);        
            } 
            else //OtherCPs
            {
                sf::Vector2f target = myGame.otherCPs_[nextCP_-1.f].getPosition();
                target = Angle_Checking(target,pos_,angle_,ROTA_MAX);
                float pow = puissance(target, pos_, angle_, MAX_POWER);
                return Decision(target, pow);
            }
        }
        else
        {
            if (nextCP_ == 0)
            {
                sf::Vector2f target = myGame.finalCP_.getPosition();   
                target = Angle_Checking(target,pos_,angle_,ROTA_MAX);             
                return Decision(target, 100);        
            } 
            else
            {
                sf::Vector2f target = myGame.otherCPs_[nextCP_-1.f].getPosition();
                target = Angle_Checking(target,pos_,angle_,ROTA_MAX);
                return Decision(target, 100);
            }
        }
    }
    
    else //Mode manuel
    {
        sf::Vector2i target_a = sf::Mouse::getPosition(*pwindow);
        sf::Vector2f target_b = {float(target_a.x)*10, float(target_a.y)*10};

        target_b = Angle_Checking(target_b,pos_,angle_,ROTA_MAX); 
        return Decision(target_b, 100);
    }    
};