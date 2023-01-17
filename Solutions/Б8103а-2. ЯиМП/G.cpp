#include <fstream>

int main()
{
    const int len = 101;
    int b[len] = {}, n, * x, * y, max = 0;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> n;
    x = new int[n];
    y = new int[n];

    for (int i = 0; i < n; i++)
    {
        fin >> x[i] >> y[i];
        b[x[i]]++;
        for (int j = 1; j <= y[i]; j++)
        {
            if (x[i] - j >= 0)
                b[x[i] - j]++;
            if (x[i] + j < len && j < y[i])
                b[x[i] + j]++;
        }
    }

    for (int i = 0; i < len; i++)
        if (max < b[i])
            max = b[i];

    fout << max;

    return 0;
}