#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "checkpoint.h"                                                                            
#include "pod.h"                                                                                  
#include "utils.h" 
#include "game.h"
#include "menu.h"                                                                                
#include <iostream>

int main()
{
    int width_screen = 1600;
    int height_screen = 900;
    sf::RenderWindow window(sf::VideoMode(width_screen, height_screen), "Nimbus 2000");
    window.setView(sf::View (sf::FloatRect(0,0,16000.f,9000.f)));

    int gameMode = 0;

    while (window.isOpen())
    {   
        sf::Event event;
        if (gameMode == 0){
            Menu open_menu = Menu();
            
            while (gameMode == 0){ //pas en jeu

                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        gameMode = -1;
                        window.close();
                    } 

                    if (event.type == sf::Event::MouseButtonPressed) 
                    {
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {                      
                           gameMode = 1;
                        }
                    }   
                }
                window.clear();
                window.draw(open_menu);
                window.display();
            }
        }

        if (gameMode == 1){ //en jeu

            //Initialisation du game et des variables
            float fps = 60; //frame per second
            //Temps minimal entre deux frame
            sf::Time refreshTime = sf::microseconds(1e6/fps);
            //horloge depuis le début du jeu
            sf::Clock globalClock;
            //temps de la physique du jeu
            sf::Clock refreshClock;
            sf::Time physicsTime = sf::Time::Zero;
            
            //Initialisation des placements aléatoires des CP
            std::vector<sf::Vector2f> Coord_CP = coord_CP(5);
            
            Game myGame = Game(Coord_CP);
            myGame.addPod(1);
            myGame.RaceDecompte();
                              
            while (gameMode == 1){
                
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        gameMode = -1;
                        window.close();
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::Escape)    
                            gameMode = 0;

                    }
                    if (event.type == sf::Event::MouseButtonPressed)
                    {    
                        if (event.mouseButton.button == sf::Mouse::Left)
                            {
                                int x = event.mouseButton.x;
                                int y = event.mouseButton.y;
                                printf("x = %d, y = %d\n", x, y);
                            }
                    }
                }

                //si on a dépassé le refreshTime depuis la dernière frame
                if (refreshClock.getElapsedTime() >= refreshTime)
                {
                    //réinitialise l'horloge qui mesure le temps entre les frames
                    refreshClock.restart();
                    //récupère le temps écoulé depuis le début du jeu
                    sf::Time frameTime = globalClock.getElapsedTime();
                    myGame.decompteTime_ = frameTime;

                    //si on a dépassé le temps de la physique
                    if (frameTime > physicsTime && frameTime.asMilliseconds() > 3000)
                    { 
                        //met à jour les sprite au temps de la physique
                        myGame.updateGraphics(physicsTime);
                        //fait avancer la physique d'un pas de temps
                        myGame.updatePhysics(&window);
                        physicsTime += PHYSICS_TIME_STEP;
                        //reprend le temps écoulé depuis le début pour rester précis
                        frameTime = globalClock.getElapsedTime();
                    }
                    else 
                        //met à jour les sprites au temps actuel
                        myGame.updateGraphics(frameTime);
                    window.clear();
                    window.draw(myGame);
                    window.display();
                }
            }
        }
    }

    return 0;
}