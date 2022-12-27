#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int x1, y1, x2, y2;
    input >> x1 >> y1 >> x2 >> y2;

    // if cells have different parity:
    if (((x1 + y1) % 2) != ((x2 + y2) % 2)) {
        output << 0;
        return 0;
    }

    // if pawns are on diagonal:
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (abs(dx) == abs(dy)) {
        if (abs(dx) == 1) output << 0;
        else {
            int half_way = abs(dx) / 2;
            int bishop_x = x1 + (dx / abs(dx) * half_way);
            int bishop_y = y1 + (dy / abs(dy)) * half_way;
            output << bishop_x << " " << bishop_y;
        }
        return 0;
    }

    int b1 = y1 - x1;
    int b2 = y1 + x1;
    int b3 = y2 - x2;
    int b4 = y2 + x2;

    int x14 = (b4 - b1) / 2;
    int y14 = x14 + b1;
    int x23 = (b2 - b3) / 2;
    int y23 = x23 + b3;

    if (1 <= x14 && x14 <= 8 && 1 <= y14 && y14 <= 8) {
        output << x14 << " " << y14;
        return 0;
    }
    if (1 <= x23 && x23 <= 8 && 1 <= y23 && y23 <= 8) {
        output << x23 << " " << y23;
        return 0;
    }
    return -1;
}
