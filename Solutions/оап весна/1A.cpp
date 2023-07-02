#include <fstream>

int main() 
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string word;
    input >> word;

    bool answer = true;
    for (int i = 1; i < word.length(); i++)
        if (word[i - 1] < 91 and word[i] > 91) {
            answer = false;
            break;
        }

    if (answer)
        output << "YES";
    else
        output << "NO";
    output.close();
    return 0;
}