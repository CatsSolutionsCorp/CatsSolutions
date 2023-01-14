/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, r;

    input >> n >> r;

    auto *a = new long long[n];

    int change = 0;
    int this_n, this_r;
    do {
        this_n = n - change;
        this_r = r - change / 2;
        if (this_r == 1) {
            for (int i = 0; i < this_n; i++)
                a[i + change / 2] = this_n * this_n - i;
        } else if (this_r == this_n) {
            for (int i = 0; i < this_n; i++)
                a[i + change / 2] = this_n * this_n - 3 * this_n + 3 + i;
        } else {
            a[change / 2] = this_n * this_n - 4 * this_n + this_r + 3;
            a[n - 1 - change / 2] = this_n * this_n - this_n + 2 - this_r;
        }
        change += 2;
    } while (this_n > 1 && this_r > 1 && this_n != this_r);

    for (int i = 0; i < n; i++) {
        output << a[i] << ' ';
    }

    return 0;
}
