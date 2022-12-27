#include <fstream>
#include <iostream>
#include <string>

bool is_win(bool opened[], size_t opened_length) {
    for (size_t i = 0; i < opened_length; ++i) {
        if (!opened[i]) return false;
    }
    return true;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string word, letters, result;
    input >> word >> letters;
    bool opened[word.length()];

    for (int i = 0; i < word.length(); ++i) {
        opened[i] = false;
    }

    for (char letter : letters) {
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == letter) opened[i] = !opened[i];
        }
        if (is_win(opened, word.length())) break;
    }

    result = word;
    for (int i = 0; i < word.length(); ++i) {
        if (!opened[i]) result[i] = '.';
    }

    output << result;
    return 0;
}