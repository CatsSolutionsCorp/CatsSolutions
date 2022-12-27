#include <fstream>

double square(double a) {
    return a * a;
}

double dist_squared(int x0, int y0, int x1, int y1) {
    return square(x1 - x0) + square(y1 - y0);
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int x1, y1, x2, y2, x, y;
    input >> x1 >> y1 >> x2 >> y2 >> x >> y;

    double x_center = std::min(x1, x2) + 0.5 * abs(x1 - x2);
    double y_center = std::min(y1, y2) + 0.5 * abs(y1 - y2);

    double dist_to_center_squared = square(x_center - x) + square(y_center - y);
    double dists_to_corners_squared[4] = {dist_squared(x1, y1, x, y),
                                 dist_squared(x2, y1, x, y),
                                 dist_squared(x1, y2, x, y),
                                 dist_squared(x2, y2, x, y)};
    double min_dist_to_corner_squared = dists_to_corners_squared[0];
    for (int i = 1; i < 4; ++i) {
        if (dists_to_corners_squared[i] < min_dist_to_corner_squared)
            min_dist_to_corner_squared = dists_to_corners_squared[i];
    }

    output << (min_dist_to_corner_squared < dist_to_center_squared ? "CORNER" : "CENTER");


    return 0;
}
