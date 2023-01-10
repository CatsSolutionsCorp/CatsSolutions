#include <fstream>

int to_int(char c) {
    return c == '1' ? 1 : 0;
}

int main() {
    std::ifstream input("function.in");
    std::ofstream output("function.out");

    int n;
    std::string bool_description;
    input >> n >> bool_description;

    int result_of_00 = to_int(bool_description[0]);
    int result_of_01 = to_int(bool_description[1]);
    int result_of_10 = to_int(bool_description[2]);
    int result_of_11 = to_int(bool_description[3]);

    char result[n + 1];
    result[n] = '\0';
    if (result_of_00 == 0 && result_of_01 == 0 && result_of_10 == 0 && result_of_11 == 0) {
        output << "No solution";
        return 0;
    }
    else if (result_of_11 == 1) {
        for (int i = 0; i < n; ++i) {
            result[i] = '1';
        }
    }
    else if (result_of_01 == 1) {
        result[0] = n % 2 == 0 ? '0' : '1';
        for (int i = 1; i < n; ++i) {
            result[i] = '1';
        }
    }
    else if (result_of_00 == 1) {
        for (int i = 0; i < n - 1; ++i) {
            result[i] = '1';
        }
        result[n-1] = '0';
    }
    else {
        result[0] = '1';
        for (int i = 1; i < n; ++i) {
            result[i] = '0';
        }
    }

    output << result;
    return 0;
}
