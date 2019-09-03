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
#include <vector>
#include "C:\Users\jerry\source\repos\Jolie-Ni\maze-game/coordinate.h"
#include "C:\Users\jerry\source\repos\Jolie-Ni\maze-game/obstacle.h"
#include <unordered_set>
#include <array>


namespace std
{
	template<typename T, size_t N>
	struct hash<array<T, N> >
	{
		typedef array<T, N> argument_type;
		typedef size_t result_type;

		result_type operator()(const argument_type& a) const
		{
			hash<T> hasher;
			result_type h = 0;
			for (result_type i = 0; i < N; ++i)
			{
				h = h * 31 + hasher(a[i]);
			}
			return h;
		}
	};
}

using namespace std;

void drawClock(sf::RenderWindow& window,sf::Text myNum);
void drawObstalce(sf::RenderWindow& window, sf::Sprite sprite, vector <obstacle> walls);
void moveObstacle(sf::RenderWindow& window, sf::Sprite sprite, vector <obstacle>& walls, int index, bool move_right, bool move_left, bool move_up, bool move_down);
bool collision(unordered_set<array<int, 2>>& set, int x_pos, int y_pos);
void deleteGameArray(int** gameArray);
void updateSet(unordered_set<array<int, 2>>& set, vector<obstacle> walls);

