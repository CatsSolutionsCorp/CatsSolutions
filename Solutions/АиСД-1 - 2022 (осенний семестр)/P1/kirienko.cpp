#include <fstream>
int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, sum = 0;
    fin >> n;
    int list[n+1];
    list[0] = 0;

    for (int i = 1; i <= n; i++) 
    {
        int x;
        fin >> x;
        list[i] = list[i-1]+x;
    }
    
    int ans[3] = {-1, -1, -1}, dif = 0;
    for (int m = n-1; m >= 1; m--)
    {
        int l = 0, r = n;
        while (l < m and m < r)
        {
            if (list[l] + list[r] == 2 * list[m])
            {
                if (list[m] - list[l] > dif or (list[m] - list[l] == dif and l+1 < ans[0]))
                {
                    ans[0] = l+1, ans[1] = m, ans[2] = r;
                    dif = list[m] - list[l];
                }
                break;
            }
            else if (list[l] + list[r] < 2*list[m]) l++;
            else r--;
        }
    }
    if (ans[0] == -1) fout << -1;
    else fout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

    return 0;
}