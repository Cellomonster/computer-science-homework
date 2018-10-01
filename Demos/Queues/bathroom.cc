#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int main(){
    srand(7);
    queue<int> bathroomLine;
    int numStalls = 7;
    int stalls[numStalls];
    int simulate = 10;

    for(int i = 0; i < numStalls; i++){
        stalls[i] = 0;
    }

    for(int i = 0; i < simulate; i++){
        int peopleToAdd = rand() % 7;
        for(int j = 0; j < peopleToAdd; j++){
           bathroomLine.push( rand() % 10 + 1);
        }

        for(int j = 0; j < numStalls; j++){
            if(stalls[j] > 0){
                stalls[j]--;
            }

            if(stalls[j] <= 0 && !bathroomLine.empty()) {
                stalls[j] = bathroomLine.front();
                bathroomLine.pop();
            }
        }

        cout << "Current State of the Stalls" << endl;
        for(int j = 0; j < numStalls; j++){
           cout << stalls[j] << " ";
        }
        cout << endl;

        if(!bathroomLine.empty()){
            cout << "Number in the queue: " << bathroomLine.size() << endl;
            cout << "Front of the line: " << bathroomLine.front() << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }

    return 0;
}
