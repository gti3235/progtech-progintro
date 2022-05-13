#include <iostream>
#include <map>
#include <string>
#include <set>
#include <list>

using namespace std;

int main() {
    string text;
    map<char, int> letterCounter;
    map<char, set<string>> words;
    map<char, string> longest, shortest;
    while(cin >> text) {
        char firstL = text[0];
        words[firstL].insert(text); 
        letterCounter[firstL]++;
        if (letterCounter[firstL] == 1 || text.size() > longest[firstL].size() || (text.size() == longest[firstL].size() && text < longest[firstL]))
            longest[firstL] = text;
        if (letterCounter[firstL] == 1 || text.size() < shortest[firstL].size() || (text.size() == shortest[firstL].size() && text < shortest[firstL]))
            shortest[firstL] = text;
    }
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        if (words[letter].size() > 0) 
            cout << letter << ": " << letterCounter[letter] << " word(s), " << words[letter].size() << " unique word(s), longest '" << longest[letter] << "' and shortest '" << shortest[letter] << "'" << endl;
    }
}