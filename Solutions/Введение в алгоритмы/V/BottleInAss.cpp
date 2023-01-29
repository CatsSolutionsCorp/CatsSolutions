#include <fstream>

void merge(int array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int* leftArray = new int[subArrayOne], * rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0, indexOfMergedArray = left; 


    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return; 

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    int n, m, * a, sips = 0, i; 
    long long sum = 0;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> n >> m;
    a = new int[n];

    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    while (sips < m) {
        mergeSort(a, 0, n - 1);
        if (a[n - 1] == 0) {
            break;
        }
        sips++;
        a[n - 1] /= 10;
        i = n - 2;
        while (i >= 0 && a[i] > a[n - 1] && sips < m) {
            sips++;
            a[i] /= 10;
            i--;
        }
    }

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    fout << sum;

    return 0;
}