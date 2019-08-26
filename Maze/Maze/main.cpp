//
//  main.cpp
//  maze
//
//  Created by Nan Ni on 2019-08-24.
//  Copyright © 2019 Nan Ni. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;

//test 20180824

/// testetstetstet
//test git ignore

void drawBrickWall(sf::RenderWindow& window, sf::Sprite sprite, float x_gap, float y_gap, int num_of_walls);


int main(int argc, const char * argv[]) {

	sf::RenderWindow window(sf::VideoMode(2000, 1000), "Maze");

	sf::Texture texture;

	texture.loadFromFile("brickwall.png");
	if (!texture.loadFromFile("brickwall.png")) {
		cout << "can not load image" << endl;
	}
	texture.setSmooth(true);
	texture.setRepeated(true);

	//drawing wall 1
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.draw(sprite);

	////drawing wall 2

	////sprite.setTexture(texture);
	//sprite.move(sf::Vector2f(500.f, 500.f));
	//window.draw(sprite);


	////drawing wall 3
	//sprite.setTexture(texture);
	//sprite.move(sf::Vector2f(1000.f, -500.f));
	//window.draw(sprite);
	
	drawBrickWall(window, sprite, 300.f, 300.f, 3);


	window.display();

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

//fuction that draws wall on window, sprite has to be initialize to texture first, x gap is the horizontal distance between two wall
//y gap is the vertical distance between top of window and of every even walls
void drawBrickWall(sf::RenderWindow& window, sf::Sprite sprite, float x_gap, float y_gap, int num_of_walls) {
	for (int i = 0; i < num_of_walls; i++) {
		sprite.move(sf::Vector2f(x_gap, y_gap));
		y_gap = -y_gap;
		window.draw(sprite);
	}
}
