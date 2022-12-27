#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    for (int i = 0; i < (int)pow(2, n); ++i) {
        output << std::bitset<15>(i).to_string().substr(15-n, n) << '\n';
    }
    return 0;
}