#include <fstream>
#include <vector>

int main()
{
    int n, * a, * res;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];

    res = new int[n];
    res[n - 1] = a[n - 1];

    std::vector<int> list;

    list.push_back(a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (a[i] >= list[list.size() - 1])
        {
            list.pop_back();
            if (list.size() == 0)
                break;
        }
        list.push_back(a[i]);
        if (list.size() == 1)
            res[i] = a[i];
        else
            res[i] = list[list.size() - 2];
    }

    for (int i = 0; i < n - 1; i++)
        fout << res[i] << " ";
    
    fout << res[n - 1];

    return 0;
}
