#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    std::vector<std::vector<int>> adjacents;
    adjacents.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        input >> k;
        for (int j = 0; j < k; ++j) {
            int adjacent;
            input >> adjacent;
            adjacents[i].push_back(adjacent);
        }
    }

    int ds[n + 1];
    ds[1] = 0;
    for (int i = 2; i <= n; ++i) {
        ds[i] = -1;
    }

    std::queue<int> to_visit;
    to_visit.push(1);
    while (!to_visit.empty()) {
        int parent = to_visit.front();
        to_visit.pop();
        for (int child: adjacents[parent]) {
            if (ds[child] == -1) {
                if (ds[parent] == -1) {
                    output << "OOPS\n";
                }
                ds[child] = ds[parent] + 1;
                to_visit.push(child);
            }
        }
    }

    int result[n + 1];
    for (int i = 1; i <= n; ++i) {
        result[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (ds[i] != -1) {
            for (int child: adjacents[i]) {
                if (ds[child] >= ds[i]) {
                    result[child] += 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        output << result[i] << ' ';
    }

    return 0;
}
