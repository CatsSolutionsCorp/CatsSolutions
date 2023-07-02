#include <bits/stdc++.h>


int main() {
    
    unsigned long long n; 
    int k; 
    std::cin >> n >> k; 

    // Если база системы счисления меньше трех, просто выводим число
    if (k < 3) {
        std::cout << n;
    }
        // Если база системы счисления больше или равна трём, выполняем алгоритм преобразования
    else {
        // Вычисляем максимальную степень k, которая не превосходит n
        int maxDegree = (int) trunc(log2(n) / log2(k));
        
        // Инициализируем счётчик counter значением, соответствующим количеству чисел, не превосходящих n,
        // у которых в разложении по k первый раз встречается цифра, большая 1
        auto counter = (unsigned long long) (2 * pow(2, maxDegree - 1));

        // Если число n равно 1, значение counter также должно быть равно 1
        if (n == 1) {
            counter = 1;
        }

        // Переводим число n из десятичной системы счисления в k-ичную систему счисления
        std::string s;
        while (n > 0) {
            int buff = n % k <= 9 ? n % k : 9;
            s = std::to_string(buff) + s;
            n /= k;
        }

        // Выполняем преобразование полученного числа k-ичной системы счисления
        bool flag = true; 
        int startIndex = -1; 

        for (int i = 0; i < s.length() and flag; i++) {
            // Если цифра больше 1, выполняем преобразование
            if (s[i] > '1') {
                // Если первая цифра больше 1, заменяем ее на 1 и все оставшиеся цифры на 0
                if (i == 0)
                    startIndex = 1;

                // Заменяем все цифры числа, начиная с i-й, на 1
                std::string sub(s.length() - i, '1');
                s.replace(i, s.length() - i, sub);

                // Устанавливаем флаг в false, чтобы прекратить выполнение преобразования
                flag = false;
            }
            // Если цифра больше 0 и индекс первой цифры больше нуля, сохраняем индекс первой цифры
            if (s[i] > '0' and startIndex == -1 and i != 0)
                startIndex = i;
        }

        // Если индекс первой цифры равен -1, значит, все цифры числа равны 0, и выводим значение счётчика
        if (startIndex == -1) {
            std::cout << counter;
        }
            // В противном случае выполняем преобразование в десятичную систему счисления 
            // и увеличиваем значение счётчика на полученное значение
        else {
            char sub[s.length() - startIndex];
            std::strcpy(sub, &s[startIndex]);
            unsigned long long i = std::bitset<std::numeric_limits<unsigned long long>::digits>(sub).to_ullong();
            counter += i;
            std::cout << counter;
        }
    }

    return 0; 
} сборка по степеням