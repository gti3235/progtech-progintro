#include <iostream>

using namespace std;

class listTest
{
public:
    listTest();
    bool empty();
    int size();
    void add(int k, int x);
    int get(int k);
    void remove(int k);
    int searchMF(int x);

private:
    struct node
    {
        int info;
        node *next;
    };
    node *head;
};

listTest::listTest()
{
    head = nullptr;
}

bool listTest::empty()
{
    return head == nullptr;
}

int listTest::size()
{
    int size = 0;
    node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
        size++;
    }
    return size;
}

int listTest::get(int k)
{
    node *p = head;
    for (int i = 1; i < k; i++)
    {
        p = p->next;
    }
    return p->info;
}

void listTest::remove(int k)
{
    if (k == 1)
    {
        head = head->next;
    }
    else
    {
        node *p = head;
        for (int i = 1; i < k - 1; i++)
        {
            p = p->next;
        }
        node *q = p->next;
        p->next = q->next;
        delete q;
    }
}

void listTest::add(int k, int x)
{
    if (k == 1)
    {
        node *p = new node;
        p->info = x;
        p->next = head;
        head = p;
    }
    else
    {
        node *p = head;
        for (int i = 1; i < k - 1; i++)
        {
            p = p->next;
        }
        node *q = new node;
        q->info = x;
        q->next = p->next;
        p->next = q;
    }
}

int listTest::searchMF(int x)
{
    node *p = head;
    int counter = 1;
    bool find = false;
    for (p = head; p != nullptr; p = p->next)
    {
        if (p->info == x)
        {
            find = true;
            break;
        } else counter++;
    }
    if (find)
    {
        add(1, x);
        remove(counter + 1);
        return counter;
    }
    return 0;
}

int main()
{
    listTest numberList;
    int N, M, X, K, Xsearch, sum = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &K, &X);
        numberList.add(K, X);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &Xsearch);
        sum += numberList.searchMF(Xsearch);
    }

    printf("%d\n", sum);
    return 0;
}