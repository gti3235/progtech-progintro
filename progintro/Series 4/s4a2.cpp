#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
void reverseChar(char* str);

int main()
{
    char inputChar[30], copyChar[30];
    int numberOfChars, counter1;
    counter1 = 0;
    double counter2 = 0.00;
    bool palin = false;

    cin >> numberOfChars;
    getchar();
    for (int i = 0; i < numberOfChars; i++) {
        cin.getline(inputChar, 30);
        inputChar[strlen(inputChar) - 1];
        if (strlen(inputChar) > 20) cout << "error" << endl;
        else if (strlen(inputChar) == 0) cout << "empty" << endl;
        else if (strlen(inputChar) == 1) {cout << "yes" << endl; counter2++; continue;}
        else {
            for (int i = 0; i < strlen(inputChar); i++) copyChar[i] = inputChar[i];
            reverseChar(inputChar);

            for(size_t i=0; i<strlen(inputChar)/2; i++) {
                if (inputChar[i] == inputChar[strlen(inputChar)-i-1]) counter1++;
            }

            if (counter1 == strlen(inputChar) / 2) palin = true;

            if (palin) {
                cout << "yes" << endl;
                counter2++;
                palin = false;
            } else cout << "no" << endl;
            counter1 = 0;
        }
    }
    double average = double ((counter2 / numberOfChars) * 100);
    std::ios_base::fmtflags oldflags = std::cout.flags();
    std::streamsize oldprecision = std::cout.precision();
    std::cout << std::fixed << std::setprecision(3) << average << '\n';
    std::cout.flags (oldflags);
    std::cout.precision (oldprecision);
}

void reverseChar(char* str) {
    const size_t len = strlen(str);

    for(size_t i=0; i<len/2; i++)
        swap(str[i], str[len-i-1]);
}