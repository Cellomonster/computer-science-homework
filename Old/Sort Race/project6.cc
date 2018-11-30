/*
File: project6.cc
-----------------
Measure times of different sorts

Author: Julian Triveri
10/08/18
*/

#include <iostream>
//#include <thread>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sys/time.h>
using namespace std;

//Used in TimeTrialSet print() function
string typeToString[4] = {"selection", "insertion", "merge", "quick"};

/* Struct: TimeTrial
 * ---------------------------------------------------------------------------
 * Represents a set of timed results based on collection size and algorithm */
struct TimeTrial{
	long int containerSize;
	vector<double> times;

	void print(){
													cout << "    Container size: " << containerSize << "\n";
		for(double d : times)	cout << "        " << d << "\n";
													cout << "Average time: " << (double)accumulate(times.begin(), times.end(), 0.0)/times.size() << " seconds\n";
	}
};

/* Struct: TimeTrialSet
 * ---------------------------------------------------------------------------
 * Represents a set of TimeTrial structs belonging to a single algorithm */
struct TimeTrialSet{
	int sortType;
	vector<TimeTrial> timeTrials;

	void print(){
		cout << "Sort algorithm: " << typeToString[sortType - 1] << "\n";
		for(TimeTrial t : timeTrials) t.print();
		cout << "\n";
	}
};

// int systemThreads;
// int threadsInUse = 1;
// vector<thread> threads;


vector<TimeTrialSet> timeTrialSets;

void runTest(long int vectorSize, int t, int n);
void printVector(vector<long int> v);

void selectionSort(vector<long int> & v);
void insertionSort(vector<long int> & v);
void mergeSort(vector<long int> & v, long int l, long int r);
void quickSort(vector<long int> & v, long int l, long int r);

// void threadBranch(int t){
// 	threadsInUse++;

// 	TimeTrialSet temp = {.sortType = t};
// 		timeTrialSets.push_back(temp);

// 		for(long int i = 100; i < 100001; i*=10){
// 			runTest(i, t, 5);
// 		}

// }

/* Main function */
int main(){

	//Unsuccessful attempt at multithreading
	// cout << "Enter how many threads to run on\n";
	// cin >> systemThreads;

	// //Having trouble calling threads from a loop. Hard-coded it is
	// thread t1(threadBranch, 1);
	// threadsInUse--;
	// if(threadsInUse == systemThreads) t1.join();
	// thread t2(threadBranch, 2);
	// threadsInUse--;
	// if(threadsInUse == systemThreads) t2.join();
	// thread t3(threadBranch, 3);
	// threadsInUse--;
	// if(threadsInUse == systemThreads) t3.join();
	// thread t4(threadBranch, 4);
	// threadsInUse--;
	// if(threadsInUse == systemThreads) t4.join();

	// t1.join();
	// t2.join();
	// t3.join();
	// t4.join();

	//For each of the four sorting algorithms
	for(int j = 1; j <= 4; j++){

		//Init new TimeTrialSet for each algorithm
		TimeTrialSet temp = {.sortType = j};
		timeTrialSets.push_back(temp);

		//Run tests with different collection sizes for each algorithm
		for(long int i = 100; i < 100001; i*=10)
			runTest(i, j, 5);
	}

	cout << "\n\n\n";

	//Print time trial results for all TimeTrialSets
	for(TimeTrialSet t :timeTrialSets)
		t.print();
}

/* Function: selectionSort
 * Usage: selectionSort(<vector>)
 * Parameters: vector to sort
 * ---------------------------------------------------------------------------
 * Sorts a vector of long ints using a selection sort algorithm */
void selectionSort(vector<long int> & v){
	for(long int i = 0; i < v.size() - 1; i++){
		long int lowestIndex = i;

		for(long int j = i + 1; j < v.size(); j++)
			if(v[j] < v[lowestIndex])
				lowestIndex = j;

		iter_swap(v.begin() + i, v.begin() + lowestIndex);
	}
}

/* Function: insertionSort
 * Usage: insertionSort(<vector>)
 * Parameters: vector to sort
 * ---------------------------------------------------------------------------
 * Sorts a vector of long ints using a insertion sort algorithm */
