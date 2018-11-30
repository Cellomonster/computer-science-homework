/*
File: List.h
--------------------
List container class for doubles

Author: Julian Triveri
11/16/18
*/

#ifndef julian_triveri_list_h
#define julian_triveri_list_h

#include <string>
#include <iostream>

/* Class:Lis
t * Container for double values */
class List{
private:
	int _arrayLength;
	int _length;
	double *_values;

	void resize();
	void outOfBounds() const;
public:
	//Constructors
	List();
	List(const List& l);
	~List();

	//Access
	int length() const;
	bool isEmpty() const;

	double &operator[](int);
	double valueAt(int) const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream&, const List&);

	//Modifiers
	void append(double);
	void insert(double, int);
	void remove(int);

	friend List operator+(const List&, const List&);
	List & operator=(const List&);

	void clear();

};

#endif