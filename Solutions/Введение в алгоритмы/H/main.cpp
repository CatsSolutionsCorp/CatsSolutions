/**
 **********************************
 * Copyrighted by Derlie Monne    *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>
#include <array>
#include <numeric>


template <size_t N>
struct BigFuckingUnsignedInt {
    std::array<short, N> digits;

    explicit BigFuckingUnsignedInt(unsigned int number) {
        digits.fill(0);
        int i = N - 1;
        while (number != 0) {
            short digit = short(number % 10);
            number /= 10;
            digits[i] = digit;
            i -= 1;
        }
    }

    BigFuckingUnsignedInt<N> operator+(const BigFuckingUnsignedInt<N> rv) const {
        BigFuckingUnsignedInt<N> sum(0);
        short remainder = 0;
        for (int i = N - 1; i != 0; --i) {
            short digits_sum = digits[i] + rv.digits[i] + remainder;
            short digit = short(digits_sum % 10);
            sum.digits[i] = digit;
            remainder = short(digits_sum / 10);
        }
        return sum;
    }

    operator std::string () const {
        return "SomeClassStringRepresentation";
    }

    void print(std::ofstream &output) {
        bool is_current_lead_zeros = digits[0] == 0;
        for (int i = 0; i < N; ++i) {
            if (is_current_lead_zeros) {
                if (digits[i] == 0) {
                    continue;
                }
                else {
                    is_current_lead_zeros = false;
                }
            }
            output << digits[i];
        }
    }

};



int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, k;
    input >> n >> k;

    int gcd_n_k = std::gcd(n, k);
    BigFuckingUnsignedInt<1000> f1(1);
    BigFuckingUnsignedInt<1000> f2(1);
    for (int i = 0; i < gcd_n_k - 2; ++i) {
        BigFuckingUnsignedInt<1000> f1_tmp = f1;
        f1 = f2;
        f2 = f1_tmp + f2;
    }
    f2.print(output);
    return 0;
}
