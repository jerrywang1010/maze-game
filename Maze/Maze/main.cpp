//
//  main.cpp
//  maze
//
//  Created by Nan Ni on 2019-08-24.
//  Copyright © 2019 Nan Ni. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>



//test 20180824

/// testetstetstet

int main(int argc, const char * argv[]) {
    sf::RenderWindow window(sf::VideoMode(640,480),"Maze");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    
                    break;
                case sf::Event::Resized:
                    
                    break;
                case sf::Event::LostFocus:
                    
                    break;
                case sf::Event::GainedFocus:
                    
                    break;
                case sf::Event::TextEntered:
                    
                    break;
                case sf::Event::KeyPressed:
                    
                    break;
                case sf::Event::KeyReleased:
                    
                    break;
                case sf::Event::MouseWheelMoved:
                    
                    break;
                case sf::Event::MouseWheelScrolled:
                    
                    break;
                case sf::Event::MouseButtonPressed:
                    
                    break;
                case sf::Event::MouseButtonReleased:
                    
                    break;
                case sf::Event::MouseMoved:
                    
                    break;
                case sf::Event::MouseEntered:
                    
                    break;
                case sf::Event::MouseLeft:
                    
                    break;
                case sf::Event::JoystickButtonPressed:
                    
                    break;
                case sf::Event::JoystickButtonReleased:
                    
                    break;
                case sf::Event::JoystickMoved:
                    
                    break;
                case sf::Event::JoystickConnected:
                    
                    break;
                case sf::Event::JoystickDisconnected:
                    
                    break;
                case sf::Event::TouchBegan:
                    
                    break;
                case sf::Event::TouchMoved:
                    
                    break;
                case sf::Event::TouchEnded:
                    
                    break;
                case sf::Event::SensorChanged:
                    
                    break;
                case sf::Event::Count:
                    
                    break;
            }
            
        }
    }
    window.clear();
    window.display();
    return 0;
}
