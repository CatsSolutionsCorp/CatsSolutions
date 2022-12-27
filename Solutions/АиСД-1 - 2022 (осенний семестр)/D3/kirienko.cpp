#include <fstream>

int gcd(int a, int b){return b==0?a:gcd(b, a%b);}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int a, b;
    fin >> a >> b;
    
    int x = gcd(a, b);
    
    fout << x << ' ' << a*b/x;
    
    return 0;
}