#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> matrix[i][j];
    }
    int sumDiag1, sumDiag2, sumRow[N], sumCol[N], sumAll, counter;
    bool Diag = false; bool ColRow = false; bool req = false;
    sumDiag1 = 0; sumDiag2 = 0; sumAll = 0; counter = 0;
    for (int i = 0; i < N; i++) {
        sumRow[i] = 0;
        sumCol[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        sumDiag1 += matrix[i][i];
        sumDiag2 += matrix[i][N-i-1];
        for (int j = 0; j < N; j++) {
            sumRow[i] += matrix[i][j]; //Calculate the sum of each row
            sumCol[i] += matrix[j][i]; //Calculate the sum of each column
            sumAll += matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        if ((sumCol[i] == sumCol[N-i-1]) && (sumRow[i] == sumRow[N-i-1])) counter++;
    }
    if (counter == N) ColRow = true;
    if (sumDiag1 == sumDiag2) Diag = true;
    int digits = (N*N)-1;
    int sumSum = 0;
    for (int i = 0; i <= digits; i++) sumSum += i;
    if ((ColRow == true) && (Diag == true) && (sumAll == sumSum)) req = true;
    if (req) cout << "yes" << endl;
    else cout << "no" << endl;
}
