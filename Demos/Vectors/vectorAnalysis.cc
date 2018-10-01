//=============================================================
// Jaimie Kelley
// 9/26/2018
// vectorAnalysis.cc
// This program illustrates basic vector operations with a
// randomly created vector.
// Adapted from Matt Kretchmar's array1.cc
//=============================================================

#include <time.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int findMax (vector<long int>, int );
int findSum (vector<long int>, int );
void selectionSort(vector<int> & numVector);

//=============================================================
// main
//=============================================================
int main ( void )
{
    srand(time(NULL));
    int n = 10;     // number of items in array
    vector<long int> nums(10, rand());

    for (int i = 0; i < n; i++ )
    {
        //nums.at(i) = rand();
    }


    cout << "Largest value is " << findMax(nums,n) << endl;
    cout << "Sum of values is " << findSum(nums,n) << endl;

    selectionSort(nums);
    for (int i = 0; i < n; i++ )
    {
        cout << nums.at(i) << " ";
    }
    cout << endl;

    return 0;
}

//=============================================================
// findMax
// Find the maximum value in a vector.
// Parameters:
//   - vector
//   - size of vector
// Return Value:
//   - largest value in vector
//=============================================================

int findMax ( vector<long int> numV, int n )
{
    int max = numV.at(0);
    for ( int i = 1; i < n; i++ )
        if ( numV.at(i) > max )
            max = numV.at(i);

    return max;
}

int findMin ( vector<long int> numV, int n )
{
    int max = numV.at(0);
    for ( int i = 1; i < n; i++ )
        if ( numV.at(i) < max )
            max = numV.at(i);

    return max;
}

//=============================================================
// findSum
// Find the sum of values in a vector.
// Parameters:
//   - vector
//   - size of vector
// Return Value:
//   - sum of values in array
//=============================================================

int findSum( vector<long int> numV, int n )
{
    int total = 0;
    for ( int i = 0; i < n; i++ )
        total += numV.at(i);

    return total;
}

void swapTwoElements(vector<long> & numVector, int pos1, int pos2){
  long int temp = numVector.at(pos1);
  numVector.at(pos1) = numVector.at(pos2);
  numVector.at(pos2) = temp;
}

//=============================================================
// selectionSort
// Sort the values in the vector in increasing order
// Parameters:
//   - vector
//   - size of vector
// Return Value:
//   - none, but vector values are rearranged
//=============================================================

void selectionSort (vector<long int> & numVector ){
  for(int i = 0; i < numVector.size(); i++){
    long smallest = numVector.at(i);
  }
    /*for ( int i = 0; i < n-1; i++ )
    {
        int smallest = i;
        for ( int j = i+1; j < n; j++ )
            if ( array[j] < array[smallest] )
                smallest = j;

        int temp = array[smallest];
        array[smallest] = array[i];
        array[i] = temp;
    }*/
}
//=============================================================
