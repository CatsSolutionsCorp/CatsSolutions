#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    char a;
    char b = '*';
    for (int i = 0; i < 5; ++i) {
        input >> a;
        if (b != '?' && a != '=') {
            if (a == '>') {
                if (b == '+') b = '?';
                else b = '-';
            }
            else if (a == '<') {
                if (b == '-') b = '?';
                else b = '+';
            }
        }
        output << b;
    }
}
