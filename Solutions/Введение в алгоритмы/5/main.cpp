#include <fstream>
#include <math.h>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    double R, r;
    input >> R >> r;
    double pi = std::acos(-1);

    output << pi * r * R;
    return 0;
}
