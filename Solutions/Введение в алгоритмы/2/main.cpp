#include <iostream>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int n;
    fscanf(input, "%d", &n);
    int cube[n][n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cube[i][j][k] = (i + j + k) % n + 1;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                fprintf(output, "%d ", cube[i][j][k]);
            }
            fprintf(output, "\n");
        }
    }
}
