#include <iostream>
#include <fstream>

using namespace std;

// for powers >= 0
int power(int base, int power) {
    if (power == 0) return 1;
    int result = base;
    for (int i = 0; i < power - 1; ++i) {
        result *= base;
    }
    return result;
}

int digits_in_number(int number) {
    int count = 0;
    int remain = number;
    while (remain != 0) {
        ++count;
        remain /= 10;
    }
    return count;
}

int reverse(int number) {
    int reversed_number = 0;
    int digit_index = digits_in_number(number) - 1;

    int remain = number;
    while (remain != 0) {
        int digit = remain % 10;
        reversed_number += digit * power(10, digit_index);
        --digit_index;
        remain /= 10;
    }
    return reversed_number;
}

int f(int k) {
    int count = 0;
    for (int i = 0; i <= k; ++i) {
        if (i + reverse(i) == k) {
            ++count;
        }
    }
    return count;
}

int main() {
    cout << reverse(2140090);

    ifstream input("input.txt");
    int k;
    input >> k;
    int result = f(k);
    ofstream output("output.txt");
    output << result;
}