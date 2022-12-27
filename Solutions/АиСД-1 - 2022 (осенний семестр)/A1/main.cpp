#include <fstream>
#include <numeric>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int a, b, c, d;
    input >> a >> b;

    int gcd = std::gcd(a, b);
    a /= gcd;
    b /= gcd;

    int b2 = 0;
    int b5 = 0;
    while (b % 2 == 0) {
        b /= 2;
        b2++;
    }
    while(b % 5 == 0) {
        b /= 5;
        b5++;
    }

    c = b;
    d = std::max(b2, b5);
    output << c << ' ' << d;

    return 0;
}
