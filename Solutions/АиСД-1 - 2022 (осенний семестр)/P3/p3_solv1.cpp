/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>

bool array3_comp(std::array<int, 3> &a1, std::array<int, 3> &a2) {
    return a1[0] < a2[0];
}

int bin_search(int value, std::vector<int> &vec) {
    int left = 0;
    int right = vec.size() - 1;

    while (right > left) {
        int middle = (left + right) / 2;
        int ind_val = vec[middle];
        if (value < ind_val)
            right = middle - 1;
        else
            left = middle + 1;
    }

    if (value < vec[left])
        return left;
    else
        return left + 1;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n >> m;

    // Первую команду сохраняем в виде матрицы, в которой для каждого бойца будем хранить его
    // мастерство, весовую категорию и разницу в очках
    std::vector<std::array<int, 3>> sorted1;
    for (int i = 0; i < n; i++) {
        int pi, ci;
        input >> pi >> ci;
        sorted1.push_back(std::array<int, 3>{pi, ci - 1, 0});
    }
    // Отсортируем ее по возрастанию
    std::sort(sorted1.begin(), sorted1.end(), &array3_comp);

    // Вторую команду будем хранить как словарь, где ключи - вес, а значения - мастерство
    auto *team2 = new std::vector<int>[m];
    for (int i = 0; i < n; i++) {
        int pi, ci;
        input >> pi >> ci;
        team2[ci - 1].push_back(pi);
    }
    // Отсортируем каждый вес, чтобы далее использовать бин поиск
    for (int i = 0; i < m; i++)
        std::sort(team2[i].begin(), team2[i].end());

    // Считаем разницу в очках для каждого бойца первой команды и для всей команды в сумме
    int team_point_diff = 0;
    for (auto &fighter: sorted1) {
        int fighter_points = 2 * bin_search(fighter[0], team2[fighter[1]]) - team2[fighter[1]].size();
        fighter[2] = fighter_points;
        team_point_diff += fighter_points;
    }

    // Заполняем префикс максимум в виде {мастерство, вес}, чтобы правильно выбирать чит веса
    std::vector<std::array<int, 2>> prefix_max(n);
    prefix_max[0] = {sorted1[0][2], sorted1[0][1]};
    for (int i = 1; i < n; i++)
        if (sorted1[i][2] > prefix_max[i - 1][0])
            prefix_max[i] = {sorted1[i][2], sorted1[i][1]};
        else
            prefix_max[i] = prefix_max[i - 1];

    // Считаем лучший чит
    int max_cheat = std::numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        // В качестве новой категории берем префикс максимум (максимальный результат)
        int fighter_prof = sorted1[i][0];
        int fighter_diff = sorted1[i][2];
        int new_category = prefix_max[i][1];
        auto team2_new_cat = team2[new_category];
        int cheat = 2 * bin_search(fighter_prof, team2_new_cat) - team2_new_cat.size()
                    - fighter_diff;
        if (cheat > max_cheat)
            max_cheat = cheat;
    }
    output << team_point_diff + max_cheat;
}
