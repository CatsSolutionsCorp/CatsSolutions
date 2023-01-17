/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/

#include <fstream>
#include <cmath>

struct Price {
    int squares_count;
    std::string squares;
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, k;
    input >> n >> k;

    Price *prices = new Price[n + 1];
    prices[0] = {0, ""};

    for (int i = 1; i <= n; ++i) {
        std::string squares;
        int squares_count = 0;
        for (int j = (int)(std::sqrt(i)); j > 0; --j) {
            // j^2 + complement == i
            int complement = i - j * j;
            if (squares_count == 0 || prices[complement].squares_count + 1 < squares_count) {
                squares_count = prices[complement].squares_count + 1;
                squares = prices[complement].squares + std::to_string(j) + " ";
            }
        }
        prices[i] = {squares_count, squares};
    }
    if (prices[n].squares_count <= k) {
        output << "YES" << std::endl << prices[n].squares;
    }
    else {
        output << "NO";
    }

    return 0;
}