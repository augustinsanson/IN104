#include <SFML/Graphics/CircleShape.hpp>
#include <cmath>
#include "game.h"
#include "checkpoint.h"
#include "utils.h"
#include "pod.h"
#include <iostream>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    otherCPs_.reserve(checkpointsPositions.size()-1);
    

    if (!backgroundTexture_.loadFromFile(IMAGES_PATH + "/background.png"))
    {
        printf("Texture error\n");
    }
    backgroundSprite_.setTexture(backgroundTexture_);
    setOriginToCenter(backgroundSprite_);
    scaleToMinSize(backgroundSprite_,HEIGHT_VIEW,WIDTH_VIEW);
    backgroundSprite_.setPosition(WIDTH_VIEW/2,HEIGHT_VIEW/2);

    for (unsigned int cpID = 1; cpID<checkpointsPositions.size(); cpID++)
    {
        otherCPs_.emplace_back(checkpointsPositions[cpID], cpID);
    }

    winner_ = "nobody";
}

void Game::addPod(int manualPlayer)
{
    int nb_pods = 2; // Nombre de pods en jeu
    
    podsSprites_.reserve(nb_pods);
    pods_.reserve(nb_pods);
    podsTextures_.reserve(nb_pods);
    
 
    Pod pod1 = Pod({11000,8000}, 0.f); //1er Pod
    sf::Texture podTexture1;
    sf::Sprite podSprite1;
    
    if (!podTexture1.loadFromFile("../repository/Images/BSGViper.png"))
    {
        printf("Texture error\n");
    }
    
    podsTextures_.emplace_back(podTexture1);
    pods_.emplace_back(pod1);
    podsSprites_.emplace_back(podSprite1);
    pods_[0].name_ = "BSGViper";
    pods_[0].version_ = 1;
       
    Pod pod2 = Pod({11000,8000}, 0.f); //2e Pod
    sf::Texture podTexture2;
    sf::Sprite podSprite2;

    if (!podTexture2.loadFromFile("../repository/Images/SWAnakinsPod.png"))
    {
        printf("Texture error\n");
    }

    podsTextures_.emplace_back(podTexture2);
    pods_.emplace_back(pod2);
    podsSprites_.emplace_back(podSprite2);
    pods_[1].name_ = "SWAnakins"; 
    pods_[1].version_ = 2;
   
 /*
    Pod pod3 = Pod({11000,8000}, 0.f); //3e Pod
    sf::Texture podTexture3;
    sf::Sprite podSprite3;
    
    if (!podTexture3.loadFromFile("../repository/Images/BSGCylon.png"))
    {
        printf("Texture error\n");
    }
    
    podsTextures_.emplace_back(podTexture3);
    pods_.emplace_back(pod3);
    podsSprites_.emplace_back(podSprite3);
    pods_[2].name_ = "BSGCylon";
    pods_[2].version_ = 3; 
    */

    podsSprites_.reserve(nb_pods);
    pods_.reserve(nb_pods);
    podsTextures_.reserve(nb_pods);  
    
    for (int i=0; i<nb_pods; i++){
        
        podsSprites_[i].setTexture(podsTextures_[i]);
        setOriginToCenter(podsSprites_[i]);
        scaleToMaxSize(podsSprites_[i], 800,800);

        pods_[i].nextCP_ = 1;
        pods_[i].lapCount_ = 1;
        pods_[i].manualPod_ = 0;
    }

    if (manualPlayer)
    {
        pods_[0].manualPod_ = 1;
    }  
}

void Game::RaceDecompte() //Décompte du départ de la course
{
    decompteSprites_.reserve(3);
    decompteTextures_.reserve(3);

    sf::Texture decompteTexture3;
    sf::Sprite decompteSprite3;
    
    if (!decompteTexture3.loadFromFile("../repository/Images/3_compteur.png"))
        printf("Texture error\n");
    
    decompteTextures_.emplace_back(decompteTexture3);
    decompteSprites_.emplace_back(decompteSprite3);

    sf::Texture decompteTexture2;
    sf::Sprite decompteSprite2;
    
    if (!decompteTexture2.loadFromFile("../repository/Images/2_compteur.png"))
        printf("Texture error\n");
    
    decompteTextures_.emplace_back(decompteTexture2);
    decompteSprites_.emplace_back(decompteSprite2);

    sf::Texture decompteTexture1;
    sf::Sprite decompteSprite1;
    
    if (!decompteTexture1.loadFromFile("../repository/Images/1_compteur.png"))
        printf("Texture error\n");
    
    decompteTextures_.emplace_back(decompteTexture1);
    decompteSprites_.emplace_back(decompteSprite1);


    for (int i=0; i<3; i++){
        
        decompteSprites_[i].setTexture(decompteTextures_[i]);
        setOriginToCenter(decompteSprites_[i]);
        scaleToMaxSize(decompteSprites_[i], 4000,4000);
        decompteSprites_[i].setPosition(WIDTH_VIEW/2,HEIGHT_VIEW/2);
    }
}

