#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    int max_subsequence_count = 1;
    int max_subsequence[n];
    max_subsequence[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = a[j] - a[i];
            int subsequence[n];
            subsequence[0] = i;
            subsequence[1] = j;
            int subsequence_count = 2;
            for (int k = j + 1; k < n; ++k)
                if (a[k] - a[subsequence[subsequence_count - 1]] == d) {
                    subsequence_count++;
                    subsequence[subsequence_count - 1] = k;
            }
            if (subsequence_count > max_subsequence_count) {
                max_subsequence_count = subsequence_count;
                std::copy(subsequence, subsequence + subsequence_count, max_subsequence);
            }
        }
    }

    output << max_subsequence_count << '\n';
    for (int i = 0; i < max_subsequence_count; ++i) {
        output << max_subsequence[i] + 1 << ' ';
    }

    return 0;
}
