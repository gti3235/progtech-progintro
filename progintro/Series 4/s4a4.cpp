#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    double matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int p = 0; p < M; p++) cin >> matrix[i][p];
    }
    if ((N >= 1 && N <= 100) && (M >= 1 && M <= 100)) {
        double c, b;
        b = 0;
        for (int m = 0; m < N; m++){
            for (int n = 0; n < M; n++) b = matrix[m][n] + b;
        }
        c = b / (N * M);
        std::ios_base::fmtflags oldflags = std::cout.flags();
        std::streamsize oldprecision = std::cout.precision();
        std::cout << std::fixed << std::setprecision(3) << c << '\n';
        std::cout << std::fixed << std::setprecision(3) << c << '\n';
        std::cout.flags (oldflags);
        std::cout.precision (oldprecision);
    }
}
