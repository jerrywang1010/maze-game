#pragma once
class coordinate
{
private :
	int x_coordinate;
	int y_coordinate;

public :
	coordinate();

	coordinate(int x, int y);

	int getX();

	int getY();

	void setX(int newX);

	void setY(int newY);
	
};

