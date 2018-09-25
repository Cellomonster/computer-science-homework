/*
File: project1.cc
-----------------
Calculates how many of two lights will be enabled when a mailman arrives.
Individual light timers and mailman arrival time are determined by user input

Authors: Huiyu Yi, Julian Triveri
9/24/18
*/

#include <iostream>
using namespace std;

/* Main Program*/

int main(){
  //Light 1 time variables
  int t1_on;
  int t1_off;

  //Light 2 time variables
  int t2_on;
  int t2_off;

  //Mailman visit time variable
  int t_mailman;

  //Gather input from user
  cout << "How many minutes should light 1 be on?" << endl;
  cin >> t1_on;
  cout << "...and what about off?" << endl;
  cin >> t1_off;
  cout << "How long should light 2 stay on?" << endl;
  cin >> t2_on;
  cout << "...and off?" << endl;
  cin >> t2_off;
  cout << "When should the mailman visit?" << endl;
  cin >> t_mailman;

  //Find time remaining based on remainder of cycle
  int t1_remain = (t_mailman % (t1_on + t1_off));
  int t2_remain = (t_mailman % (t2_on + t2_off));

  //Output 'both', 'one', or 'none' of the lights
  //are on at the time of the mailman's arrival
  string output = //output string will be printed to console
    (t1_remain < t1_on || t2_remain < t2_on) ? //if either light is on...
      ((t1_remain < t1_on && t2_remain < t2_on) ? "BOTH" : "ONE") //determine if just 1 or both...
      : "NONE"; //else none

  //Output result
  cout << output << endl;

  return 0;
}
