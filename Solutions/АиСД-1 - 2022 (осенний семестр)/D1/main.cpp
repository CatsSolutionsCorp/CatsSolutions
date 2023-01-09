#include <fstream>
#include <math.h>
#include <tuple>

const double PI = acos(-1);

std::pair<double, double> rotate_point(double x, double y, double radians) {
    double x_rotated = cos(radians) * x - sin(radians) * y;
    double y_rotated = sin(radians) * x + cos(radians) * y;
    return std::make_pair(x_rotated, y_rotated);
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    double xa, ya, xb, yb, x0, y0, degrees;
    input >> xa >> ya >> xb >> yb >> x0 >> y0 >> degrees;

    auto a_norm_rotated = rotate_point(xa - x0, ya - y0, degrees * PI / 180);
    auto b_norm_rotated = rotate_point(xb - x0, yb - y0, degrees * PI / 180);
    double ax_rotated = x0 + a_norm_rotated.first;
    double ay_rotated = y0 + a_norm_rotated.second;
    double bx_rotated = x0 + b_norm_rotated.first;
    double by_rotated = y0 + b_norm_rotated.second;

    output.precision(3);
    output << std::fixed << ax_rotated << ' '
           << std::fixed << ay_rotated << ' '
           << std::fixed << bx_rotated << ' '
           << std::fixed << by_rotated;

    return 0;
}
