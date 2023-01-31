/**
 **********************************
 * Copyrighted by Derlie Monne    *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>
#include <vector>
#include <algorithm>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int a_i;
        input >> a_i;
        a[i] = a_i;
    }

    int sips_count = 0;
    while (sips_count < m) {
        std::sort(a.begin(), a.end());
        a[n-1] /= 10;
        sips_count += 1;

        int j = n-2;
        while (j >= 0 and a[j] >= a[n-1] and sips_count < m) {
            a[j] /= 10;
            sips_count += 1;
            j -= 1;
        }

    }

    long long a_sum = 0;
    for (int i = 0; i < n; ++i) {
        a_sum += a[i];
    }
    output << a_sum;

    return 0;
}
