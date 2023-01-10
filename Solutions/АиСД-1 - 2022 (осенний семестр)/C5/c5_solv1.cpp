/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/
#include <fstream>
#include <cmath>

struct Digit {
    int k;
    std::string way;
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, k;

    input >> n >> k;

    auto *a = new Digit[n + 1];
    a[0] = {0, ""};

    for (int i = 1; i <= n; i++) {
        std::string this_way;
        int this_k = 0;
        for (int j = int(std::sqrt(i)); j > 0; j--) {
            if (this_k == 0 || a[i - j * j].k + 1 < this_k) {
                this_k = a[i - j * j].k + 1;
                this_way = a[i - j * j].way + std::to_string(j) + " ";
            }
        }

        a[i] = {this_k, this_way};
    }

    if (a[n].k <= k)
        output << "YES" << std::endl << a[n].way;
    else
        output << "NO";
}
