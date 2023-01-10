/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <iostream>
#include <algorithm>

bool compare_strings(std::string &a, std::string &b) {
    if (a.size() < b.size())
        return true;
    else if (b.size() < a.size())
        return false;

    for (int i = 0; i < a.size(); i++) {
        if (int(a[i]) < int(b[i]))
            return true;
        else if (int(a[i]) > int(b[i]))
            return false;
    }

    return false;
}

struct Digit {
    std::string str;
    int y;
    int x;
};

int main() {
    int a, b;
    std::cin >> a >> b;

    auto **table = new std::string *[a + 1];
    for (int i = 0; i <= a; i++) {
        table[i] = new std::string[b + 1];
        std::fill(&table[i][0], &table[i][b + 1], "-1");
    }


    Digit digits[8] = {
            {"0", 6, 0},
            {"1", 2, 1},
            {"2", 3, 1},
            {"3", 2, 2},
            {"4", 4, 0},
            {"5", 5, 0},
            {"6", 4, 1},
            {"8", 7, 0},
    };


    for (auto &digit: digits) {
        if (digit.str == "0")
            continue;
        if (digit.y <= a && digit.x <= b)
            table[digit.y][digit.x] = digit.str;
    }

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            std::string new_value = table[i][j];
            for (auto &digit: digits) {
                int prev_y = i - digit.y, prev_x = j - digit.x;
                if (prev_y >= 0 && prev_x >= 0) {
                    auto prev_num = table[prev_y][prev_x];
                    auto this_num = prev_num + digit.str;
                    if (prev_num != "-1" && (new_value == "-1" || compare_strings(this_num, new_value)))
                        new_value = this_num;
                }
            }
            table[i][j] = new_value;
        }
    }

    if (table[a][b] == "-1")
        std::cout << "Wrong";
    else
        std::cout << table[a][b];
}
