#include <fstream>
#include <cmath>
int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, x, n1;
    fin >> n;

    for (int i = 0; i < pow(2, n); i++)
    {
        char bin[n];
        x = i;
        n1 = n - 1;

        for (int i1 = 0; i1 < n; i1++)
        {
            bin[i1] = '0';
        }

        while (x != 0)
        {
            if (x % 2){
                bin[n1] = '1';
            }
            x /= 2;
            n1 -= 1;
        }

        for (int i1 = 0; i1 < n; i1++)
        {
            fout << bin[i1];
        }
        
        fout << std::endl;
    }
}