#include <fstream>
#include <iostream>


int main() {
    std::ifstream input("input.txt");

    int hours, minutes;
    input >> hours >> minutes;
    int minutes_total = 60 * hours + minutes;
    int new_year_minutes_total = 24 * 60;
    int delta_minutes_total = new_year_minutes_total - minutes_total;
    int delta_hours = delta_minutes_total / 60;
    int delta_minutes = delta_minutes_total - 60 * delta_hours;

    std::ofstream output("output.txt");
    output << delta_hours << " " << delta_minutes << std::endl;
}