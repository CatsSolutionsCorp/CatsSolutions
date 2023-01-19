/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>
#include <cmath>

const double g = 9.8;

double degrees_to_radians(double degrees) {
    return degrees * std::acos(-1) / 180;
}

double get_y(double m, double v0y, double k, double t) {
    if (k == 0) {
        return v0y * t - g * t*t / 2;
    }
    return (m / k) * ((v0y + m*g/k) * (1 - exp(-k*t/m)) - g*t);
}

double get_x(double m, double v0x, double k, double t) {
    if (k == 0) {
        return v0x * t;
    }
    return (v0x * m / k) * (1 - exp(-k*t/m));
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    double m, v0, degrees, k;
    input >> m >> v0 >> degrees >> k;

    double dt = 0.0001;
    double radians = degrees_to_radians(degrees);
    double v0x = v0 * std::cos(radians);
    double v0y = v0 * std::sin(radians);
    double t = dt;
    while (true) {
        double y = get_y(m, v0y, k, t);
        // skip if body is going up
        if (y <= 0) {
            double distance = get_x(m, v0x, k, t);
            output << t << ' ' << distance;
            return 0;
        }
        t += dt;
    }
}