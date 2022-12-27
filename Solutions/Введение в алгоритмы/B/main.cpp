#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n;
    int a_accumulate[n];

    input >> a_accumulate[0];
    for (int i = 1; i < n; ++i) {
        short a_i;
        input >> a_i;
        a_accumulate[i] = a_accumulate[i - 1] + a_i;
    }
    input >> m;
    for (int j = 0; j < m; ++j) {
        int l_j, r_j;
        input >> l_j >> r_j;
        int a_accumulate_left = l_j == 1 ? 0 : a_accumulate[l_j - 2];
        int a_accumulate_right = a_accumulate[r_j - 1];
        int result = a_accumulate_right - a_accumulate_left;
        output << result << ' ';
    }

    return 0;
}