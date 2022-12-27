#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;

    int max_number = 1 << n;
    for (int i = 0; i < max_number; ++i) {
        for (int j = n; j > 0; --j) {
            int mask = 1 << (j - 1);
            char bit = (i & mask) == 0 ? '0' : '1';
            output << bit;
        }
        output << '\n';
    }

    return 0;
}
