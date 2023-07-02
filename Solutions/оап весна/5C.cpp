#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long n, C, P, T, sumA=0;
    fin >> n >> C >> P >> T;

    long long a[n], b[n];
    long long l = 0,  r, mid, k, const_kc;

    for (long long i = 0; i < n; i++) {
        b[i] = 0;
        fin >> a[i];
        sumA += a[i];
    }
    r = sumA;

    while (l < r) {
        mid = (l + r + 1) / 2;
        long long cM = mid;
        for (long long i = 0; i < n; i++) {
            b[i] = min(a[i], cM);
            cM -= b[i];
        }
        long long pos = n - 1, sumT = 0;
        while (true) {
            while (pos >= 0 && !b[pos])
                pos--;

            if (pos < 0) break;

            k = (b[pos] + C - 1) / C;
            sumT += 2 * k * (pos + 1);
            const_kc = k * C;
            
            while (pos >= 0 && const_kc != 0) {
                if (!b[pos]) pos--;
                long long minf = min(b[pos], const_kc);
                b[pos] -= minf;
                const_kc -= minf;
            }
        }
        if (sumT <= T / P)
            l = mid;
        else
            r = mid - 1;
    }
    fout << l;
    return 0;
} 