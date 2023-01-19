/**
 **********************************
 * Copyrighted by Derlie Monne    *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>


struct Vector2 {
    Vector2(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

void debug(Vector2 o, Vector2 x, int n, int m, std::ofstream &output) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (o.x == i and o.y == j) {
                output << 'o';
            }
            else if (x.x == i and x.y == j) {
                output << 'x';
            }
            else {
                output << '-';
            }
        }
        output << '\n';
    }
    output << "======================\n";
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n >> m;

    Vector2 x = Vector2(1, 1);
    Vector2 o = Vector2(n, m);

    int steps_count = 0;
    if (m >= n) {
        // move x right
        x = Vector2(1, 2);
    }
    else {
        // move x down
        x = Vector2(2, 1);
    }
    o = Vector2(1, 1);
    steps_count += (n - 1) + (m - 1);

    while (not(x.x == n and x.y == m)) {
        bool down_move_possible = o.x != n;
        bool right_move_possible = o.y != m;
        bool o_on_left_of_x = o.y < x.y;
        bool o_on_top_of_x = o.x < x.x;

        // o x  ==>  - o
        // - -       - x
        if (o_on_left_of_x and down_move_possible) {
            steps_count += 3;
            x = Vector2(x.x + 1, x.y);
            o = Vector2(o.x, o.y + 1);
        }
        // o -  ==>  - -
        // x -       o x
        else if (o_on_top_of_x and right_move_possible) {
            steps_count += 3;
            x = Vector2(x.x, x.y + 1);
            o = Vector2(o.x + 1, o.y);
        }
        else {
            steps_count += 5;
            if (x.x == n) {
                x = Vector2(x.x, x.y + 1);
                o = Vector2(o.x, o.y + 1);
            }
            else if (x.y == m) {
                x = Vector2(x.x + 1, x.y);
                o = Vector2(o.x + 1, o.y);
            }
        }
    }

    output << steps_count;
}