#include "../src/include/SFML/Graphics.hpp"
#include "camera.h"
#include <cmath>

void windowf(){
    sf3D::Camera cam;
    sf::Thread camera(&sf3D::Camera::cameraInit, &cam);
    camera.launch();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML", sf::Style::Fullscreen);
    sf::VertexArray view(sf::Lines,2);
    view[0].position=sf::Vector2f(75,1080/2-cam.getPosY());
    view[1].position=sf::Vector2f(75+cos(cam.getAngleV()/180*3.1415)*80,1080/2-cam.getPosY()-sin(cam.getAngleV()/180*3.1415)*80);
    sf::VertexArray cube(sf::Quads,4);
    cube[0].position=sf::Vector2f(50,25+1080/2-cam.getPosY());
    cube[1].position=sf::Vector2f(100,25+1080/2-cam.getPosY());
    cube[2].position=sf::Vector2f(100,-25+1080/2-cam.getPosY());
    cube[3].position=sf::Vector2f(50,-25+1080/2-cam.getPosY());
    cube[0].color=sf::Color::Red;
    cube[1].color=sf::Color::Green;
    cube[2].color=sf::Color::Green;
    cube[3].color=sf::Color::Red;
    sf::VertexArray dir(sf::Lines,2);
    dir[0].position=sf::Vector2f(1920/2-cam.getPosZ(),1080/2-cam.getPosX());
    dir[1].position=sf::Vector2f(1920/2-cam.getPosZ()-sin(cam.getAngleH()/180*3.1415)*80,1080/2-cam.getPosX()-cos(cam.getAngleH()/180*3.1415)*80);
    sf::VertexArray sph(sf::Quads,4);
    sph[0].position=sf::Vector2f(25+1920/2-cam.getPosZ(),25+1080/2-cam.getPosX());
    sph[1].position=sf::Vector2f(-25+1920/2-cam.getPosZ(),25+1080/2-cam.getPosX());
    sph[2].position=sf::Vector2f(-25+1920/2-cam.getPosZ(),-25+1080/2-cam.getPosX());
    sph[3].position=sf::Vector2f(25+1920/2-cam.getPosZ(),-25+1080/2-cam.getPosX());
    sph[0].color=sf::Color::Green;
    sph[1].color=sf::Color::Red;
    sph[2].color=sf::Color::Magenta;
    sph[3].color=sf::Color::Blue;
    sf::Cursor cursor;
    cursor.loadFromSystem(sf::Cursor::Cross);
    window.setMouseCursor(cursor);
    window.setFramerateLimit(60);
    while(window.isOpen()){
        cube[0].position=sf::Vector2f(50,25+1080/2-cam.getPosY());
        cube[1].position=sf::Vector2f(100,25+1080/2-cam.getPosY());
        cube[2].position=sf::Vector2f(100,-25+1080/2-cam.getPosY());
        cube[3].position=sf::Vector2f(50,-25+1080/2-cam.getPosY());
        view[0].position=sf::Vector2f(75,1080/2-cam.getPosY());
        view[1].position=sf::Vector2f(75+cos(cam.getAngleV()/180*3.1415)*80,1080/2-cam.getPosY()-sin(cam.getAngleV()/180*3.1415)*80);
        dir[0].position=sf::Vector2f(1920/2-cam.getPosZ(),1080/2-cam.getPosX());
        dir[1].position=sf::Vector2f(1920/2-cam.getPosZ()-sin(cam.getAngleH()/180*3.1415)*80,1080/2-cam.getPosX()-cos(cam.getAngleH()/180*3.1415)*80);
        sph[0].position=sf::Vector2f(25+1920/2-cam.getPosZ(),25+1080/2-cam.getPosX());
        sph[1].position=sf::Vector2f(-25+1920/2-cam.getPosZ(),25+1080/2-cam.getPosX());
        sph[2].position=sf::Vector2f(-25+1920/2-cam.getPosZ(),-25+1080/2-cam.getPosX());
        sph[3].position=sf::Vector2f(25+1920/2-cam.getPosZ(),-25+1080/2-cam.getPosX());
        window.clear();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }  
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            exit(0);
        } 
        window.draw(sph);
        window.draw(dir);
        window.draw(cube);
        window.draw(view);
        window.display();
    }
}