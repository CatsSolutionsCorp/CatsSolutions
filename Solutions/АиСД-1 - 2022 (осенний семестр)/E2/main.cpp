#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

struct Soldier {
    Soldier() = default;
    Soldier(float height, std::string name) {
        this->height = height;
        this->name = name;
    }

    float height;
    std::string name;

    bool operator<(const Soldier &other) const {
        return height < other.height;
    }
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;
    std::vector<Soldier> soldiers;
    for (int i = 0; i < n; ++i) {
        float height;
        std::string name;
        input >> height >> name;
        Soldier soldier(height, name);
        soldiers.push_back(soldier);
    }

    std::stable_sort(soldiers.rbegin(), soldiers.rend());
    for (const Soldier& soldier : soldiers) {
        output << soldier.name << '\n';
    }

    return 0;
}