void Game::updatePhysics(sf::RenderWindow* pwindow)
{
    
    for (Pod &pod : pods_){
        if (pod.lapCount_ <= NUMBER_OF_LAPS)
        {
            Decision d = pod.getDecision(*this, pwindow);
            //Avec la décision du pod et on met à jour la position, la vitesse, l'angle

            float k = 0.85;
            pod.vel_ =  k * ( pod.vel_ + d.power_*(d.target_-pod.pos_)/norm(d.target_-pod.pos_) );
            pod.pos_ = pod.pos_ + pod.vel_;

            // Délimitation de la zone de jeu: impossible de sortir de l'écran
            if (pod.pos_.x<400)pod.pos_.x = 400;
            if (pod.pos_.x>WIDTH_VIEW-400)pod.pos_.x = WIDTH_VIEW-400;
            if (pod.pos_.y<400)pod.pos_.y = 400;
            if (pod.pos_.y>HEIGHT_VIEW-400)pod.pos_.y = HEIGHT_VIEW-400;
            
            pod.angle_ = arg(pod.vel_);
                    
            //Angle max fixé : si l'angle dépasse la valeur limite, on change la cible pour que l'angle ne dépasse plus
            if (norm(pod.pos_ - d.target_)<550){ //CheckPoint atteint //Problème sur cette ligne, changer d.target_ par allCPS_[pod.nextCP_] ?

                if (pod.nextCP_ == 0 && pod.lapCount_<= NUMBER_OF_LAPS){
                    pod.nextCP_ = 1;
                    pod.lapCount_ += 1;
                    if (pod.lapCount_ == NUMBER_OF_LAPS+1 && winner_.compare("nobody")==0 )
                    {
                        winner_ = pod.name_;
                        std::cout <<"winner is : " << winner_ << '\n';
                    }
                }
                
                else if (0 < pod.nextCP_ && pod.nextCP_ < otherCPs_.size()) pod.nextCP_ += 1;
                else pod.nextCP_ = 0;
            }
        }
    }

    physicsTime += PHYSICS_TIME_STEP;
}

void Game::updateGraphics(sf::Time frameTime) //Mise à jour de la position des Sprites en fonction du temps de la frame actuelle, mais pas des pods
{
    //utiliser la position de la podSprite (ancienne position graphique) et la position du pod
    //(prochaine position réelle), physicsTime_, lastFrameTime_ et frameTime pour évaluer la nouvelle position graphique

    float R = (physicsTime - frameTime)/(frameTime-lastFrameTime);
    
    int nb_pods = podsSprites_.size();
    for (int i=0; i<nb_pods; ++i){
        if (pods_[i].lapCount_ <= NUMBER_OF_LAPS) // Si le Pod est encore en course
        {
            sf::Vector2f pos_sprite = podsSprites_[i].getPosition();

            if (R>1)  podsSprites_[i].setPosition( pos_sprite + (pods_[i].pos_ - pos_sprite)/R );
            else podsSprites_[i].setPosition(pods_[i].pos_);
            
            podsSprites_[i].setRotation(pods_[i].angle_*180.f/M_PI);
        }
    }

    lastFrameTime = frameTime;

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
        target.draw(backgroundSprite_, states);
        target.draw(finalCP_, states);

        for (const auto &cp : otherCPs_)
        {
            target.draw(cp,states);
        }
        
        if (decompteTime_.asMilliseconds() > 3000)
        {
            for (const auto &podSprite : podsSprites_)
            {   
                target.draw(podSprite, states); 
            }
        }

        else if (decompteTime_.asMilliseconds() < 1000) //Décompte 3-2-1
            target.draw(decompteSprites_[0],states);
        else if (decompteTime_.asMilliseconds() < 2000)
            target.draw(decompteSprites_[1],states);
        else if (decompteTime_.asMilliseconds() < 3000)
            target.draw(decompteSprites_[2],states);

}