#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

bool balanced(string input);

int main(){
  string input;
  cin >> input;


  if(balanced(input))
      cout << "Balanced" << endl;
  else
      cout << "Not Balanced" << endl;

  return 0;
}

bool balanced(string input){
    stack<char> openings;

    map<char, char> parens;
    parens['('] = ')';
    parens['{'] = '}';
    parens['['] = ']';


    for(int i = 0; i < input.size(); i++){
        if(input[i] == '[' || input[i] == '{' || input[i] == '('){
          openings.push(input[i]);
        } else {
          if(openings.empty()) return false;
          char currentChar = openings.top();
          switch(currentChar){
            case '[':
                if(input[i] == ']')
                    openings.pop();
                else
                    return false;
                break;
            case '{':
                if(input[i] == '}')
                    openings.pop();
                else
                    return false;
                break;
            case '(':
                if(input[i] == ')')
                    openings.pop();
                else
                    return false;
                break;
          }
        }
    }
    if(!openings.empty()) return false;
    return true;
}
