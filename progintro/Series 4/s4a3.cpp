#include <iostream>

using namespace std;

int main()
{
    int N, M, arrayInput; //N for rows M for columns
    cin >> N >> M;
    int matrix[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int MaxColumn[M], MinRow[N], maximum, minimum;
    for (int i = 0; i < M; i++)   // Maximum of each column
    {
        maximum = matrix[0][i];
        for (int j = 0; j < N; j++)
        {
            if (maximum < matrix[j][i])
            {
                maximum = matrix[j][i];
            }
            MaxColumn[i] = maximum;
        }
    }
    for (int i = 0; i < N; i++)   // Minimum of each row
    {
        minimum = matrix[i][0];
        for (int j = 0; j < M; j++)
        {
            if (minimum > matrix[i][j])
            {
                minimum = matrix[i][j];
            }
            MinRow[i] = minimum;
        }
    }
    //for (int i = 0; i < M; i++) cout << "Max : " << MaxColumn[i] << endl;
    //for (int i = 0; i < N; i++) cout << "Min : " << MinRow[i] << endl;
    maximum = 0;
    minimum = 0;
    minimum = MaxColumn[0];
    for (int i = 0; i < M; i++)   // Minimum of maximum of each column
    {
        if (minimum > MaxColumn[i]) minimum = MaxColumn[i];
    }
    maximum = MinRow[0];
    for (int i = 0; i < N; i++)   // Maximum of minimum of each row
    {
        if (maximum < MinRow[i]) maximum = MinRow[i];
    }
    cout << minimum << endl;
    cout << maximum << endl;
}
