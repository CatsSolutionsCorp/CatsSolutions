#include <fstream>
#include <iostream>


int main() {
    std::ifstream input("input.txt");

    int n;
    input >> n;

    int max;
    input >> max;
    for (int i = 1; i < n; ++i) {
        int number;
        input >> number;
        max = std::max(max, number);
    }

    std::ofstream output("output.txt");
    output << max;
}