#include "../src/include/SFML/Graphics.hpp"
#include "windows.h"
#include <cmath>
#include <iostream>
namespace sf3D{
    class Camera{

    private:

        float depth=100.0;
        float xPos=0.0;
        float yPos=0.0;
        float zPos=0.0;
        float vAngle=0.0;
        float hAngle=0.0;
        float velocity=10.0;
        float sensivity=0.8;

    public:

        void cameraInit(){
            sf::Vector2i mousePos;
            sf::Mouse::setPosition(sf::Vector2i(1920/2,1080/2));
            std::cout.setf(std::ios::fixed);
            std::cout.precision(1); 
            while(true){
                Sleep(10);
                mousePos=sf::Mouse::getPosition();
                std::cout<<getPosX()<<"\t"<<getPosY()<<"\t"<<getPosZ()<<"\t"<<getAngleH()<<"\t"<<getAngleV()<<std::endl;
                changeAngleV(-(mousePos.y-1080/2)*getSensivity());
                changeAngleH(-(mousePos.x-1920/2)*getSensivity());
                sf::Mouse::setPosition(sf::Vector2i(1920/2,1080/2));
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    changePosX(+cos(getAngleH()/180*3.1415)*getVelocity());
                    changePosZ(+sin(getAngleH()/180*3.1415)*getVelocity());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    changePosX(-sin(getAngleH()/180*3.1415)*getVelocity());
                    changePosZ(+cos(getAngleH()/180*3.1415)*getVelocity());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    changePosX(-cos(getAngleH()/180*3.1415)*getVelocity());
                    changePosZ(-sin(getAngleH()/180*3.1415)*getVelocity());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    changePosX(+sin(getAngleH()/180*3.1415)*getVelocity());
                    changePosZ(-cos(getAngleH()/180*3.1415)*getVelocity());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    changePosY(getVelocity());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
                    changePosY(-getVelocity());
                }
            }
        }

        void setVelocity(float v){
            velocity=v;
        }
        float getVelocity(){
            return velocity;
        }
        void setSenivity(float s){
            sensivity=s;
        }
        float getSensivity(){
            return sensivity;
        }
        void changeAngleV(float v){
            if(vAngle+v>90.0){
                vAngle=90.0;
            }
            if(vAngle+v<-90.0){
                vAngle=-90.0;
            }
            vAngle+=v;
        }
        void changeAngleH(float h){
            hAngle+=h;
            if(hAngle<0){
                hAngle+=360.0;
            }
            if(hAngle>360){
                hAngle-=360.0;
            }
        }
        float getAngleV(){
            return vAngle;
        }
        float getAngleH(){
            return hAngle;
        }
        void changePosX(float x){
            xPos+=x;
        }
        void changePosY(float y){
            yPos+=y;
        }
        void changePosZ(float z){
            zPos+=z;
        }
        float getPosX(){
            return xPos;
        }
        float getPosY(){
            return yPos;
        }
        float getPosZ(){
            return zPos;
        }
    };
}
