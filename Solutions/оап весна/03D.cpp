#include <vector>
#include <cstdio>
#include <string>


class HashTable {
private:
    std::vector<std::pair<std::string , int>> table;
public:
    int amount_obj = 0;
    void add(std::string, int);
    int get(int);
    std::string getObj(int);
};


void HashTable::add(std::string key, int value) {
    auto beg = table.begin();
    bool keyExst = false;

    while (beg != table.end()) {
        if (beg->first == key) {
            keyExst = true;
            beg->second += value;
            break;
        }
        beg++;
    }

    if (!keyExst) {
        table.emplace_back(key, value);
        amount_obj++;
    }
}


int HashTable::get(int key) {
    return table[key].second;
}


std::string HashTable::getObj(int key) {
    return table[key].first;
}


int main() {
    FILE *in, *out;
    in = fopen("schools.in", "r");
    out = fopen("schools.out", "w");
    HashTable school_list;
    int count, school_amount = 0;
    
    fscanf(in, "%d", &count);
   
    for (int i = 0; i <= count; i++) {
        char school_name[101];
        fscanf(in, "%*[^0123456789]%100[0123456789]", school_name);

        school_list.add(school_name, 1);
    }

    for (int i = 0 ; i < school_list.amount_obj; i++) {
        if (school_list.get(i) <= 5)school_amount++;
    }

    fprintf(out, "%d\n", school_amount);

    for (int i = 0 ; i < school_list.amount_obj; i++) {
        if (school_list.get(i) <= 5)
            fprintf(out, "%s\n", school_list.getObj(i).c_str());
    }

    return 0;
}
