#include <fstream>

int partition(int * arr, int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int * arr, int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

int main() {
	int n, * a;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> n;
    a = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }

	return 0;
}