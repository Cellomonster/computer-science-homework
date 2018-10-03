/* Purpose: To practice using sets with large corpora.
 * Author: Jaimie Kelley
 * Date: 10/3/2018
 * Sources Used:
 *     Programming Abstractions in C++ by Eric S. Roberts for the code template
 *     http://www.cplusplus.com/reference/set/set/ for the STL set entry
 *     https://github.com/dwyl/english-words/blob/master/words.txt
 */

#include <set>
#include <iostream>
#include <fstream>
using namespace std;

int main(void ){
        set<string> lexicon;
        ifstream infile;
        infile.open("words.txt");
        if(infile.fail()) cout << "Can't open words.txt" << endl;
        string word;
        while(getline(infile, word)) {
                lexicon.insert(word);
        }
        infile.close();

        if(!lexicon.empty()) {
                cout << "Size: " << lexicon.size() << endl;
                cout << "Count of words containing 'aardvark'" << lexicon.count("aardvark") << endl;
        }

        lexicon.insert("aardvark");
        cout << "Count of words containing 'aardvark'" << lexicon.count("aardvark") << endl;
        return 0;
}
