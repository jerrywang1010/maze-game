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
    backTexture.loadFromFile("white_large.jpg");
    backTexture.setSmooth(true);
    backTexture.setRepeated(true);
    whiteBlock.setTexture(backTexture);
    whiteBlock.setPosition(1600, 0);

	
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
        int seconds = 0;
        int minute = 0;
        
        seconds = time%60;
        minute = time/60;
        
        
        stringstream ss;
        ss << minute << ":" <<seconds;
        myNum.setString(ss.str().c_str());
        sf::Font arial;
        arial.loadFromFile("arial.ttf");
        myNum.setCharacterSize(50);
        myNum.setFont(arial);
        myNum.setFillColor(sf::Color::Red);
        myNum.setPosition(1750, 50);
        
        window.clear();
		window.draw(background_sprite);
		window.draw(entrance_sprite);
		window.draw(exit_sprite);
        window.draw(brick_wall_sprite);
        window.draw(whiteBlock);
		//drawObstalce(window, brick_wall_sprite, walls);
		moveObstacle(window, brick_wall_sprite, walls, 3, true, false, false, false);
		updateSet(set, walls);
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