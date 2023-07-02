#include <iostream>
#include <vector>

const long long BASE = 1e9 + 9;
std::vector<unsigned long long> pows = {1};
std::vector<unsigned long long> hashes = {0};

unsigned long long getHash(int l, int r) {
    return ::hashes[r + 1] - ::hashes[l] * ::pows[r - l + 1];
}

bool checkTwoSubs(int a, int b, int c, int d) {
    return ::getHash(a, b) == ::getHash(c, d);
}


int main() {
    std::string s;
    int m;

    std::cin >> s >> m;

    for (char c: s) 
    {
        ::hashes.push_back(::hashes.back() * ::BASE + c);
        ::pows.push_back(::pows.back() * ::BASE);
    }

    for (int i = 0; i < m; ++i) 
    {
        int a, b, c, d;

        std::cin >> a >> b >> c >> d;

        std::cout << (checkTwoSubs(--a, --b, --c, --d) ? "Yes\n" : "No\n");
    }

    return 0;
}