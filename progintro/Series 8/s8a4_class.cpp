#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool flag = false;
int levelEnd = 0;

class treeTest
{
public:
    treeTest();
    int height();
    int size();
    void insert(int x);
    int search(int x);
    int min();
    int max();
    void inorder();
    void preorder();
    void postorder();

private:
    struct node
    {
        int info;
        node *left, *right;
    };
    node *root;

public:
    void inorder_aux(node *t)
    {
        if (t != nullptr)
        {
            inorder_aux(t->left);
            printf("%d ", (t->info));
            inorder_aux(t->right);
        }
    }

    void postorder_aux(node *t)
    {
        if (t != nullptr)
        {
            postorder_aux(t->left);
            postorder_aux(t->right);
            printf("%d ", (t->info));
        }
    }

    void preorder_aux(node *t)
    {
        if (t != nullptr)
        {
            printf("%d ", (t->info));
            preorder_aux(t->left);
            preorder_aux(t->right);
        }
    }

    int height_aux(node *t)
    {
        if (t == nullptr)
            return 0;
        return (1 + std::max(height_aux(t->left), height_aux(t->right)));
    }

    int size_aux(node *t)
    {
        if (t == nullptr)
            return 0;
        return (1 + size_aux(t->left) + size_aux(t->right));
    }

    node *insert_aux(node *t, int key)
    {
        if (t == nullptr)
        {
            node *p = new node;
            p->info = key;
            p->left = p->right = nullptr;
            return p;
        }
        if (t->info > key)
            t->left = insert_aux(t->left, key);
        else if (t->info < key)
            t->right = insert_aux(t->right, key);
        return t;
    }

    // int search_aux(node *t, int x)
    // {
    //     if (t == nullptr)
    //         return 0;
    //     if (t->info == x)
    //         return level;
    //     if (t->info > x)
    //         search_aux(t->right, x);
    //     else
    //         search_aux(t->left, x);
    //     level++;
    //     return 0;
    // }

    int search_aux(node *node, int data, int level)
    {
        if (node == NULL)
            return 0;

        if (node->info == data)
        {
            flag = true;
            levelEnd = level;
            return level;
        }

        if (data < node->info && !flag)
            return search_aux(node->left, data, level + 1);
        else if (data > node->info && !flag)
            return search_aux(node->right, data, level + 1);
        // int downlevel = search_aux(node->left, data, level + 1);
        // if (downlevel != 0)
        //     return downlevel;
        // downlevel = search_aux(node->right, data, level + 1);
        // return downlevel;
        return level;
    }
};

treeTest::treeTest()
{
    root = nullptr;
}

int treeTest::height()
{
    return height_aux(root);
}

int treeTest::size()
{
    return size_aux(root);
}

void treeTest::insert(int x)
{
    root = insert_aux(root, x);
}

int treeTest::search(int data)
{
    return search_aux(root, data, 1);
}

int treeTest::min()
{
    node *t = root;
    if (t == nullptr)
        return 0;
    while (t->left != nullptr)
    {
        t = t->left;
    }
    return t->info;
}

int treeTest::max()
{
    node *t = root;
    if (t == nullptr)
        return 0;
    while (t->right != nullptr)
    {
        t = t->right;
    }
    return t->info;
}

void treeTest::preorder()
{
    preorder_aux(root);
}

void treeTest::postorder()
{
    postorder_aux(root);
}

void treeTest::inorder()
{
    inorder_aux(root);
}

int main()
{
    treeTest numberTree;
    int N, M;
    scanf("%d", &N);
    int numberSequenceInsert[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numberSequenceInsert[i]);
    }
    scanf("%d", &M);
    int numberSequenceSearch[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &numberSequenceSearch[i]);
    }
    for (int i = 0; i < N; i++)
        numberTree.insert(numberSequenceInsert[i]);

    printf("%d\n", numberTree.height());

    printf("%d %d\n", numberTree.min(), numberTree.max());

    numberTree.search(numberSequenceSearch[0]);
    printf("%d", levelEnd);
    flag = false;
    levelEnd = 0;

    for (int i = 1; i < M; i++)
    {
        numberTree.search(numberSequenceSearch[i]);
        printf(" %d", levelEnd);
        flag = false;
        levelEnd = 0;
    }
    
    printf("\n");
    numberTree.inorder();
    printf("end\n");
    numberTree.preorder();
    printf("end\n");
    numberTree.postorder();
    printf("end\n");
    return 0;
}
