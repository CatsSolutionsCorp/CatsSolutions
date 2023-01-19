//Код не для той задачи. Это "Кондиционеры", а не "Ближайшее число"

#include <fstream>

int main()
{
    int n, * a, m, * b, * c, sum = 0;
    std::ifstream fin("cond.in");
    std::ofstream fout("cond.out");
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];

    fin >> m;
    b = new int[m];
    c = new int[m];

    for (int i = 0; i < m; i++)
        fin >> b[i] >> c[i]; 

    for (int i = 0; i < n; i++)
    {
        int min = 1001;
        for (int j = 0; j < m; j++)
            if (a[i] <= b[j] && c[j] < min)
                min = c[j];
        sum += min;
    }

    fout << sum;

    return 0;
}
