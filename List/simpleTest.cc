#define RED "\033[1;31m" <<
#define RST "\033[0m" 
#define NLN << "\033[0m\n"
#define SE cout << "--------------------------------------------------\n";
#define COUT cout << 

#include "List.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){
	List list = List();

	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE

	COUT "Append 5" NLN;
	list.append(5);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Append 4.7777777" NLN;
	list.append(4.7777777);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Append -3" NLN;
	list.append(-3);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Append 10 elements" NLN;
	for(int i = 0; i < 10; i++)
		list.append(1);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Clear" NLN;
	list.clear();
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Insert 50 elements and insert at 6" NLN;
	for(int i = 0; i < 50; i++)
		list.insert(i, i);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	list.insert(2, 6);
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Remove 10 elements at index 3" NLN;
	for(int i = 0; i < 10; i++)
		list.remove(3);
	COUT RED list.length() NLN;
	COUT RED list NLN;

	COUT "Test =" NLN;
	List l2 = List();
	for(int i = 0; i < 19; i++)
		l2.append(-i);

	list = l2;
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "Test +" NLN;
	list = list + l2;
	COUT RED list.length() NLN;
	COUT RED list NLN;
	SE
	
	COUT "\n\n\nTest out of bounds" RED " Program should quit!" NLN;
	list[-10];

	return 0;
}