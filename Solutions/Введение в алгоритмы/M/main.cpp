#include <fstream>
#include <deque>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n, m;
    int di_dj_of_neighbors[4][2] = {{1,  0},
                                    {-1, 0},
                                    {0,  1},
                                    {0,  -1}};
    std::deque<std::pair<int, int>> next_positions;
    input >> n >> m;
    char labyrinth[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            input >> labyrinth[i][j];
            if (labyrinth[i][j] == 'S') {
                auto next_position = std::make_pair(i, j);
                next_positions.push_back(next_position);
            }
        }
    }
    bool visited[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    while (!next_positions.empty()) {
        auto position = next_positions.front();
        int cur_i = position.first;
        int cur_j = position.second;
        next_positions.pop_front();
        if (visited[cur_i][cur_j]) continue;
        visited[cur_i][cur_j] = true;

        if (labyrinth[cur_i][cur_j] == 'F') {
            output << "YES";
            return 0;
        }
        for (int *di_dj: di_dj_of_neighbors) {
            int i = cur_i + di_dj[0];
            int j = cur_j + di_dj[1];
            if (i >= 0 && i <= n - 1 &&
                j >= 0 && j <= m - 1 &&
                !visited[i][j] &&
                labyrinth[i][j] != '#') {
                auto next_position = std::make_pair(i, j);
                next_positions.push_back(next_position);
            }
        }

    }
    output << "NO";
    return 0;
}