void insertionSort(vector<long int> & v) { 
	for (long int i = 1; i < v.size(); i++){
		long int j = i - 1;
		
		while (j >= 0 && v[j] > v[i]) j = j - 1;
			rotate(v.begin() + j + 1, v.begin() + i, v.begin() + i + 1);
	}
}

/* Function: mergeSort
 * Usage: mergeSort(<vector>, <int>, <int>)
 * Parameters: vector to sort, left slice, right slice
 * ---------------------------------------------------------------------------
 * Sorts a vector of long ints using a merge sort algorithm */
void mergeSort(vector<long int> & v, long int l, long int r) { 
	if(l>=r) return;

	long int m = l+(r-l)/2;

	mergeSort(v, l, m);
	mergeSort(v, m+1, r);

	vector<long int> left;
	vector<long int> right;

	for (long int i = 0; i < m - l + 1; i++)
		left.push_back(v[l + i]);

	for (long int i = 0; i < r - m; i++)
		right.push_back(v[m + 1 + i]);

	long int i = 0;
	long int j = 0;

	long int beforeMergeIndex = l;
	while (i < left.size() && j < right.size()){
		if (left[i] <= right[j]){
			v[beforeMergeIndex] = left[i];
			i++;
		}else{
			v[beforeMergeIndex] = right[j];
			j++;
		}
		beforeMergeIndex++;
	}

	while (i < left.size()){
		v[beforeMergeIndex] = left[i];
		beforeMergeIndex++;
		i++;
	}

	while (j < right.size()){
		v[beforeMergeIndex] = right[j];
		beforeMergeIndex++;
		j++;
	}
}

/* Function: quickSort
 * Usage: quickSort(<vector>, <int>, <int>)
 * Parameters: vector to sort, start boundary, finish boundary
 * ---------------------------------------------------------------------------
 * Sorts a vector of long ints using a quicksort algorithm */
void quickSort(vector<long int> & v, long int s, long int f){
	if(s >= f) return;

	long int p = v[s];
	long int l = s + 1;
	long int r = f;
	while(true){
		while(l < r && v[r] >= p) r--;
		while(l < r && v[l] <  p) l++;

		if(l == r) break;

		iter_swap(v.begin() + l, v.begin() + r);
	}

	long int b;

	if(v[l] < p){
		b = l;
		v[s] = v[l];
		v[l] = p;
	}else b = s;

	quickSort(v, s, b - 1);
	quickSort(v, b + 1, f);
}

/* Function: runTest
 * Usage: runTest(<int>, <int>, <int>)
 * Parameters: length of vector, type of vector to test, number of trials
 * ---------------------------------------------------------------------------
 * Run n time trials for t sorting algorithm on a vector with vectorSize elements */
void runTest(long int vectorSize, int t, int n){
	TimeTrial trial = {.containerSize = vectorSize};

	for(int i = 0; i < n; i++){
		srand(time(NULL));

		//Generate vector
		vector<long int> v;
		for(long int i = 1; i <= vectorSize; i++) v.push_back(i);
		random_shuffle(v.begin(), v.end());

		//Begin timing
		timeval timeBefore, timeAfter;
	  long diffSeconds, diffUSeconds;
		gettimeofday(&timeBefore, NULL);

		//Run sort algorithm of choice
		switch(t){
			case 1:
				selectionSort(v);
				break;
			
			case 2:
				insertionSort(v);
				break;
			
			case 3:
				mergeSort(v, 0, v.size() - 1);
				break;
			
			case 4:
				quickSort(v, 1, v.size() - 1);
				break;
			
		}

		//End timer
		gettimeofday(&timeAfter, NULL);
		diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
		diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
		double time = diffSeconds + diffUSeconds / 1000000.0;

		//Record time
		trial.times.push_back(time);
		cout << "Completed time trial #" << i + 1 << " for " << typeToString[t - 1] << "sort with " << vectorSize << " elements in " << time <<  " seconds\n";
	}

	//Submit TimeTrial to TimeTrialSet for the algorithm of choice
	timeTrialSets[t - 1].timeTrials.push_back(trial);
}

// void printVector(vector<int> v){
// 	for(int i : v) cout << i << ", ";
// 	cout << "\n";
// }