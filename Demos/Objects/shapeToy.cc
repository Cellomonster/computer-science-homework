#include "shapeToy.h"

Shape::Shape(float width, float height, float depth, int innerPoints, int outerPoitns){
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->outerPoints = outerPoints;
	this->innerPoints = innerPoints;
}

Shape::getWidth(){
	return width;
}

Shape::getHeight(){
	return height;
}

Shape::getDepth(){
	return depth;
}

Shape::getOuter(){
	return outerPoints;
}

Shape::getInner(){
	return innerPoints;
}