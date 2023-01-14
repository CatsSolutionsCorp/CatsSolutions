/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>
#include <algorithm>

struct Shelter {
    int number, distance;
};

bool shelterComp(Shelter &shelter1, Shelter &shelter2) {
    return shelter1.distance < shelter2.distance;
}

int bin_search(const Shelter *array, int size, int element) {
    int left = 0;
    int right = size - 1;
    int middle = (right + left) / 2;
    while (left != right && array[middle].distance != element) {
        if (array[middle].distance > element) {
            if (middle == left)
                return left - 1;
            right = middle - 1;
        } else if (array[middle].distance < element) {
            if (middle == right)
                return right;
            left = middle + 1;
        }

        middle = (right + left) / 2;
    }

    if (element < array[middle].distance)
        return middle - 1;
    else
        return middle;
}

int main() {
    std::ifstream input("shelter.in");
    std::ofstream output("shelter.out");

    int n, m;

    input >> n;

    int *villages = new int[n];
    for (int i = 0; i < n; i++)
        input >> villages[i];

    input >> m;

    auto *shelters = new Shelter[m];
    for (int i = 0; i < m; i++) {
        int distance;
        input >> distance;
        shelters[i] = {i + 1, distance};
    }

    std::sort(shelters, shelters + m, &shelterComp);

    for (int i = 0; i < n; i++) {
        int left_shelter_ind = bin_search(shelters, m, villages[i]);
        int right_shelter_ind = left_shelter_ind + 1;

        if (left_shelter_ind == -1)
            left_shelter_ind++;

        if (right_shelter_ind == m)
            right_shelter_ind--;

        int left_shelter_dist = std::abs(villages[i] - shelters[left_shelter_ind].distance);
        int right_shelter_dist = std::abs(villages[i] - shelters[right_shelter_ind].distance);

        int answer;
        if (right_shelter_dist < left_shelter_dist)
            answer = shelters[right_shelter_ind].number;
        else
            answer = shelters[left_shelter_ind].number;

        output << answer << ' ';
    }

    return 0;
}
