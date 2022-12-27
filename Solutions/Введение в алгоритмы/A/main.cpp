#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string input_to_output(int n, std::vector<int> eat_days) {
    int last_day = eat_days[n - 1];
    int eaten_already[last_day + 6];
    for (int i = 0; i < last_day + 6; ++i) {
        eaten_already[i] = 0;
    }

    for (int eat_day : eat_days) {
        for (int j = 0; j < 7; ++j) {
            ++eaten_already[eat_day - 1 + j];
        }
    }

    for (int eaten_already_in_day : eaten_already) {
        if (eaten_already_in_day > 2) return "BAD";
    }
    return "GOOD";
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n = 0;
    input >> n;
    std::vector<int> eat_days;
    for (int i = 0; i < n; ++i) {
        int eat_day;
        input >> eat_day;
        eat_days.push_back(eat_day);
    }

    output << input_to_output(n, eat_days);
}