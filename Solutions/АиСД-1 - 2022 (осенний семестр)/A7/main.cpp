#include <fstream>

int main() {
    std::ifstream input("a.in");
    std::ofstream output("a.out");

    int k, n;
    input >> k >> n;

    int page_number = ((n - 1) / k) + 1;
    int line_number = (n - 1) % k + 1;

    output << page_number << ' ' << line_number;
    return 0;
}
