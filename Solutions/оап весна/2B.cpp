#include <bits/stdc++.h>
using namespace std;
// Разбор: https://www.youtube.com/watch?v=7kV2wpIPKFI
//     !!!!! ОЧЕНЬ ВАЖНО !!!!! У меня почему-то не проходило проверку, если не через лонги решал,
// 				а через инты. Также если current_area определять вне второго ифа, 
// 				то тогда на каких-то тестах крашило. Очень странная фигня
 

// Идея в том, чтобы отсортировать все вершины (поля) по убыванию х-координаты
// Хранить их будем в очереди с приоритетом, у которой корень - минимальный элемент 
// И при добавлении новой вершины у нас как-бы выпихивается минимальная (даже если это и есть только что добавленная)

struct Field {
    long long int x, y;
};

bool compare(Field &left, Field &right){ return left.x > right.x;}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);

    int n, limit;
    cin >> n >> limit;
    vector<Field> fields(n);

    int n_copy = n+1;
    // классика, которой я заменяю заполнение вектора полей.
    // пишите for (int i = 0...) и погнали
    while(n_copy--) cin >> fields[n-n_copy].x >> fields[n-n_copy].y;

    //Используется внешняя функция compare для сортировки. Сравнивается по убыванию х-координаты
    // По факту, можно и через merge_sort Бори написать. Если нужно - в ЛС кину
    sort(fields.begin(), fields.end(), compare);

    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    long long int max_area = 0, current_area;
    for (Field f: fields) {
        pq.push(f.y);
        //Тут очень важно именно два последовательных ифа, т.к.
        // У нас, по факту, сначала оно удаляется, а потом моментально заходит
        // Во второй иф, т.к. длина может перескакнуть только на 1
        if (pq.size() > limit) pq.pop();
        if (pq.size() == limit) {
            current_area = f.x * pq.top();
            max_area = max(max_area, current_area);
        }
    }
    cout << max_area;
    return 0;
}