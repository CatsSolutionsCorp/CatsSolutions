#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int capacity = 1e7+9;

class HashTable{
private:
    vector<int> v;

public:
    HashTable(int capacity){
        v = vector<int>(capacity);
    }

    int HashFunc(int val)
    {
        return val % capacity;
    }

    int insert(int val){
        if (val > 0){
            int place = HashFunc(val);
            if (v[place] != val)
                v[place] = val;
            return 0;
        }

        else if (val < 0)
        {
            int place_abs = HashFunc(abs(val));
            if (v[place_abs] != 0)
                v[place_abs] = 0;
            return 0;
        }

        else{
            for (auto i: v){
                if (i != 0)
                    fout << i << ' ';
            }
            return 1;
        }
    }
};

int main(){
    int n, result;
    HashTable h(capacity);

    while (fin >> n)
        result = h.insert(n);
        if (result == 1)
            return 0;

    return 0;
}