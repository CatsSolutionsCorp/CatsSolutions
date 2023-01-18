/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>
#include <numeric>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    // так сказал Гренкин.
    // это правда, я проверил.
    int d1, m1, d2, m2;
    input >> d1 >> m1 >> d2 >> m2;
    int diff1 = abs(d1 - d2);
    int diff2 = abs(m1 - m2);
    int m = std::gcd(diff1, diff2);

    output << std::max(diff1, diff2) / m;

    return 0;
}