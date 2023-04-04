#include <fstream>

const int table_size = 5000000;

struct elem
{
    int key;
    int val;
};

void hash_table()
{
    int *elements = new int;
}

int hash_func(int key)
{
    return key % table_size;
}

int get(int key)
{
    return 
}

void add(int key, int val)
{
    for (int i=0; !(hash_table[hash_func(key+i) == -1
         or ]))
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");


}