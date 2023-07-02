#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

class Button {
public:
    int x;
    int y;
};

class Position {
public:
    int l{};
    int r{};
    int count = 0;
    double sum = 0;
    int t{};
};

double distance(Button l, Button r) {
    return sqrt((pow(l.x - r.x, 2) + pow(l.y - r.y, 2)));
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    Button mas[10] = {4, 2, 1, 1, 1, 2, 1, 3, 2, 1,
                      2, 2, 2, 3, 3, 1, 3, 2, 3, 3};
    int n, a, l, r;
    double d;

    in >> n;

    std::vector<Position> positions, newPositions;
    positions.push_back({4, 6, 0, 0});
    Position dial[10][10];

    for (int i = 1; i <= n; i++) {
        in >> a;

        for (int j = 0; j < positions.size(); j++) {
            l = positions[j].l;
            r = positions[j].r;
            d = distance(mas[r], mas[a]);

            if (mas[a].y >= mas[l].y && a != l) {
                if (dial[l][a].count == i) {
                    if (dial[l][a].sum > positions[j].sum + d) {
                        dial[l][a].sum = positions[j].sum + d;
                        newPositions[dial[l][a].t].sum = positions[j].sum + d;
                    }
                } else {
                    dial[l][a].count = i;
                    dial[l][a].sum = positions[j].sum + d;
                    newPositions.push_back({l, a, i, positions[j].sum + d});
                    dial[l][a].t = newPositions.size() - 1;
                }
            }
            d = distance(mas[l], mas[a]);

            if (mas[a].y <= mas[r].y && a != r) {
                if (dial[a][r].count == i) {
                    if (dial[a][r].sum > positions[j].sum + d) {
                        dial[a][r].sum = positions[j].sum + d;
                        newPositions[dial[a][r].t].sum = positions[j].sum + d;
                    }
                } else {
                    dial[a][r].count = i;
                    dial[a][r].sum = positions[j].sum + d;
                    newPositions.push_back({a, r, i, positions[j].sum + d});
                    dial[a][r].t = newPositions.size() - 1;
                }
            }
        }
        positions.clear();
        positions = newPositions;
        newPositions.clear();
    }
    double min = INFINITY;

    for (int i = 0; i < positions.size(); i++)
        min = (min < positions[i].sum) ? min : positions[i].sum;

    out << std::setprecision(16) << min;

    return 0;
}