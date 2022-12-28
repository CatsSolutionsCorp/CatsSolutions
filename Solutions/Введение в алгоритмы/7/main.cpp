#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int a, b;
    input >> a >> b;
    bool is_pages_count_even = (b - a + 1) % 2 == 0;

    if (a == b) {
        if (a % 2 == 0) {
            output << "2 -1 100";
        }
        else {
            output << "1 -1 100";
        }
    }
    else if (a % 2 == 0) {
        if (is_pages_count_even) {
            output << "1 -1 3 -2 2 -1 100";
        }
        else {
            output << "1 -1 3 0 -2 2 -1 100";
        }
    }
    else {
        if (is_pages_count_even) {
            output << "2 -1 3 -2 1 -1 100";
        }
        else {
            output << "2 -1 3 0 -2 1 -1 100";
        }
    }
}
