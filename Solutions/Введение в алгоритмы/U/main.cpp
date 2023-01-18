/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>

int max_of_three(int a, int b, int c) {
    return std::max(std::max(a, b), std::max(a, c));
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;

    int a[n], b[2][n];
    for (int i = 0; i < n; ++i) {
        int a_i;
        input >> a_i;
        a[i] = a_i;
        b[0][i] = a_i;
        b[1][i] = a_i;
    }

    b[0][0] = std::max(a[0], a[1] + 1);
    for (int i = 1; i < n - 1; ++i) {
        b[i % 2][i] = max_of_three(a[i], a[i-1] + 1, a[i+1] + 1);
    }
    b[(n-1) % 2][n-1] = std::max(a[n-1], a[n-2] + 1);

    int delta[2] = {0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            delta[i] += b[i][j] - a[j];
        }
    }

    int best_way = delta[0] <= delta[1] ? 0 : 1;
    for (int i = 0; i < n; ++i) {
        output << b[best_way][i] << " ";
    }

    return 0;
}
