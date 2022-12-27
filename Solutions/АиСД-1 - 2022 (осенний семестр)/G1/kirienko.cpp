#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n, m, l = 0, r = 0;
    fin >> n;
    int* list = new int[n];
    char step;
    
    for (int i = 0; i < n; i++) fin >> list[i];
    fin >> m;
    
    int mx = list[0], c = 1;
    for (int i = 0; i < m; i++)
    {
        fin >> step;
        if (step == 'R')
        {
            r++;
            if (list[r] > mx) { mx = list[r]; c = 1; }
            else if (list[r] == mx) c++;
        }
        else if (step == 'L')
        {
            l++;
            if (list[l-1] == mx)
            {
                if (c > 1) c--;
                else if (c == 1)
                {
                    mx = list[l];
                    for (int j = l+1; j <= r; j++)
                    {
                        if (list[j] > mx) { mx = list[j]; c = 1; }
                    }
                    c = 1;
                }
            }
        }
        fout << mx << ' ';
    }
    return 0;
}