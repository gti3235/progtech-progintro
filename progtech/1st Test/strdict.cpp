#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int N, D, d;
    string w;
    cin >> N >> D;
    map<int, set<string>> dict;
    map<string, set<int>> word;
    for (int i = 0; i < N; ++i) {
        cin >> d >> w;
        dict[d].insert(w); 
        word[w].insert(d);
    }

    int max = 1;
    for (int i = 2; i < D; ++i) {
        if (dict[i].size() > dict[max].size())
            max = i;
    }
    cout << "largest dictionary is " << max << " with " << dict[max].size() << " word(s)" << endl;

    int counter = 0;
    for (auto i : word) {
        if (i.second.size() == D) { 
            cout << i.first << endl;
            counter++;
        }
    }

    cout << counter << " word(s) appear in all dictionaries" << endl;
    system(0);
}