int main(int argc, const char * argv[]) {
	//test new class


	//2D array that contains all the pixel locations on the screen
	//1 means occupied by a obstacle and 0 means unoccupied.
	//int gameArray[1600][1000];

	//have to initialize the array dynamically to avoid memeory overflow.
	//int** gameArray = new int* [1000];
	//for (int i = 0; i < 1000; i++) {
	//	gameArray[i] = new int[1600];
	//}
	unordered_set<array<int, 2>> set;

	// vector containing all brick walls
	vector <obstacle> walls;
	for (int i = 0; i < 4; i++) {
		coordinate c(i * 200, 0);
		obstacle o(769, 96, c, 0);
		walls.push_back(o);
	}

	updateSet(set, walls);

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



	//load entrance sprite
	sf::Texture entrance_texture;
	sf::Sprite entrance_sprite;
	entrance_texture.loadFromFile("white_entrance.png");
	if (!entrance_texture.loadFromFile("white_entrance.png")) {
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
    
    sf::Sprite Blood_1;
    sf::Texture blood_1;
    blood_1.loadFromFile("blood_1.png");
    blood_1.setSmooth(true);
    blood_1.setRepeated(true);
    Blood_1.setTexture(blood_1);
    Blood_1.setPosition(1630, 200);
    Blood_1.setScale(0.5, 0.5);
    
    sf::Sprite Blood_2;
    sf::Texture blood_2;
    blood_2.loadFromFile("blood_2.png");
    blood_2.setSmooth(true);
    blood_2.setRepeated(true);
    Blood_2.setTexture(blood_2);
    Blood_2.setPosition(1630, 200);
    Blood_2.setScale(0.5, 0.5);
    
    sf::Sprite Blood_3;
    sf::Texture blood_3;
    blood_3.loadFromFile("blood_3.png");
    blood_3.setSmooth(true);
    blood_3.setRepeated(true);
    Blood_3.setTexture(blood_3);
    Blood_3.setPosition(1630, 200);
    Blood_3.setScale(0.5, 0.5);
    
    sf::Sprite Blood_4;
    sf::Texture blood_4;
    blood_4.loadFromFile("blood_4.png");
    blood_4.setSmooth(true);
    blood_4.setRepeated(true);
    Blood_4.setTexture(blood_4);
    Blood_4.setPosition(1630, 200);
    Blood_4.setScale(0.5, 0.5);
    

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

	//brick wall is 96 x 769
    
    
    
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
		

		if (collision(set, x_pos, y_pos)) {
			cout << "collision !!!" << endl;
		}
		else {
			cout << "not !!" << endl;
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
		moveObstacle(window, brick_wall_sprite, walls, 3, true, false, false, false);
		updateSet(set, walls);
        if(index <= 50){
            window.draw(Blood_4);
        }
        else if(index > 50 && index <= 100){
            window.draw(Blood_3);
        }
        else if(index > 100 && index <= 150){
            window.draw(Blood_2);
        }
        else if(index > 150 && index <= 200){
            window.draw(Blood_1);
        }
        else{
            break;
        }
        window.draw(myNum);
        window.display();

    }

    window.clear();
    window.display();
	
    return 0;
}

//delete game array
void deleteGameArray(int** gameArray) {
	for (int i = 0; i < 1000; i++) {
		delete gameArray[i];
	}
	delete gameArray;
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
//void drawBrickWall(sf::RenderWindow& window, sf::Sprite sprite, float x_gap, float y_gap, int num_of_walls) {
//	for (int i = 0; i < num_of_walls; i++) {
//		sprite.move(sf::Vector2f(x_gap, y_gap));
//		y_gap = -y_gap;
//		window.draw(sprite);
//	}
//}

bool collision(unordered_set<array<int, 2>>& set, int x_pos, int y_pos) {
	if (x_pos >= 1600 || x_pos < 0) return false;
	if (y_pos < 0 || y_pos >= 1000) return false;

	//return gameArray[x_pos][y_pos] == 1;
	array<int, 2> key = { x_pos, y_pos };
	auto search = set.find(key);

	return search != set.end();
}

void updateSet(unordered_set<array<int, 2>>& set, vector<obstacle> walls) {
	set.clear();
	for (int i = 0; i < walls.size(); i++) {
		coordinate top_left = walls[i].getCoordinate();
		int x = top_left.getX();
		int y = top_left.getY();
		int height = walls[i].getHeight();
		int width = walls[i].getWidth();

		for (int row = x; row >= 0 && row < x + width; row++) {
			for (int col = y; col >= 0 && col < y + height; col++) {
				array<int, 2> arr = { row, col };
				set.insert(arr);
			}
		}
	}
}


//wall is 97x769

void drawObstalce(sf::RenderWindow& window, sf::Sprite sprite, vector <obstacle> walls) {
	for (int i = 0; i < walls.size(); i++) {
		sprite.setPosition(walls[i].getCoordinate().getX(), walls[i].getCoordinate().getY());
		sprite.setRotation(walls[i].getAngle());
		window.draw(sprite);
	}
}

//move the piece of wall indiceted by index in vector walls in the direction specified
void moveObstacle(sf::RenderWindow& window, sf::Sprite sprite, vector <obstacle>& walls, int index, bool move_right, bool move_left, bool move_up, bool move_down) {
	obstacle oldWall = walls[index];
	obstacle newWall(oldWall.getHeight(), oldWall.getWidth(), oldWall.getCoordinate(), oldWall.getAngle());
	coordinate oldCoordinate = oldWall.getCoordinate();
	if (move_right && oldCoordinate.getX() < 1600 - 97) {
		coordinate newCoordinate(oldCoordinate.getX() + 1, oldCoordinate.getY());
		newWall.setCoordinate(newCoordinate);
		walls[index] = newWall;
	}
	else if (move_left && oldCoordinate.getX() > 0) {
		coordinate newCoordinate(oldCoordinate.getX() - 1, oldCoordinate.getY());
		newWall.setCoordinate(newCoordinate);
		walls[index] = newWall;
	}
	else if (move_up && oldCoordinate.getY() > 0) {
		coordinate newCoordinate(oldCoordinate.getX(), oldCoordinate.getY() - 1);
		newWall.setCoordinate(newCoordinate);
		walls[index] = newWall;
	}
	else if (move_down && oldCoordinate.getY() < 1000 - 769) {
		coordinate newCoordinate(oldCoordinate.getX(), oldCoordinate.getY() + 1);
		newWall.setCoordinate(newCoordinate);
		walls[index] = newWall;
	}
	drawObstalce(window, sprite, walls);
}