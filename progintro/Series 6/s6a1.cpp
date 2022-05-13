#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void quicksort(int a[], int first, int last);
int partition(int a[], int first, int last);
int exceptZeros(int a[], int limit);

int main()
{
    int N, min = 0, max = 0;
    cin >> N;
    int numberArray1[N], numberArray2[N];
    bool match = true, forMin = true, forMax = true;

    for (int i = 0; i < N; i++)
    { // initialize the numbers of array1
        cin >> numberArray1[i];
    }

    for (int i = 0; i < N; i++)
    { // initialize the numbers of array2
        cin >> numberArray2[i];
    }

    int n = sizeof(numberArray1) / sizeof(numberArray1[0]);
    quicksort(numberArray1, 0, n-1);
    quicksort(numberArray2, 0, n-1);

    for (int i = 0; i < N; i++) // check the no-equal matrix digits
    {
        if ((numberArray1[i] != numberArray2[i]) && forMin)
        {
            min = std::min(numberArray1[i], numberArray2[i]);
            match = false;
            forMin = false;
        }
        if ((numberArray1[N-i-1] != numberArray2[N-i-1]) && forMax)
        {
            max = std::max(numberArray1[N-i-1], numberArray2[N-i-1]);
            forMax = false;
        }
    }

    if (match)
        cout << "yes" << endl;
    else
    {
        cout << "no" << " " << min << " " << max << endl;
    }
}

void quicksort(int a[], int first, int last)
{
    int i;
    if (first >= last)
        return;
    i = partition(a, first, last);
    quicksort(a, first, i);
    quicksort(a, i + 1, last);
}

int partition(int a[], int first, int last)
{
    int x = a[(first + last) / 2];
    int i = first, j = last;
    while (true)
    {
        while (a[i] < x)
            i++;
        while (x < a[j])
            j--;
        if (i >= j)
            break;
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return j;
}