#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    if (n == 1) {
        output << 1;
    }
    else if (n == 2) {
        output << 2;
    }
    else if (n == 3 || n == 4) {
        output << 6;
    }
    else if (n == 5) {
        output << 3;
    }
    else {
        output << 9;
    }
    return 0;
}
