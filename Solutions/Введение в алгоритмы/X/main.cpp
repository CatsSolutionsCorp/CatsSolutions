/**
 **********************************
 * Copyrighted by Derlie Monne    *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/

// идея решения - бин поиск по ответу

#include <fstream>
#include <iomanip>
#include <cmath>


double get_h(double h_start, double m, double k, double g, double t) {
    return h_start - g * m * t / k + g * m * m / (k * k) * (1 - exp(-k * t / m));
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    double h_start, h_end, m, k;
    input >> h_start >> h_end >> m >> k;
    // km -> m
    h_start *= 1000;
    h_end *= 1000;
    double g = 9.8;

    double tl = 0;
    double tr = 1000000;
    double t = (tl + tr) / 2;
    double h = get_h(h_start, m, k, g, t);
    while (std::abs(h - h_end) > 1e-6) {
        h = get_h(h_start, m, k, g, t);
        if (h > h_end) {
            tl = t;
        }
        else {
            tr = t;
        }
        t = (tl + tr) / 2;
    }
    output << std::fixed << std::setprecision(4) << t;
    return 0;
}
