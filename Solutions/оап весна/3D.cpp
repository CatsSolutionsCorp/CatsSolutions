#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0)
using namespace std;

const int sz = 1e3;
vector<string> arr(sz + 2);


int put_in_hash(string a) {
    int t = 0;
    for (char i : a) {
        t += i;
    }
    t = abs(t % sz);
    while (!arr[t].empty()) {
        if (arr[t] == a) {
            return t;
        }
        t = (t + 1) % sz;
    }
    arr[t] = a;
    return t;
}

//48 = '0'; 57 = '9'

// Идея в том, чтобы создать хэш-таблицу, в которой мы будем хранить номера школ, 
// а в дополнительном массиве будем хранить количество упоминаний, по факту тот же map, только на двух массивах :)

// Что надо сделать:
// 1) Пройтись по строке и вытащить номер школы
// 2) Т.к. при инициализации наш массив заполняен нулями
//   То мы просто плюсуем в эту ячейку с номером школы единичку
// 3) Проходимся по получившемуся массиву и смотрим на кол-во 
//   Удовлетворяющих условию школ, увеличивая счётчик
// 4) Вывод счётчика, а после проходимся по хэш-таблице повторно, выводя нужные номера школ

int main(){
    fast;
    freopen("schools.in", "r", stdin); freopen("schools.out", "w", stdout);
    int n;
    vector<int>county(sz+2,0); // массив, где будет храниться количество упоминаний школ
    cin >> n;
    cin >> ws; // убираем все пробелы
    while(n--){
        string str,num;
        getline(cin,str);
        for(char i : str){
            if(i >= '0' && i <= '9') // считываем номер школы и записываем в переменную num
                num += i; 
        }
        county[put_in_hash(num)]++; // находим под каким индексом она будет храниться в хэш-функции
        // и под этим же номером добавляем +1 в массив упоминаний
    }
    int k = 0;
    // считаем количество школ, подходящих под условие
    for(int i = 0;i < county.size();i++){
        if(county[i] <= 5 && county[i] > 0){
            k+=1;
        }
    }
    cout << k << '\n';
    for(int i = 0;i<arr.size();i++){
        if(county[i] <= 5 && county[i] > 0){
            cout << arr[i] << '\n'; // здесь уже выводим номер школы
        }
    }
    return 0;
}
