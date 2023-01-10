#include <fstream>
#include <map>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n1, n2, n3;
    input >> n1 >> n2 >> n3;
    int a1[n1], a2[n2], a3[n3];
    for (int i = 0; i < n1; ++i) {
        input >> a1[i];
    }
    for (int i = 0; i < n2; ++i) {
        input >> a2[i];
    }
    for (int i = 0; i < n3; ++i) {
        input >> a3[i];
    }

    std ::map<int, int> integer_occurrences;
    for (int i = 0; i < n1; ++i) {
        if (integer_occurrences.find(a1[i]) == integer_occurrences.end()) {
            integer_occurrences[a1[i]] = 1;
        }
        else {
            integer_occurrences[a1[i]] += 1;
        }
    }
    for (int i = 0; i < n2; ++i) {
        if (integer_occurrences.find(a2[i]) == integer_occurrences.end()) {
            integer_occurrences[a2[i]] = 1;
        }
        else {
            integer_occurrences[a2[i]] += 1;
        }
    }
    for (int i = 0; i < n3; ++i) {
        if (integer_occurrences.find(a3[i]) == integer_occurrences.end()) {
            integer_occurrences[a3[i]] = 1;
        }
        else {
            integer_occurrences[a3[i]] += 1;
        }
    }

    int count = 0;
    for (const auto& [integer, occurrences] : integer_occurrences) {
        if (occurrences == 3) count++;
    }

    output << count;

    return 0;
}
