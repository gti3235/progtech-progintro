#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int N, number;
    cin >> N;
    string task;
    deque<int> NumberQueue;
    stack<int> NumberStack;
    for (int i = 0; i < N; ++i)
    {
        cin >> number;
        NumberQueue.push_back(number);
    }

    cin >> task;
    for (char cmd : task)
    {
        // cout << task << cmd << endl;
        switch (cmd)
        {
        case 'P': {
            deque<int>::iterator i;
            for (i = NumberQueue.begin(); i != NumberQueue.end(); ++i)
            {
                std::cout << (i == NumberQueue.begin() ? "" : " ") << *i;
            }
            cout << endl;
            break;
        }
        case 'Q':
            if (!NumberQueue.empty())
            {
                NumberStack.push(NumberQueue.front());
                NumberQueue.pop_front();
            }
            else
            {
                cout << "error" << endl;
                return 0;
            }
            break;
        case 'S':
            if (!NumberStack.empty())
            {
                NumberQueue.push_back(NumberStack.top());
                NumberStack.pop();
            }
            else
            {
                cout << "error" << endl;
                return 0;
            }
            break;
        default:
            break;
        }
    }
}