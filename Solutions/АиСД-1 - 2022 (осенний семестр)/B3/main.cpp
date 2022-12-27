#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream input("input.txt");

    int n;
    input >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        input >> a;
        sum += a;
    }

    std::ofstream output("output.txt");
    output << sum << std::endl;
}