/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>
#include <vector>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        input >> a[i] >> b[i];
    }

    int m;
    input >> m;
    int c[m], d[m];
    for (int i = 0; i < m; ++i) {
        input >> c[i] >> d[i];
    }

    std::vector<std::pair<int, int>> segments;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int left = std::max(a[i], c[j]);
            int right = std::min(b[i], d[j]);
            bool segment_exists = left < right;
            if (segment_exists) {
                segments.emplace_back(left, right);
            }
        }
    }

    output << segments.size() << '\n';
    for (const auto &[left, right] : segments) {
        output << left << ' ' << right << '\n';
    }


    return 0;
}