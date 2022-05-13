#include <iostream>

using namespace std;

int gcd(int number1, int number2);

int main()
{
    int N, gcd1 = 1;
    bool error = false, neg = false;
    cin >> N;
    int a[N][4], b[N][2];
    char symbol[N];
    for (int i = 0; i < N; i++)
    {
        cin >> symbol[i];
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!(a[i][1] == 0 || a[i][3] == 0))
        {
            if (!(symbol[i] == '/' && a[i][2] == 0))
            {
                error = false;
                switch (symbol[i])
                {
                case '+':
                    b[i][0] = (a[i][0] * a[i][3]) + (a[i][2] * a[i][1]);
                    b[i][1] = a[i][1] * a[i][3];
                    break;
                case '-':
                    b[i][0] = (a[i][0] * a[i][3]) - (a[i][2] * a[i][1]);
                    b[i][1] = a[i][1] * a[i][3];
                    break;
                case '/':
                    b[i][0] = a[i][0] * a[i][3];
                    b[i][1] = a[i][2] * a[i][1];
                    break;
                case '*':
                    b[i][0] = a[i][0] * a[i][2];
                    b[i][1] = a[i][1] * a[i][3];
                    break;
                }
            } else error = true;
        } else error = true;

        if (!error)
        {
            gcd1 = gcd(b[i][0], b[i][1]);
            b[i][0] /= gcd1;
            b[i][1] /= gcd1;
            if ((b[i][0] / b[i][1]) == 0)
            {
                if ((b[i][0] < 0 && b[i][1] < 0) || (b[i][0] > 0 && b[i][1] > 0))
                    neg = false;
                if ((b[i][0] < 0 && b[i][1] > 0) || (b[i][0] > 0 && b[i][1] < 0))
                    neg = true;
            }
            if (!neg)
                printf("%d %d %d\n", b[i][0] / b[i][1], abs(b[i][0] - (b[i][0] / b[i][1] * b[i][1])), abs(b[i][1]));
            else
                printf("-%d %d %d\n", b[i][0] / b[i][1], abs(b[i][0] - (b[i][0] / b[i][1] * b[i][1])), abs(b[i][1]));
            neg = false;
        } else printf("error\n");
    }
}

int gcd(int number1, int number2)
{
    number1 = abs(number1);
    number2 = abs(number2);
    while (number1 > 0 && number2 > 0)
        if (number1 > number2)
            number1 %= number2;
        else
            number2 %= number1;
    return (number1 + number2);
}