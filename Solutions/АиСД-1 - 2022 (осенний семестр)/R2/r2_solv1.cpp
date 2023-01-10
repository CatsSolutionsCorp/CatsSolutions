/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>
#include <stack>
#include <set>

struct Cell {
    int x, y;
};

bool contains(std::set<int> &set1, int value) {
    return set1.find(value) != set1.end();
}

bool was_checked(std::set<int> *matrix, Cell cell) {
    return contains(matrix[cell.y], cell.x);
}

char get_answer(int n, int m, std::string &char_line, std::string &bit_line) {
    auto *calc_matrix = new std::set<int>[m];

    std::stack<Cell> calc_stack;
    calc_stack.push({0, 0});

    while (!calc_stack.empty()) {
        Cell this_cell = calc_stack.top();
        calc_stack.pop();

        int x = this_cell.x, y = this_cell.y;
        char this_char = char_line[y];
        char this_bit = bit_line[x];

        calc_matrix[y].insert(x);

        if (this_bit == '0' && this_char == 'b')
            continue;

        if (y == m - 1) {
            if (x == n - 1)
                return 'Y';
            continue;
        }

        if (x != n - 1 && !was_checked(calc_matrix, {x + 1, y + 1}))
            if (x != n - 1)
                calc_stack.push({x + 1, y + 1});

        if (char_line[y + 1] == this_char && !was_checked(calc_matrix, {x, y + 1}))
            if (char_line[y + 1] == this_char)
                calc_stack.push({x, y + 1});
    }
    return 'N';
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n >> m;

    std::string bit_line;
    std::string char_line;

    input.get();
    getline(input, bit_line);
    getline(input, char_line);

    char answer = get_answer(n, m, char_line, bit_line);
    output << answer;
    return 0;
}
