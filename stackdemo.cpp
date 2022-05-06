#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
    stack(int size)
    {
        sizeOfArray = size;
        matrix = new T[sizeOfArray];
        top = 0;
    }

    stack(const stack &s)
    {
        matrix = new T[s.sizeOfArray];
        top = s.top;
        sizeOfArray = s.sizeOfArray;
        for (int i = 0; i < top; ++i)
        {
            matrix[i] = s.matrix[i];
        }
    }

    ~stack()
    {
        delete[] matrix;
    }

    const stack &operator=(const stack &s)
    {
        delete[] matrix;
        sizeOfArray = s.sizeOfArray;
        top = s.top;
        matrix = new T[s.sizeOfArray];
        for (int i = 0; i < top; ++i)
            matrix[i] = s.matrix[i];
        return *this;
    }

    bool empty()
    {
        return top == 0;
    }

    void push(const T &x)
    {
        matrix[top++] = x;
    }

    T pop()
    {
        return matrix[--top];
    }

    int size()
    {
        return top;
    }

    friend ostream &operator<<(ostream &out, const stack &s)
    {
        T *ptr = s.matrix;
        if (s.top == 0)
            out << "[]";
        else
        {
            out << "[" << *ptr;
            ptr++;
            for (int i = 1; i < s.top; i++)
            {
                out << ", " << *ptr;
                ptr++;
            }
            out << "]";
        }
        return out;
    }

private:
    int sizeOfArray;
    T *matrix;
    int top;
};