#pragma once
class obstacle
{
private :
	coordinate top_left;
	int height;
	int width;

	int angle;

public :
	obstacle();
	obstacle(int height, int width, coordinate top_left, int angle);

	int getHeight();
	int getWidth();
	int getAngle();
	coordinate getCoordinate();

	void setCoordinate(coordinate c);
	void setheight(int height);
	void setWidth(int width);
	void setAngle(int angle);


};

