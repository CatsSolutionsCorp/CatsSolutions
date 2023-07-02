#include <queue>
#include <vector>
#include <fstream>

using namespace std;



int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, m;
    long long sum = 0;
    std::priority_queue<int> thirst;

    fin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int thirstInd;

        fin >> thirstInd;

        sum += thirstInd;
        thirst.push(thirstInd);
    }

    for (int i = 0; i < m and sum > 0; i++) {
        auto max = thirst.top();
        auto res = max / 10;

        sum -= max - res;

        thirst.pop();
        thirst.push(res);
    }

    fout << sum;
}