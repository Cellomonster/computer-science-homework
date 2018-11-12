/*
File: shapeToy.h
-----------------
Shape class.

Author: Julian Triveri
10/08/18
*/

#ifndef toy_h
#define toy_h

/* Class: Meld
 * ---------------------------------------------------------------------------
 * Represents a meld of cards. Handles checking and adding of cards*/
class Meld{
private:
	float height;
	float width;
	float depth;
	int outerPoints;
	int innerPoints;

public:
	Shape(int innerPoints, int outerPoitns);
	~Shape();

	bool willFit(Shape hole);

	Shape(float width, float height, float depth, int innerPoints, int outerPoitns);//{
	// 	this->width = width;
	// 	this->height = height;
	// 	this->depth = depth;
	// 	this->outerPoints = outerPoints;
	// 	this->innerPoints = innerPoints;
	// }

	int getOuter();
	int getInner();
	float getHeight();
	float getWidth();
	float getDepth();
};

#endif