/*
File: project5.cc
-----------------
Find all the words in a boggle board

Authors: Julian Triveri
10/15/18
*/

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> wordsFound;

//Dictionary
deque<string> words;

//Boggle dice values based on
//https://boardgames.stackexchange.com/questions/29264/boggle-what-is-the-dice-configuration-for-boggle-in-various-languages
string dice[25] =
{	"qbzjxk", "touoto", "ovwrgr", "aaafsr", "aumeeg",
"hhlrdo", "nhdtho", "lhnrod", "afaisr", "yifasr",
"telpci", "ssnseu", "riyprh", "dordln", "ccwnst",
"ttotem", "sctiep", "eandnn", "mnneag", "uotown",
"aeaeee", "yifpsr", "eeeema", "ititie", "etilic" };

//Represents a value in the boggle board matrix;
struct pos{
	int x;
	int y;
};

char boggle[5][5];

long unsigned int dictionaryIndexes[27];

void generateBoggle();
bool readDictionary();
void findWord(pos position, vector<pos> visited, string found, string target);

/* Main function */
int main(void){

	readDictionary();

	generateBoggle();

	cout << endl << endl;
	cout << "|BOARD|" << endl;
	for(int y = 0; y < 5; y++){
		for(int x = 0; x < 5; x++)
			cout << boggle[y][x];
		cout << endl;
	}
	cout << endl;

	cout << "|FOUND WORDS|" << endl;
	vector<pos> v;
	for(int y = 0; y < 5; y++)
		for(int x = 0; x < 5; x++)
			//Only loop through words which start with the letter on the die at [y][x]
			for(int i = dictionaryIndexes[boggle[y][x] - 97]; i < dictionaryIndexes[boggle[y][x] - 96]; i++)
				findWord(pos{x,y}, v, "", words[i]);

			//Slower version, checking entire dictionary
			/*for(string word : words)
				findWord(pos{x,y}, v, "", word);*/

	cout << endl << endl;

	return 0;
}

/* Function: generateBoggle
 * Usage: generateBoggle()
 * ---------------------------------------------------------------------------
 * Generates the randomized boggle board */
void generateBoggle(){
	srand(time(NULL));
	random_shuffle(&dice[0], &dice[25]);
	for(int i = 0; i < 25; i++)
		boggle[i%5][i/5] = dice[i].at(random()%6);
}

/* Function: readDictionary
 * Usage: readDictionary()
 * Returns: wether or not the dictionary of words was succesfully read
 * ---------------------------------------------------------------------------
 * Reads content of words.txt and stores each line as a value in the words deque
 */
bool readDictionary() {
	ifstream filestr;
	filestr.open("words.txt");
	if (!filestr.is_open()){
		perror ("Error opening file.");
		return false;
	} else {
		while (filestr) {
			string s;
			getline(filestr,s);
			words.push_back(s);
		}

		//Apparently, words.txt was not correctly sorted in alphabetical order
		//must be sorted here
		sort(words.begin(), words.end());
	}

	dictionaryIndexes[26] = words.size();

	//Store index of the first word with a specific first letter
	//this slightly accelerates the search process by having the program
	//ignore large parts of the dictionary deque containing words
	//which obviously have no chance of being correct
	//to see how much of a difference this creates, you can uncomment the
	//old loop at line 71-72

	//First character represents both an index, and a character minus 97
	int firstCharacterToFind = 0;
	for(long unsigned int i = 0; i < words.size() && firstCharacterToFind < 26; i++)
		if(words[i].find(char(firstCharacterToFind + 97)) == 0){
			dictionaryIndexes[firstCharacterToFind] = i;
			firstCharacterToFind ++;
		}

	return true;
}

/* Function: findWord
 * Usage: findWord(<pos>, <vector<pos>>, <string>, <string>)
 * Parameters: position on the board to check, positions already checked, current string formed, target word to find
 * ---------------------------------------------------------------------------
 * Recursively searches for a given word on the board. If it is found on the
 * board, the word is added to the wordsFound vector
 */
void findWord(pos position, vector<pos> visited, string found, string target){
	//Mark this position as already used
	visited.push_back(position);

	//Add this die character to the found string
	found += boggle[position.y][position.x];

	//If the word found is equal to or longer than 3 characters, is equal to the target word,
	//and was not found before, add it to the vector of found words
	if(found.length() >= 3 && target == found && find(wordsFound.begin(), wordsFound.end(), found) == wordsFound.end()){
		wordsFound.push_back(found);
		cout << found << endl;
		return;
	}

	//Check if the found string could potentially be the target string
	if(target.find(found) == 0){
		//Check surrounding die
		for(int y = position.y - 1; y < position.y + 2; y++){
			for(int x = position.x - 1; x < position.x + 2; x++){
				if(x >= 0 && y >= 0 && x < 5 && y < 5){
					//Check if potential 'branch' die has already been used
					bool isntVisited = true;
					for(pos visitedPosition : visited)
						if(x == visitedPosition.x && y == visitedPosition.y)
							isntVisited = false;
					if(isntVisited)
						//If the die has not been used, check it
						findWord(pos{x,y}, visited, found, target);
				}else return;
			}
		}
	}else return;
}
