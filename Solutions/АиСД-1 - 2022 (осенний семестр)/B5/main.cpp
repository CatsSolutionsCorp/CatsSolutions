#include <iostream>
#include <math.h>

using namespace std;

int get_exponent(float f) {
    if (f == 0) return 0;
    if (isnan(f)) return -126;
    int f_bits_as_int = *(int *) &f;
    f_bits_as_int >>= 23;
    f_bits_as_int &= 0b11111111;
    if (f_bits_as_int == 0) return -126;
    f_bits_as_int -= 127;
    return f_bits_as_int;
}

int main() {
    float f;
    cin >> f;
    cout << get_exponent(f);
}