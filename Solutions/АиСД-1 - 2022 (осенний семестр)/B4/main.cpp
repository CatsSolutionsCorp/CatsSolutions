#include <iostream>
#include <fstream>
#include <vector>
#include <array>

const int UNIT_CUBE_COLS = 7;
const int UNIT_CUBE_ROWS = 6;
const int UNIT_CUBE_DX = 4;
const int UNIT_CUBE_DY = 3;
const int UNIT_CUBE_DD = 3;

const std::vector<std::vector<char>> unit_cube = {
        {'0', '0', '+', '-', '-', '-', '+'},
        {'0', '/', ' ', ' ', ' ', '/', '|'},
        {'+', '-', '-', '-', '+', ' ', '|'},
        {'|', ' ', ' ', ' ', '|', ' ', '+'},
        {'|', ' ', ' ', ' ', '|', '/', '0'},
        {'+', '-', '-', '-', '+', '0', '0'},
};

void draw_unit_cube(int x, int y, int z, int w, int h, int d, std::vector<std::vector<char>> *canvas) {
    int first_row = canvas->size() - 6 - 3 * y - 2 * z;
    int first_col = 4 * x + 2 * z;
    for (int i = 0; i < UNIT_CUBE_ROWS; ++i) {
        for (int j = 0; j < UNIT_CUBE_COLS; ++j) {
            char current_ascii = unit_cube[i][j];
            if (current_ascii != '0') {
                (*canvas)[first_row + i][first_col + j] = unit_cube[i][j];
            }
        }
    }
}

void draw(std::vector<std::vector<char>> *canvas, std::ofstream *ofstream) {
    for (const std::vector<char> &row: *canvas) {
        for (char ascii: row) {
            *ofstream << ascii;
        }
        *ofstream << '\n';
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int w, h, d, w1, h1, d1;
    input >> w >> h >> d >> w1 >> h1 >> d1;

    int canvas_rows = 3 * h + 2 * d + 1;
    int canvas_cols = 4 * w + 2 * d + 1;
    std::vector<std::vector<char>> canvas;
    for (int i = 0; i < canvas_rows; ++i) {
        std::vector<char> row;
        for (int j = 0; j < canvas_cols; ++j) {
            row.push_back(' ');
        }
        canvas.push_back(row);
    }

    std::vector<std::array<int, 3>> anticube_positions;
    std::array<int, 3> antibox_position = {w - w1, h - h1, 0};
    for (int i = 0; i < w1; ++i) {
        for (int j = 0; j < h1; ++j) {
            for (int k = 0; k < d1; ++k) {
                anticube_positions.push_back(std::array<int, 3>{antibox_position[0] + i,
                                                                antibox_position[1] + j,
                                                                antibox_position[2] + k});
            }
        }
    }

    for (int k = d - 1; k >= 0; k--) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                bool are_ijk_of_antibox =
                        antibox_position[0] <= i && i < antibox_position[0] + w1 &&
                        antibox_position[1] <= j && j < antibox_position[1] + h1 &&
                        antibox_position[2] <= k && k < antibox_position[2] + d1;
                if (!are_ijk_of_antibox) {
                    draw_unit_cube(i, j, k, w, h, d, &canvas);
                }
            }
        }
    }

    for (int i = 0; i < 2 * d; ++i) {
        int j = 0;
        while (j <= canvas_cols && canvas[i][j] == ' ') {
            canvas[i][j] = '.';
            j++;
        }
    }

    draw(&canvas, &output);

    return 0;
}
