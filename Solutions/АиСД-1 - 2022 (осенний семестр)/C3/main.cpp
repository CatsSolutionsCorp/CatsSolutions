#include <fstream>
#include <map>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    std::map<int, int> count;

    for (int i = 0; i < n; ++i) {
        int number;
        input >> number;
        if (count.find(number) == count.end()) {
            count[number] = 1;
        } else {
            count[number] += 1;
        }
    }

    for (auto &it: count) {
        output << it.first << " " << it.second << '\n';
    }

    return 0;
}