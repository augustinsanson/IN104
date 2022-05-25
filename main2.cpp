int main()
{

    float L = 16000;
    float l = 9000;
    float echelle = 1;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 32;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

    //Background
    sf::Texture myTexture;
    myTexture.loadFromFile("../repository/Images/background.png");
    sf::Sprite background(myTexture);
    setOriginToCenter(background);
    scaleToMinSize(background,L,l);
    background.setPosition(L/2.f,l/2.f);

    //Vaisseau 1
    sf::Texture myTexture2;
    myTexture2.loadFromFile("../repository/Images/BSGCylon.png");
    sf::Sprite v1(myTexture2);
    setOriginToCenter(v1);
    scaleToMaxSize(v1,600/echelle, 600/echelle);
    //v1.setPosition(0.f,600/2.f);

    //Vaisseau 2
    sf::Texture V2;
    V2.loadFromFile("BSGViper.png");
    sf::Sprite v2(V2);
    setOriginToCenter(v2);
    scaleToMaxSize(v2,600/echelle,600/echelle);
    v2.setPosition(0.f, 0.f);

    //Vaisseau 3
    sf::Texture V3;
    V3.loadFromFile("NFSFighte.png");
    sf::Sprite v3(V3);
    setOriginToCenter(v3);
    scaleToMaxSize(v3,600/echelle,600/echelle);
    v3.setPosition(L/2.f, 0.f);

    sf::Font police;
    police.loadFromFile("Fredoka-Bold.ttf");

    //checkeredFlag
    sf::CircleShape Point0(600/echelle);
    float xc0 = L/8;
    float yc0 = l/8;
    Point0.setFillColor(sf::Color(255,255,255,63));
    Point0.setOutlineColor(sf::Color(0,0,0));
    Point0.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point0);
    scaleToMaxSize(Point0, 800/echelle, 800/echelle);
    Point0.setPosition(xc0,yc0);
    sf::Texture checkeredFlag;
    checkeredFlag.loadFromFile("checkeredFlag.png");
    sf::Sprite CheckeredFlag(checkeredFlag);
    setOriginToCenter(CheckeredFlag);
    scaleByRadius(CheckeredFlag, 420/echelle);
    CheckeredFlag.setPosition(xc0, yc0);

    
    sf::CircleShape Point1(600/echelle);
    float xc1 = 0.6*L;
    float yc1= 0.1*l;
    Point1.setFillColor(sf::Color(0,0,0,63));
    Point1.setOutlineColor(sf::Color(0,0,0));
    Point1.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point1);
    scaleToMaxSize(Point1, 800/echelle, 800/echelle);
    Point1.setPosition(xc1,yc1);
    sf::Text text1;
    text1.setFont(police);
    text1.setString("1");
    text1.setCharacterSize(450/echelle);
    text1.setFillColor(sf::Color(255,255,255,200));
    text1.setOutlineThickness(80/echelle);
    setTextCenterPosition(text1, xc1, yc1);

    sf::CircleShape Point2(600/echelle);
    float xc2 = 0.75*L;
    float yc2 = 0.6*l;
    Point2.setFillColor(sf::Color(0,0,0,63));
    Point2.setOutlineColor(sf::Color(0,0,0));
    Point2.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point2);
    scaleToMaxSize(Point2, 800/echelle, 800/echelle);
    Point2.setPosition(xc2,yc2);
    sf::Text text2;
    text2.setFont(police);
    text2.setString("2");
    text2.setCharacterSize(450/echelle);
    text2.setFillColor(sf::Color(255,255,255,200));
    text2.setOutlineThickness(80/echelle);
    setTextCenterPosition(text2, xc2, yc2);

    sf::CircleShape Point3(600/echelle);
    float xc3 = 0.5*L;
    float yc3 = 0.75*l;
    Point3.setFillColor(sf::Color(0,0,0,63));
    Point3.setOutlineColor(sf::Color(0,0,0));
    Point3.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point3);
    scaleToMaxSize(Point3, 800/echelle, 800/echelle);
    Point3.setPosition(xc3,yc3);
    sf::Text text3;
    text3.setFont(police);
    text3.setString("3");
    text3.setCharacterSize(450/echelle);
    text3.setFillColor(sf::Color(255,255,255,200));
    text3.setOutlineThickness(80/echelle);
    setTextCenterPosition(text3, xc3, yc3);
    

    sf::CircleShape Point4(600/echelle);
    float xc4 = 0.2*L;
    float yc4 = 0.7*l;
    Point4.setFillColor(sf::Color(0,0,0,63));
    Point4.setOutlineColor(sf::Color(0,0,0));
    Point4.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point4);
    scaleToMaxSize(Point4, 800/echelle, 800/echelle);
    Point4.setPosition(xc4,yc4);
    sf::Text text4;
    text4.setFont(police);
    text4.setString("4");
    text4.setCharacterSize(450/echelle);
    text4.setFillColor(sf::Color(255,255,255,200));
    text4.setOutlineThickness(80/echelle);
    setTextCenterPosition(text4, xc4, yc4);

    sf::CircleShape Point5(600/echelle);
    float xc5 = 0.1*L;
    float yc5 = 0.3*l;
    Point5.setFillColor(sf::Color(0,0,0,63));
    Point5.setOutlineColor(sf::Color(0,0,0));
    Point5.setOutlineThickness(-50/echelle);
    setOriginToCenter(Point5);
    scaleToMaxSize(Point5, 800/echelle, 800/echelle);
    Point5.setPosition(xc5,yc5);
    sf::Text text5;
    text5.setFont(police);
    text5.setString("5");
    text5.setCharacterSize(450/echelle);
    text5.setFillColor(sf::Color(255,255,255,200));
    text5.setOutlineThickness(80/echelle);
    setTextCenterPosition(text5, xc5, yc5);


    //sf::RectangleShape rectangle(sf::Vector2f(200,200));
    //sf::Color();
    //rectangle.setFillColor(sf::Color(150,30,150,100));
    //sf::RectangleShape square(sf::Vector2f(80,80));
    //square.setFillColor(sf::Color(150,30,150,255));

    //setOriginToCenter(square);
    //setOriginToCenter(rectangle);
    //square.setPosition(150,150);
    //rectangle.setPosition(150,150);

    //Initialisation
    sf::Vector2f C(xc1,yc1); //Position du premier Cercle
    sf::Vector2f V(0,0); //Vitesse initiale
    sf::Vector2f U1(xc0,yc0); //Position du vaisseau
    float theta_max = 3.14/10*57.2958;
    float angle_avant = std::atan((C.y-U1.y)/(C.x-U1.x))*57.2958;
    float angle;
    float p = 100; // Puissance moteur
    v1.setRotation(angle_avant); //Pointe vers C1

    //int i=0;
    sf::Clock clock;
    sf::Clock timer;
    window.setFramerateLimit(20);
    while (window.isOpen())
    {
        sf::Time frameTime = sf::seconds(0.1f);
        float framerate = 1 / (frameTime.asMilliseconds()*0.001);
        std::cout << "FPS: " << framerate << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.draw(v1);
        window.draw(Point0);
        window.draw(CheckeredFlag);
        window.draw(Point1);
        window.draw(Point2);
        window.draw(Point3);
        window.draw(Point4);
        window.draw(Point5);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        sf::Time time = clock.getElapsedTime();
        time.asSeconds();
        if( time >= frameTime){
            if(norme(U1,C)<150.f){
                C = sf::Vector2f(xc2,yc2);
            }
           //Créer une file pour les positions des cercles
            clock.restart();
            angle = angle_rotation(U1,V, C, theta_max, angle_avant);
            v1.setRotation(angle);
            angle_avant = angle;
            V = vitesse(U1,V,C,p);
            U1 = position(U1,V);
            v1.setPosition(U1);
        }
        window.display();
    }

    return 0;
}



