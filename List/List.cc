/*
File: List.cc
--------------------
List container class for doubles

Author: Julian Triveri
11/17/18
*/

#define DEFAULT_LIST_SIZE 10

#include "List.h"
#include <string>
#include <iostream>
#include <sstream>

/* Default Constructor */
List::List(){
	_length = 0;
	_arrayLength = 10;
	_values = new double[DEFAULT_LIST_SIZE];
}

/* Constructor: List
 * Usage: List(<List>)
 * Parameters: List to copy
 * ---------------------------------------------------------------------------
 * Creates a new List with copied values from another */
List::List(const List& l){
	_length = 0;
	_arrayLength = 10;
	_values = new double[DEFAULT_LIST_SIZE];

	for(int i = 0; i < l.length(); i++)
		append(l.valueAt(i));
}

/* Destructor */
List::~List(){
	delete[] _values;
}

/* Function: resize [PRIVATE]
 * Usage: List.resize();
 * ---------------------------------------------------------------------------
 * Resizes the _values array to twice its length */
void List::resize(){
	double *temp = new double[_arrayLength * 2];

	for(int i = 0; i < _length; i++)
		temp[i] = _values[i];

	delete[] _values;
	_values = temp;

	_arrayLength *= 2;
}

/* Function: outOfBounds [PRIVATE]
 * Usage: List.outOfBounds();
 * ---------------------------------------------------------------------------
 * Prints error message and exits the program */
void List::outOfBounds() const{
	std::cout << "error index out of bounds" << std::endl;
	exit(1);
}

/* Function: length 
 * Usage: List.length();
 * Returns: int
 * ---------------------------------------------------------------------------
 * Returns length of the list */
int List::length() const{
	return _length;
}

/* Function: isEmpty 
 * Usage: List.isEmpty();
 * Returns: boolean
 * ---------------------------------------------------------------------------
 * Returns wether the list is empty or not */
bool List::isEmpty() const{
	return !_length;
}

/* Operator: [] 
 * Usage: List[<int>];
 * Parameters: index
 * Returns: double
 * ---------------------------------------------------------------------------
 * Returns double value at specified int index */
double& List::operator[](int i){
	if(i < 0 || i >= _length){
		outOfBounds();
	}

	return _values[i];
}

/* Function: valueAt [PRIVATE]
 * Usage: List.valueAt(<int>);
 * Parameters: index
 * Returns: double
 * ---------------------------------------------------------------------------
 * Returns double value of list at index as constant */
double List::valueAt(int i) const{
	if(i < 0 || i >= _length){
		std::cout << "Julian! What are you doing! This shouldn't happen!" << std::endl;
		exit(1);
	}

	return _values[i];
}

/* Function: toString
 * Usage: List.toString();
 * Returns: string
 * ---------------------------------------------------------------------------
 * Returns string of values in the Index */
std::string List::toString() const{
	std::stringstream os;

	for(int i = 0; i < _length; i++){
		os << _values[i] << " ";
	}

	return os.str();
}

/* Operator: << 
 * Usage: Stream << List;
 * Returns: ostream
 * ---------------------------------------------------------------------------
 * Appends List.toString() to an output stream */
std::ostream& operator<<(std::ostream &os, const List &l){
	os << l.toString(); 
	return os;
}

/* Function: append
 * Usage: List.append(<double>)
 * Parameters: value to append
 * ---------------------------------------------------------------------------
 * Adds a double value to the end of the list */
void List::append(double d){
	if(_arrayLength == _length)
		resize();

	_values[_length] = d;
	_length++;
}

/* Function: insert
 * Usage: List.insert(<double>, <int>)
 * Parameters: value to insert, index
 * ---------------------------------------------------------------------------
 * Inserts a double value at the given index */
void List::insert(double d, int i){
	if(i < 0 || i > _length){
		outOfBounds();
	}

	if(_arrayLength == _length)
		resize();

	for(int j = _length; j > i; j--)
		_values[j] = _values[j - 1];

	_values[i] = d;
	_length++;
}

/* Function: remove
 * Usage: List.remove(<double>, <int>)
 * Parameters: index
 * ---------------------------------------------------------------------------
 * Removes a double value at the given index */
void List::remove(int i){
	if(i < 0 || i >= _length){
		outOfBounds();
	}

	for(int j = i; j < _length - 1; j++)
		_values[j] = _values[j + 1];

	_length--;
}

/* Operator: +
 * Usage: list1 + list2
 * Returns: right list appended to left list
 * ---------------------------------------------------------------------------
 * Returns a new list with the values of the rvalue list appended to the values
 * of the lvalue list */
List operator+(const List& l1, const List& l2){
	List temp = List(l1);

	for(int i = 0; i < l2.length(); i++)
		temp.append(l2.valueAt(i));

	return temp;
}

/* Operator: =
 * Usage: list1 = list2
 * Returns: Copy of list2
 * ---------------------------------------------------------------------------
 * Assigns values lvalue list to values of rvalue list, and returns a copy of the rvalue list */
List & List::operator=(const List & l){
	_length = l.length();
	_arrayLength = l.length();
	
	delete[] _values;
	_values = new double[_arrayLength];
	
	for(int i = 0; i < _length; i++)
		_values[i] = l.valueAt(i);

	return *this;
}

/* Functions: clear
 * Usage: List.clear()
 * ---------------------------------------------------------------------------
 * Clears the contents of a list */
void List::clear(){
	delete[] _values;
	_length = 0;
	_arrayLength = 10;
	_values = new double[DEFAULT_LIST_SIZE];
}



