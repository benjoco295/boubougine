#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <iostream>
#include "renderer.h"
#include "mesh.h"
#include "camera.h"

int main(){
    sf::ContextSettings settings; settings.depthBits=24; settings.majorVersion=3; settings.minorVersion=3; settings.attributeFlags=sf::ContextSettings::Core;
    sf::Window window(sf::VideoMode(800,600),"mini3d", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    glewExperimental = GL_TRUE;
    if(glewInit()!=GLEW_OK){ std::cerr<<"GLEW init failed\n"; return -1; }
    glGetError();

    Renderer renderer;
    if(!renderer.init()){ std::cerr<<"Renderer init failed\n"; return -1; }

    // simple triangle mesh
    Mesh tri;
    tri.upload({ 0.0f,0.6f,0.0f,  -0.6f,-0.6f,0.0f,  0.6f,-0.6f,0.0f });

    Camera cam; cam.setOrtho(-1,1,-1,1,-1,1);

    bool running = true;
    while(running){
        sf::Event ev;
        while(window.pollEvent(ev)){
           if(ev.type == sf::Event::MouseWheelScrolled) {
              // ev.mouseWheelScroll.delta > 0 -> zoom in, < 0 -> zoom out
              float delta = ev.mouseWheelScroll.delta;
              // ajustez le facteur selon préférence : 0.1 pour zoom progressif
              cam.addZoom(delta * 0.15f);
            }

            if(ev.type==sf::Event::Closed) running=false;
            if(ev.type==sf::Event::Resized) glViewport(0,0,ev.size.width,ev.size.height);
            if(ev.type==sf::Event::KeyPressed && ev.key.code==sf::Keyboard::Escape) running=false;
        }
        renderer.render(tri, cam);
        window.display();
    }
    return 0;
}
