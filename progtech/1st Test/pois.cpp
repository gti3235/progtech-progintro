#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <set>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    set<string> categories;
    map<string, vector<pair<double,double>>> m;
    int n;
    cin >> n;
    double x,y;
    string s;
    for(int i =0; i < n; i++){
        cin >> x >> y;
        cin >> s;
        categories.insert(s);
        m[s].push_back({x,y});
    }
    int k;
    cin >> k;
    double xx, yy;
    for(int i = 0; i < k; i++){ //<set> is ordered I think
        cin >> xx >> yy;
        for(auto categ: categories){
            double ans=1e7+5; //sth too big
            for(auto pairr: m[categ]){
                ans=min(ans, sqrt(pow((pairr.first-xx),2) + pow((pairr.second-yy),2)));
            }
            cout << xx << " " << yy << "\n";
            cout << categ << " " << ans << "\n";
            
            
        }
    }
    return 0;
}