#include <fstream>
#include <algorithm>
#include <vector>

static const int ONE_REGISTER_LETTERS_COUNT = 26;
static const int TWO_REGISTERS_LETTERS_COUNT = ONE_REGISTER_LETTERS_COUNT * 2;
static const long BUCKETS_COUNT = TWO_REGISTERS_LETTERS_COUNT * TWO_REGISTERS_LETTERS_COUNT * TWO_REGISTERS_LETTERS_COUNT;

struct BucketWord {
    int word_i;
    int words_count;
};

int char_to_index(char c) {
    bool assertion = c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z';
    if (not assertion) {
        throw std::exception();
    }
    if (c < 'a') return (c - 'A');
    return (c - 'a') + ONE_REGISTER_LETTERS_COUNT;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    long n;
    fin >> n;

    std::vector<std::string> words;
    for (long i = 0; i < n; ++i) {
        std::string word;
        fin >> word;
        for (char &c : word) {
            bool isLetter = c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z';
            if (not isLetter) {
                throw std::exception();
            }
        }
        words.push_back(word);
    }

    BucketWord buckets[BUCKETS_COUNT];
    for (auto & bucket : buckets) {
        bucket = BucketWord {.word_i = -1, .words_count = 0};
    }


    for (long word_i = 0; word_i < n; ++word_i) {
        std::string word = words[word_i];
        int letter1 = char_to_index(word[0]);
        int letter2 = char_to_index(word[1]);
        int letter3 = char_to_index(word[2]);
        int bucket_i =
                letter1 * TWO_REGISTERS_LETTERS_COUNT * TWO_REGISTERS_LETTERS_COUNT +
                letter2 * TWO_REGISTERS_LETTERS_COUNT +
                letter3;
        if (bucket_i < 0 or bucket_i >= BUCKETS_COUNT) throw std::exception();
        buckets[bucket_i].word_i = word_i;
        buckets[bucket_i].words_count++;
    }

    for (auto & bucket : buckets) {
        if (bucket.word_i < -1) throw std::exception();
        if (bucket.word_i != -1) {
            for (int j = 0; j < bucket.words_count; ++j) {
                fout << words[bucket.word_i] << '\n';
            }
        }
    }

    return 0;
}