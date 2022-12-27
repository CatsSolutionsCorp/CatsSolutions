#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


std::vector<int> get_digits_of_number(int number) {
    std::vector<int> digits;
    int remain = number;
    while (remain != 0) {
        int digit = remain % 10;
        digits.push_back(digit);
        remain /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

int get_number_from_digits(std::vector<int> digits) {
    int power_of_ten = digits.size() - 1;
    int result = 0;
    for (int digit : digits) {
        result += digit * std::pow(10, power_of_ten);
        --power_of_ten;
    }
    return result;
}

int main() {
    std::ifstream input("input.txt");

    int a;
    input >> a;

    std::vector<int> digits = get_digits_of_number(a);
    std::sort(digits.rbegin(), digits.rend());
    std::vector<int> b_digits(digits.begin(), digits.end() - 1);
    int b = get_number_from_digits(b_digits);
    std::vector<int> c_digits(digits.end() - 1, digits.end());
    int c = get_number_from_digits(c_digits);

    std::ofstream output("output.txt");
    output << b << " " << c << std::endl;
}