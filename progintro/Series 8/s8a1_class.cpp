#include <iostream>

using namespace std;

class queueTest
{
public:
    queueTest();
    bool empty();
    void push(int x);
    void pop();
    int peek();

private:
    struct node
    {
        int info;
        node *next;
    };
    node *front, *rear;
};

bool queueTest::empty()
{
    return front == nullptr;
}

queueTest::queueTest()
{
    front = rear = nullptr;
}

void queueTest::push(int x)
{
    node *p = new node;
    p->info = x;
    p->next = nullptr;
    if (front == nullptr)
        front = p;
    else
        rear->next = p;
    rear = p;
}

void queueTest::pop()
{
    node *p = front;
    int result = front->info;
    if (front == rear)
        rear = nullptr;
    front = front->next;
    delete p;
}

int queueTest::peek()
{
    if (front != nullptr)
        return front->info;
    return 0;
}

int main()
{
    queueTest numberQueue;
    int numberInput, charInput;
    bool check2 = false, check1 = false;
    do
    {
        scanf("%d", &numberInput);
        numberQueue.push(numberInput);
        charInput = getchar();
    } while (charInput != '\n');
    queueTest NegQueue, PosQueue;
    int counterEqual = 0, counterPos = 0, counterNeg = 0;
    while (!numberQueue.empty())
    {
        if (numberQueue.peek() > 0)
        {
            PosQueue.push(numberQueue.peek());
            counterPos++;
        }
        else if (numberQueue.peek() < 0) {
            NegQueue.push(abs(numberQueue.peek()));
            counterNeg++;
        }
        numberQueue.pop();
    }
    for (int i = 0; i < counterPos; i++)
    {
        if (PosQueue.peek() == NegQueue.peek())
            counterEqual++;
        if (!PosQueue.empty() && !NegQueue.empty())
        {
            PosQueue.pop();
            NegQueue.pop();
        }
    }
    if (counterNeg == counterPos)
        check1= true;
    if (counterEqual == counterPos)
        check2 = true;
    // if (check1 && check2)
    //     cout << "yes" << endl;
    // else
    //     cout << "no" << endl;
    (check1 && check2) ? cout << "yes" : cout << "no";
}
