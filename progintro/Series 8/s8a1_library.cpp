#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q);
int queueSignChecker(queue<int> q);
int queueSequenceChecker(queue<int> q);
void queueClean(queue<int> q);

int main()
{
    int n, c;
    queue<int> numberQueue;
    do
    {
        scanf("%d", &n);
        numberQueue.push(n);
        c = getchar();
    } while (c != '\n');
    if (queueSignChecker(numberQueue) && queueSequenceChecker(numberQueue))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int queueSignChecker(queue<int> q)
{
    int posInt = 0, negInt = 0;
    while (!q.empty())
    {
        if (q.front() > 0)
            posInt++;
        else
            negInt++;
        q.pop();
    }
    if (posInt == negInt)
        return 1;
    return 0;
}

int queueSequenceChecker(queue<int> q)
{
    queue<int> NegQueue, PosQueue;
    queueClean(PosQueue); queueClean(NegQueue);
    int counterEqual = 0;
    int size = q.size();
    if (size % 2 == 0)
    {
        while (!q.empty())
        {
            if (q.front() > 0)
                PosQueue.push(q.front());
            else if (q.front() < 0)
                NegQueue.push(abs(q.front()));
            q.pop();
        }
        int sizePos = PosQueue.size();
        for (int i = 0; i < sizePos; i++)
        {
            if (PosQueue.front() == NegQueue.front()) counterEqual++;
            PosQueue.pop(); 
            NegQueue.pop();
        }
        if (counterEqual == size/2)
            return 1;
    }
    return 0;
}

void queueClean(queue<int> q) {
    while (!q.empty()) {
        q.pop();
    }
}