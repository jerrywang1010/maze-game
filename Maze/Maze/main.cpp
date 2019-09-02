//
//  main.cpp
//  maze
//
//  Created by Nan Ni on 2019-08-24.
//  Copyright © 2019 Nan Ni. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <sstream>


using namespace std;

//test 20180824

/// testetstetstet
//test git ignore

void drawClock(sf::RenderWindow& window,sf::Text myNum);
void drawBrickWall(sf::RenderWindow& window, sf::Sprite sprite, float x_gap, float y_gap, int num_of_walls);
bool collision(int x_gap, int y_gap, int x_pos, int y_pos);

int main(int argc, const char * argv[]) {

	sf::RenderWindow window(sf::VideoMode(2000, 1000), "Maze");

	sf::Texture texture;

	texture.loadFromFile("brickwall.png");
    //texture.loadFromFile("/Users/nan/Desktop/projects/maze/brickwall.png");
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
	
	int x_gap = 300;
	int y_gap = 300;

	int x_pos = 0;
    int y_pos = 0;

	drawBrickWall(window, sprite, 300.f, 300.f, 3);
	//first bar 97/768
    
    
    
    sf::Text myNum;
    //window.display();

    

    int index = 0;

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
					x_pos = event.mouseMove.x;
					y_pos = event.mouseMove.y; 
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
		
		if (collision(300, 300, x_pos, y_pos)) {
            index++;
			cout << index << endl;
		}
        
        
        stringstream ss;
        ss << index;
        myNum.setString(ss.str().c_str());
        sf::Font arial;
        arial.loadFromFile("arial.ttf");
        myNum.setCharacterSize(50);
        myNum.setFont(arial);
        myNum.setFillColor(sf::Color::Red);
        myNum.setPosition(1500, 500);
        window.clear();
        window.draw(myNum);
        window.draw(sprite);
        drawBrickWall(window, sprite, 300.f, 300.f, 3);
        window.display();

    }

    window.clear();
    window.display();
    return 0;
}


void drawClock(sf::RenderWindow& window,sf::Text myNum){
        sf::Font arial;
        if(!arial.loadFromFile("arial.ttf")){
            cout << "can't load font" << endl;
        }
        //myNum.setString("hello world");
        //myNum.setString(ss.str());
        myNum.setCharacterSize(50);
        myNum.setFont(arial);
        myNum.setFillColor(sf::Color::Red);
        myNum.setPosition(1500,500);
        window.clear();
        window.draw(myNum);
        window.display();
    
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

//wall is 97x769
bool collision(int x_gap, int y_gap, int x_pos, int y_pos) {
	if (x_pos % x_gap < 97) {
		//odd number
		if ((x_pos / 300) % 2 == 1) {
			if (y_pos > 300 && y_pos < 1000) return true;
		}
		//even number
		else {
			if (y_pos > 0 && y_pos < 769) return true;
		}
	}
	return false;
}
