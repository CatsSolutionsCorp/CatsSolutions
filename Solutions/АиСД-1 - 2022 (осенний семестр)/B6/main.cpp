#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int x, k;
    input >> x >> k;

    int bit = 0;
    if (k < 32) {
        bit = (x >> k) % 2;
    }
    output << bit;
    return 0;
}
