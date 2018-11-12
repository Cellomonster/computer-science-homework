//=============================================================
// Matt Kretchmar
// 1/31/2017
// array1.cc
// This program illustrates basic C array operations with a
// randomly created array.
//=============================================================

#include <time.h>
#include <iostream>
using namespace std;

int findMax (int [], int );
int findSum (int [], int );
void selectionSort ( int [], int );
int binarySearch(int [], int, int);

//=============================================================
// main
//=============================================================
int main ( void )
{
    srand(time(NULL));
    int n = 10;     // number of items in array
    int nums[n];    // declare an array of n integers

    for (int i = 0; i < n; i++ )
    {
        nums[i] = rand() % 100;
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Largest value is " << findMax(nums,n) << endl;
    cout << "Sum of values is " << findSum(nums,n) << endl;

    selectionSort(nums,n);
    for (int i = 0; i < n; i++ )
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << binarySearch(nums, n, 50) << endl;

    return 0;
}

//=============================================================
// findMax
// Find the maximum value in an array.
// Parameters:
//   - array
//   - size of array
// Return Value:
//   - largest value in array
//=============================================================

int findMax ( int array[], int n )
{
    int max = array[0];
    for ( int i = 1; i < n; i++ )
        if ( array[i] > max )
            max = array[i];

    return max;
}

//=============================================================
// findSum
// Find the sum of values in an array.
// Parameters:
//   - array
//   - size of array
// Return Value:
//   - sum of values in array
//=============================================================

int findSum( int array[], int n )
{
    int total = 0;
    for ( int i = 0; i < n; i++ )
        total += array[i];

    return total;
}

//=============================================================
// selectionSort
// Sort the values in the array in increasing order
// Parameters:
//   - array
//   - size of array
// Return Value:
//   - none, but array values are rearranged
//=============================================================

void selectionSort ( int array[], int n )
{
    for ( int i = 0; i < n-1; i++ )
    {
        int smallest = i;
        for ( int j = i+1; j < n; j++ )
            if ( array[j] < array[smallest] )
                smallest = j;

        int temp = array[smallest];
        array[smallest] = array[i];
        array[i] = temp;
    }
}

//=============================================================
// binarySearch
// Return the index of a given value
// Parameters:
//   - array
//   - size of array
//   - target value
// Return Value:
//   - index of target value
//=============================================================

int binarySearch(string key, Vector<string> &vec, int p1, int p2){
    if(p1 > p2) return -1;
    int mid = (p1+p2)/2;
    if(key == vec[mid]) return mid;
    if(key < )
}

//=============================================================
