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

template<typename T>
T *merge_arrays(T *a, int size1, T *b, int size2, bool (*comp)(T&, T&)) {
    int ptr1 = 0, ptr2 = 0;

    int size = size1 + size2;
    T *new_array = new T[size];

    for (int i = 0; i < size; i++) {
        if (ptr2 >= size2 || ptr1 < size1 && comp(a[ptr1], b[ptr2])) {
            new_array[i] = a[ptr1];
            ptr1++;
        } else {
            new_array[i] = b[ptr2];
            ptr2++;
        }
    }
    delete[] a;
    delete[] b;

    return new_array;
}

template<typename T>
T *merge_sort(T *a, int size, bool (*comp)(T&, T&)) {
    if (size == 1)
        return a;

    int size1 = size / 2;
    int size2 = size - size1;
    T *l = new T[size1];
    T *r = new T[size2];

    for (int i = 0; i < size; i++)
        if (i < size / 2)
            l[i] = a[i];
        else
            r[i - size1] = a[i];

    l = merge_sort(l, size1, comp);
    r = merge_sort(r, size2, comp);

    return merge_arrays<T>(l, size1, r, size2, comp);
}

struct Soldier {
    double height;
    std::string name;
};

bool soldier_comp(Soldier *&soldier1, Soldier *&soldier2) {
    return soldier1->height >= soldier2->height;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n;
    input >> n;

    Soldier **soldiers = new Soldier*[n];
    for (int i = 0; i < n; i++) {
        double height;
        std::string name;
        input >> height >> name;
        soldiers[i] = new Soldier{height, name};
    }
    soldiers = merge_sort<Soldier*>(soldiers, n, &soldier_comp);

    for (int i = 0; i < n; i++)
        output << soldiers[i]->name << std::endl;
}