#include "utils.h"
#include <cmath>
#include <stdlib.h>
#include <stdbool.h>

void setOriginToCenter(sf::Sprite &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2.f, rect.height/2.f);
}

void setOriginToCenterShape(sf::Shape &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2.f, rect.height/2.f);
}

void scaleToMaxSize(sf::Sprite &Sprite, float H, float W){
    auto bounds = Sprite.getGlobalBounds();
    float rapport_h = H/bounds.height;
    float rapport_w = W/bounds.width;
    if (rapport_h < rapport_w){ //On multiplie par le rapport L/l le plus petit
        Sprite.setScale(rapport_h,rapport_h); //On multiplie largeur et longueur par H/h
    }
    else {
        Sprite.setScale(rapport_w,rapport_w); 
    }
}

void scaleToMinSize(sf::Sprite &Sprite, float H, float W){
    auto bounds = Sprite.getGlobalBounds();
    float rapport_h = H/bounds.height;
    float rapport_w = W/bounds.width;
    if (rapport_h > rapport_w){//On multiplie par le rapport L/l le plus grand
        Sprite.setScale(rapport_h,rapport_h); //On multiplie largeur et longueur par H/h
    }
    else {
        Sprite.setScale(rapport_w,rapport_w);
    }
}

//void scaleToMinSize(sf::Sprite &sp, double size_x, double size_y)
//{
//    double scalingFactor = std::max(size_x/sp.getTextureRect().width, size_y/sp.getTextureRect().height);
//    sp.scale(scalingFactor, scalingFactor);
//}

