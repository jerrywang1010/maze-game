//
//  main.cpp
//  maze
//
//  Created by Nan Ni on 2019-08-24.
//  Copyright © 2019 Nan Ni. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
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
    
    sf::Image backGround;
    
    backGround.loadFromFile("stone.jpg");
    sf::Texture textureMain;
    
    textureMain.loadFromImage(backGround);
    //textureMain.loadFromFile("stone.jpg");
    
    textureMain.setRepeated(true);
    textureMain.setSmooth(true);
    
    
    sf::Sprite backSprite;
    
    backSprite.setTexture(textureMain);
    backSprite.setPosition(0, 0);

    // load background
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	background_texture.loadFromFile("background.png");
	if (!background_texture.loadFromFile("background.png")) {
		cout << "can not load background" << endl;
	}
	background_texture.setSmooth(true);
	background_sprite.setTexture(background_texture);
	//window.draw(background_sprite);


	//load entrance sprite
	sf::Texture entrance_texture;
	sf::Sprite entrance_sprite;
	entrance_texture.loadFromFile("entrance.png");
	if (!entrance_texture.loadFromFile("entrance.png")) {
		cout << "can not load entrance" << endl;
	}
	entrance_texture.setSmooth(true);
	entrance_sprite.setTexture(entrance_texture);
	entrance_sprite.setPosition(0, 800);


	//load exit sprite
	sf::Sprite exit_sprite = entrance_sprite;
	exit_sprite.setPosition(1500, 100);

	sf::Texture brick_wall_texture;
	brick_wall_texture.loadFromFile("brickwall.png");
	if (!brick_wall_texture.loadFromFile("brickwall.png")) {
		cout << "can not load brick" << endl;
	}
	brick_wall_texture.setSmooth(true);
	brick_wall_texture.setRepeated(true);

	//drawing wall 1
	sf::Sprite brick_wall_sprite;
	brick_wall_sprite.setTexture(brick_wall_texture);
	//window.draw(brick_wall_sprite);
    
    sf::Sprite whiteBlock;
    sf::Texture backTexture;
    backTexture.loadFromFile("stone_light.jpg");
    backTexture.setSmooth(true);
    backTexture.setRepeated(true);
    whiteBlock.setTexture(backTexture);
    whiteBlock.setPosition(1600, 0);
    
    sf::Sprite Clock;
    sf::Texture clock_brick;
    clock_brick.loadFromFile("clock_BG.png");
    clock_brick.setRepeated(true);
    clock_brick.setSmooth(true);
    Clock.setTexture(clock_brick);
    Clock.setPosition(1925, 50);
    Clock.setRotation(90);

	////drawing wall 2

	////sprite.setTexture(texture);
	//sprite.move(sf::Vector2f(500.f, 500.f));
	//window.draw(sprite);

//    whiteBlock.setTexture(backTexture);
//    whiteBlock.setPosition(1600, 0);

	
	int x_gap = 300;
	int y_gap = 300;

	int x_pos = 0;
    int y_pos = 0;

	drawBrickWall(window, brick_wall_sprite, 300.f, 300.f, 3);
	//first bar 97/768
    
    
    
    sf::Text myNum;
    //window.display();

    sf::Clock clock;

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
                    cout << event.mouseButton.x << endl;
                    cout << event.mouseButton.y << endl;
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
        
        if(x_pos <= 1000){
            clock.restart();
        }
        
        int time = clock.getElapsedTime().asSeconds();
        int seconds_0 = 0;
        int seconds_1 = 0;
        int minute_0 = 0;
        int minute_1 = 0;
        
        if(time<60){
            seconds_0 = time%10;
            seconds_1 = time/10;
        }
        else{
            int seconds = time%60;
            int minute = time/60;
            seconds_0 = seconds%10;
            seconds_1 = seconds/10;
            minute_0 = minute%10;
            minute_1 = minute/10;
        }
        
        
        stringstream ss;
        ss << minute_1 << " "<< minute_0 << " : " << seconds_1 <<" " << seconds_0 ;
        myNum.setString(ss.str().c_str());
        sf::Font arial;
        arial.loadFromFile("arial.ttf");
        myNum.setCharacterSize(60);
        myNum.setFont(arial);
        myNum.setFillColor(sf::Color(139,0,0));
        myNum.setPosition(1695, 50);
        
        window.clear();
       // window.draw(backSprite);//draw main game board background
        //window.draw(sprite);//draw first brick
        //window.draw(background);//draw score board background
        //window.draw(Clock);//draw clock background
        //drawBrickWall(window, sprite, 300.f, 300.f, 5);//draw brick wall pattern
        //window.draw(myNum);//draw clock with numbers
		window.draw(background_sprite);
		window.draw(entrance_sprite);
		window.draw(exit_sprite);
        window.draw(brick_wall_sprite);
        window.draw(whiteBlock);
        drawBrickWall(window, brick_wall_sprite, 300.f, 300.f, 5);
        window.draw(myNum);
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
        myNum.setPosition(1400,20);
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
