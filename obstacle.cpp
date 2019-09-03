#include "coordinate.h"
#include "obstacle.h"
#include <iostream>
#include <iterator>
#include <map>


using namespace std;

obstacle::obstacle() {
	height = width = angle = 0;
	top_left = coordinate(0, 0);
}

obstacle::obstacle(int height, int width, coordinate top_left, int angle) {
	this->height = height;
	this->width = width;
	this->top_left = top_left;
	this->angle = angle;
}

int obstacle::getHeight() {
	return height;
}

int obstacle::getWidth() {
	return width;
}

int obstacle::getAngle() {
	return angle;
}

coordinate obstacle::getCoordinate() {
	return top_left;
}

void obstacle::setCoordinate(coordinate c) {
	top_left = c;
}

void obstacle::setheight(int height) {
	this->height = height;
}

void obstacle::setWidth(int width) {
	this->width = width;
}

void obstacle::setAngle(int angle) {
	this->angle = angle;
}

