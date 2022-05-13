#include <iostream>

using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i]; 
    }
    int paronomastis = a[1] * a[3];
    int arithmitis = (a[0] * a[3]) + (a[2] * a[1]);
    cout << arithmitis << " " << paronomastis << endl;
}