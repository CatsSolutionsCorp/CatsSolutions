#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, d;
    input >> n >> d;
    int a[n];
    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    int postfix_max_indices[n];
    postfix_max_indices[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        postfix_max_indices[i] = a[postfix_max_indices[i + 1]] >= a[i] ?
                postfix_max_indices[i + 1] : i;
    }

    int max_sum = -1;
    int i = 0;
    int j = 0;
    while (i < n - d) {
        while (postfix_max_indices[j] - i < d ) j++;
        int curr_sum = a[i] + a[postfix_max_indices[j]];
        max_sum = std::max(max_sum, curr_sum);
        i++;
    }

    output << max_sum;
}
