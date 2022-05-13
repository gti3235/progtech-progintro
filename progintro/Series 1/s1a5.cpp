#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N > 0)
    {
        for (int i = 1; i <= N; i++)
            cout << "hello world" << endl;
    } else cout << "nothing today" << endl;
}