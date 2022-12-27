#include <iostream>
#include <fstream>

using namespace std;


int f(int a_1) {
    int a_prev_prev;
    int a_prev;
    int a = a_1;

    int i = 2;
    while (true) {
        if (i > 2) {
            a_prev_prev = a_prev;
        }
        a_prev = a;
        a = abs(a_prev - 100);

        if (i > 2 && a == a_prev_prev) {
            int n = i - 1;
            return n;
        }

        i++;
    }
}

int main() {
    ifstream input("input.txt");
    int a_1;
    input >> a_1;
    int n = f(a_1);
    ofstream output("output.txt");
    output << n;
}
