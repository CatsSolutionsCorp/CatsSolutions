#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <list>

const int BASE = 120;
const int MOD = 4 * 1000;

class HashTable {
    private:
        std::list<std::pair<std::string, int>> table[::MOD];
        
    public:
        void add(std::string, int);

        int get(std::string);
};


unsigned long long hashing(std::string key) {
    unsigned long long result = 0;

    for (char c: key)
        result = (result * ::BASE + (c - 'a' + 1)) % ::MOD;

    return result;
}


void HashTable::add(std::string key, int value) {
    unsigned long long hashIdx = hashing(key);
    auto &cell = table[hashIdx];
    auto bIt = std::begin(cell);
    bool keyExst = false;

    while (bIt != std::end(cell)) {
        if (bIt->first == key) {
            keyExst = true;
            bIt->second = value;
            
            break;
        }
        bIt++;
    }

    if (!keyExst) {
        cell.emplace_back(key, value);
    }
}


int HashTable::get(std::string key) {
    unsigned long long hashIdx = hashing(key);
    auto &cell = table[hashIdx];
    auto bIt = std::begin(cell);
    
    while (bIt != std::end(cell)) {
        if (bIt->first == key)
            return bIt->second;
        
        bIt++;
    }

    return 0;
}


int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    
    int n, m, k;
    HashTable hastT;
    std::string keyP1, keyP2;
    std::vector<std::string> allKeys;

    in >> n;

    int answers[n][n];

    memset(answers, 0, sizeof(answers));

    for (int i = 0; i < n; ++i) {
        in >> keyP1;
        allKeys.push_back(keyP1);
    }

    std::sort(allKeys.begin(), allKeys.end());

    for (int i = 0; i < n; i++) hastT.add(allKeys[i], i);

    in >> m;

    for (int i = 0; i < m; i++) {
        in >> keyP1 >> keyP2;

        answers[hastT.get(keyP1)][hastT.get(keyP2)] = 1;
        answers[hastT.get(keyP2)][hastT.get(keyP1)] = 2;
    }

    in >> k;

    for (int i = 0; i < k; i++) {
        in >> keyP1 >> keyP2;
        
        out << answers[hastT.get(keyP1)][hastT.get(keyP2)] << " ";
    }
    
    return 0;
}
