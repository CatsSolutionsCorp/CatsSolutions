/**
 **********************************
 * Copyrighted by Derlie Monne *
 **********************************
 *             ХУЙ                *
 *            ВОЙНЕ               *
 **********************************
**/


#include <fstream>


int count_ways(int dog_i, int dogs_count, int food_remain, int food_ate_prev_dog) {
    if (dog_i == dogs_count) {
        return 1;
    }
    int min_food_eat = food_ate_prev_dog;
    int hungry_dogs_count = dogs_count - dog_i + 1;
    int max_food_eat = food_remain / hungry_dogs_count;
    int count = 0;
    for (int food_eat = min_food_eat; food_eat <= max_food_eat; ++food_eat) {
        count += count_ways(dog_i + 1, dogs_count, food_remain - food_eat, food_eat);
    }
    return count;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n >> m;
    output << count_ways(1, n, m, 1);

    return 0;
}