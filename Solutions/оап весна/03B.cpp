#include <fstream>
#include <vector>

const int PRIME = 31;
const int MOD = 1e9 + 7;

std::vector<long long> deg = {1};
std::vector<long long> hashes = {0};


long long hash(int left, int length) {
    return hashes[left + length] - hashes[left] * deg[length];
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string inputString;
    int m, a, b, c, d;
    in >> inputString;
    in >> m;

    for (char i: inputString) {
        int x = (int) (i - 'a' + 1);
        hashes.push_back((hashes.back() * PRIME + x) % MOD);
        deg.push_back((deg.back() * PRIME) % MOD);
    }

    for (int i = 0; i < m; i++) {
        in >> a >> b >> c >> d;
        if (((hash(a - 1, b - a + 1) - hash(c - 1, d - c + 1)) % MOD == 0))
            out << "Yes\n";
        else
            out << "No\n";
    }
}
