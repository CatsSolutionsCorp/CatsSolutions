#include <bits/stdc++.h>
using namespace std;

// Идея в том, что слог эквивалентен гласной в контексте этой задачи
// Поэтому она сводится к тому, чтобы подсчитать количество гласных
// Для каждого предложения и присвоить ему флаг восклицания.
// Хранить характеристики строчек будем в парах <количество,восклицание> 
// Для каждого из певцов. После просто составим табличку пересечений и 
// Будем итерационно накапливать ответ. 


// Считаем количество гласных в строке, записываем их количество в 
// Соответствующую строке ячейку вектора, а также то, восклицательное ли
void count_vowels(vector<pair<int, bool>> &vec, int len) {
  string vowels = "aeiouyAEIOUY"; // vowels - гласные
  while(len--) {
    string str; getline(cin >> ws, str);
  
    bool exc = false; // от слова exclamation - восклицание
    int counter = 0;

    // npos указывает, что символ не найден. Я его, кста, не смог задефайнить
    // Может, у вас как-то получится? а то что-то не очень красиво выглядит
    for (char i: str){ 
      if (vowels.find(i) != std::string::npos)  counter++;
      if (i == '!')  exc = true;
    }
    
    vec.push_back({counter, exc});
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int len_first, len_second; cin >> len_first >> len_second;

  // Как идея - можете тайпдефнуть вектор пар, чтобы код красивше был
  vector<pair<int, bool>> first, second;
  count_vowels(first, len_first);
  count_vowels(second, len_second);

  // Таблица будет накапливать в себе количество общих слогов
  // По факту, нам таблица и не нужна, мы можем просто
  // Бежать по двум массивам и, если совпадает количество слогов,
  // То суммировать куда-то. Но задача на динамику, так что...
  vector<vector<pair<int, bool>>> table(len_first + 1, 
                                  vector<pair<int, bool>>(len_second + 1));

  for (int i = 1; i <= len_first; i++)
    for (int j = 1; j <= len_second; j++) {

      table[i][j].first = max(table[i-1][j].first, table[i][j-1].first);
      if (first[i-1] == second[j-1])
        table[i][j].first = table[i-1][j-1].first + abs(first[i-1].first);
    }

  cout << table[len_first][len_second].first;

  return 0;
}