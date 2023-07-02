#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0)
#define аминь return 0
using namespace std;


int main() {
    fast;
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    string s; // l - длина подстроки, m - длина окна
    int l, m, max_count = 0;
    cin >> l >> m >> s;
    unordered_map<string, int> map_index;
    vector<int> index_count(m + 1);

    // В этом цикле мы заполняем словарь и массив-счётчик
    for (int i = 0; i <= m - l; ++i) {
        // Вытаскиваем подстроку и закидываем в словарь
        string sub = s.substr(i, l);
        map_index[sub]++;

        // Чтобы не считать одну и ту же подстроку дважды
        if (index_count[map_index[sub] - 1] > 0)
            index_count[map_index[sub] - 1]--;

        index_count[map_index[sub]]++;
        max_count = max(max_count, map_index[sub]);
    }

    // Выводим первый элемент. Тем самым мы как обработали граничные условия
    // Так и дальнейший цикл не поломается
    cout << max_count << " ";

    for (int i = 1; i <= s.size() - m; ++i) {
        string old_sub = s.substr(i - 1, l);
        index_count[map_index[old_sub]]--;
        map_index[old_sub]--;
        if (index_count[max_count] == 0)
            max_count--;
        index_count[map_index[old_sub]]++;

        string new_sub = s.substr(i + m - l, l);
        map_index[new_sub]++;
        if (index_count[map_index[new_sub] - 1] > 0)
            index_count[map_index[new_sub] - 1]--;
        index_count[map_index[new_sub]]++;
        max_count = max(max_count, map_index[new_sub]);

        std::cout << max_count << " ";
    }
    аминь;
}