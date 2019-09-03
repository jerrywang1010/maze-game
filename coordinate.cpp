#include "coordinate.h"


coordinate::coordinate() {
	x_coordinate = 0;
	y_coordinate = 0;
}

coordinate::coordinate(int x, int y) {
	x_coordinate = x;
	y_coordinate = y;
}

int coordinate::getX() {
	return x_coordinate;
}

int coordinate::getY() {
	return y_coordinate;
}

void coordinate::setX(int newX) {
	x_coordinate = newX;
}

void coordinate::setY(int newY) {
	y_coordinate = newY;
}
