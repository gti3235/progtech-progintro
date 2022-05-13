#include <iostream>
#include <cmath>

using namespace std;

int DigitSeparationAndCalculation(int x, int y);
void preCalc(int x);
int digits[7];
int roots[100];

int main()
{
    int numberRoot, max_number;
    cin >> numberRoot;
    max_number = DigitSeparationAndCalculation(pow(9, numberRoot), numberRoot);
    int roots[max_number];
    preCalc(numberRoot);
    for (int i = 0; i <= 99999999; i++) {
        DigitSeparationAndCalculation(i, numberRoot);
    }
}

int DigitSeparationAndCalculation(int x, int y) {
    int digit, counter, result;
    digit = 0;
    counter = 0;
    result = 0;
    int a = x;
    while (a>0){
        digit = a % 10;
        digit = roots[digit];
        digits[counter] = digit;
        result += digits[counter];
        a /= 10;
        counter++;
    }
    if (result == x) cout << x << endl;
    int counterCopy = counter;
    counter = 0;
    return counterCopy;
}

void preCalc(int x) {
    for (int i = 0; i <= 9; i++) {
        roots[i] = pow(i, x);
    }
}