//void scaleToMaxSize(sf::Sprite &sp, double size_x, double size_y)
//{
//    double scalingFactor = std::min(size_x/sp.getTextureRect().width, size_y/sp.getTextureRect().height);
//    sp.scale(scalingFactor, scalingFactor);
//}

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center)
{
    sf::Vector2f offset;
    offset.x = txt.getPosition().x - txt.getGlobalBounds().left - txt.getGlobalBounds().width/2.;
    offset.y = txt.getPosition().y - txt.getGlobalBounds().top - txt.getGlobalBounds().height/2.;

    txt.setPosition(center + offset);
}

void scaleByRadius(sf::Sprite &sp, int radius)
{
    double scalingFactor = 2*radius/std::sqrt(sp.getTextureRect().width*sp.getTextureRect().width + sp.getTextureRect().height*sp.getTextureRect().height);
    sp.scale(scalingFactor, scalingFactor);
}

float norm(sf::Vector2f u){
    return sqrt(pow(u.x,2) + pow(u.y,2));
}

float arg(sf::Vector2f u){
    if (u.x == 0) return u.y/abs(u.y)*M_PI/2; // + ou - pi/2 en fct du signe de y
    else if (u.x < 0 && u.y >= 0) return atan(u.y/u.x)+M_PI;
    else if (u.x < 0 && u.y < 0) return atan(u.y/u.x)-M_PI; //On veut rester dans l'intervalle ]-pi,pi]
    else return atan(u.y/u.x);
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
            
            // Verification d'une eventuelle collision
            for(int j=0; j<i; ++j){
                if (norm(sf::Vector2f(x,y)-Coord_CP[j])<1200)
                {   collision = true;
                    printf("collision btw %d and %d\n",i,j);
                }    
            }
        } while (collision);
        
        //Si pas de collision, on ajoute les coordonnees du CH
        Coord_CP.emplace_back(sf::Vector2f(x,y));
    }
    return Coord_CP;
}



sf::Vector2f verifAngle(sf::Vector2f target, sf::Vector2f pos, float angle, float thetaMax)
{
    sf::Vector2f C = target-pos;
    
    if (abs(arg(C)-angle)<thetaMax)
        return target;   
    else
    {
        int n = -1;
        float k = angle - arg(C) + 2*n*M_PI;
        while ((k <= -M_PI || k > M_PI) && n<2)
        {
            n = n+1;
            k = angle - arg(C) + 2*n*M_PI;
        }

        float alpha;
        if (0<=k && k<=M_PI) alpha = k - thetaMax; // > 0
        else alpha = k + thetaMax; // < 0

        sf::Vector2f CPrime = sf::Vector2f(C.x*cos(alpha)-C.y*sin(alpha), C.x*sin(alpha)+C.y*cos(alpha));
        return CPrime + pos;
    }
} 

float power(sf::Vector2f target , sf::Vector2f pos, float angle, float powMax)
{
    float theta = abs(arg(target-pos)-angle);
    if (theta > M_PI) theta = 2*M_PI - theta ; // On veut un angle modulo pi, un angle aigu
    
    float pow = (M_PI-theta)/M_PI*powMax;
    //if (pow < 2) return 2;
    //else return pow;
    return pow;
}