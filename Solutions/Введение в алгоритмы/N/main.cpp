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
#include <algorithm>
#include <deque>


struct Vector2 {
    Vector2(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;

    // degenerate case
    if (n == 1) {
        output << 0;
        return 0;
    }

    char labyrinth[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> labyrinth[i][j];
        }
    }

    int distances[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distances[i][j] = 0;
        }
    }

    std::deque<Vector2> to_visit;
    to_visit.emplace_back(0, 0);

    while (!to_visit.empty()) {
        Vector2 visit = to_visit.front();
        to_visit.pop_front();

        auto neighbors = {Vector2(visit.x, visit.y + 1),
                          Vector2(visit.x, visit.y - 1),
                          Vector2(visit.x + 1, visit.y),
                          Vector2(visit.x - 1, visit.y)};
        for (const Vector2 &neighbor : neighbors) {
            bool neighbor_is_inside_labyrinth = 0 <= neighbor.x and neighbor.x < n and
                                                0 <= neighbor.y and neighbor.y < n;
            if (!neighbor_is_inside_labyrinth) continue;

            bool neighbor_already_computed = distances[neighbor.x][neighbor.y] != 0;
            bool neighbor_is_wall = labyrinth[neighbor.x][neighbor.y] == '#';
            if (neighbor_already_computed or neighbor_is_wall) continue;

            distances[neighbor.x][neighbor.y] = distances[visit.x][visit.y] + 1;
            to_visit.push_back(neighbor);
        }
    }

    int shortest_path = distances[n-1][n-1];
    output << (shortest_path == 0 ? -1 : shortest_path);
    return 0;
}