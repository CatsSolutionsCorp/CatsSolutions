#include <fstream>


class Heap 
{
private:
    const static int MAX_SIZE = 500000;
    int Heap_arr[MAX_SIZE], size;

public:
    Heap() {
        size = 0;
    }

    int parent(int), Left_child(int), Right_child(int);

    int Delete(), ShowSize(), ShowMainParent();

    void insert(int), sort(int), swap(int *, int *);
};


int Heap::parent(int i) {
    return (i - 1) / 2;
}


int Heap::Left_child(int i) {
    return (i * 2) + 1;
}


int Heap::Right_child(int i) {
    return (i * 2) + 2;
}


int Heap::Delete() {
    int max = Heap_arr[0];

    Heap_arr[0] = Heap_arr[size - 1];
    size--;

    sort(0);

    return max;
}


void Heap::swap(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
}


void Heap::sort(int i) {
    int left, right, largest, temp;

    left = Heap::Left_child(i);
    right = Heap::Right_child(i);
    largest = i;

    if (left <= size && Heap_arr[left] > Heap_arr[largest]) largest = left;

    if (right <= size && Heap_arr[right] > Heap_arr[largest]) largest = right;

    if (largest != i) {
        temp = Heap_arr[i];
        Heap_arr[i] = Heap_arr[largest];
        Heap_arr[largest] = temp;

        sort(largest);
    }
}


void Heap::insert(int num) {
    Heap_arr[size] = num;
    int i = size;
    size++;

    while (i != 0 && Heap_arr[Heap::parent(i)] < Heap_arr[i]) {
        Heap::swap(&Heap_arr[Heap::parent(i)], &Heap_arr[i]);
        i = Heap::parent(i);
    }
}


int Heap::ShowSize() {
    return size;
}


int Heap::ShowMainParent() {
    return Heap_arr[0];
}


int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, num, min;
    Heap Max_Heap, Min_Heap;

    fin >> n;

    while (fin >> num) 
    {
        if (Min_Heap.ShowSize() != 0) 
        {
            min = -Min_Heap.ShowMainParent();

            if (num > min)
                Min_Heap.insert(-num);

            else
                Max_Heap.insert(num);
        } 
        else
            Max_Heap.insert(num);

        while (Min_Heap.ShowSize() > Max_Heap.ShowSize())
            Max_Heap.insert(-Min_Heap.Delete());

        while (Min_Heap.ShowSize() + 1 < Max_Heap.ShowSize())
            Min_Heap.insert(-Max_Heap.Delete());

        fout << Max_Heap.ShowMainParent() << " ";
    }

    return 0;
}