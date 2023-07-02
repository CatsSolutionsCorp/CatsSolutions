#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int test; cin >> test;
  while(test--) {


    //У нас будет существовать последовательность перезапусков таймеров тогда 
    // и только тогда, когда Т предаствим ввиде линейной комбинации a и b

    //max_reset отражает, сколько сбросов времени мы можем сделать
    int T, a, b; cin >> T >> a >> b;
    int max_reset = T / a, reset_a = 0, reset_b = 0;
    
    bool is_found = false;
    while (!is_found && reset_a < max_reset) {
      reset_b = 0;

      //тупо-глупо перебираем все возможные комбинации 
      // reset_b и reset_a, ища ту самую заветную
      while (!is_found && a * reset_a + b * reset_b<= T) {
        if (a * reset_a + b * reset_b== T) {
          is_found = true; reset_a--; reset_b--; //Потому что потом прибавим
        }
        reset_b++;
      }
      
      reset_a++;
    }

    
    // Если мы можем обойтись переворотом только второго таймера
    if (is_found && reset_a == 0 && b * reset_b > a) {
      cout << reset_b << endl;
      cout << 0 << ' ' << 3 << endl;

      //Вертим второй таймер столько раз, сколько потребно
      for (int t = b; t < b * reset_b; t += b) cout << t << ' ' << 2 << endl;
    }

    // Если мы можем обойтись переворотом только первого таймера  
    else if (is_found && reset_b == 0 && a * reset_a > b) {
      cout << reset_a << endl;
      cout << 0 << ' ' << 3 << endl;

      //Вертим первый таймер столько, сколько потребно
      for (int t = a; t < a * reset_a; t += a) cout << t << ' ' << 1 << endl;
    } 
      
    // Если впринципе нашли, но это не одно из граничных условий
    else if (is_found) {
      cout << reset_a + reset_b << endl;

      int t = 0; // Сначала вертим первый, потом вертим второй
      for (t; t < reset_a * a; t += a) cout << t << ' ' << 1 << endl;
      for (t; t < reset_a * a + reset_b * b; t += b) cout << t << ' ' << 2 << endl;

    }
    else cout << 0 << endl;
  }

  return 0;
}