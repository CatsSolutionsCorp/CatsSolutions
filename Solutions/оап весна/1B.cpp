#include <fstream>
#include <iostream>

unsigned long long count = 0;

struct Soldier
{
	double height;
	std::string name;
};

void merge(Soldier *array, int const left, int const mid, int const right)
{
	int left_size = mid - left + 1;
	int right_size = right - mid;

	Soldier left_array[left_size];
	for (int i = 0; i < left_size; i++)
		left_array[i] = array[left + i];

	Soldier right_array[right_size];
	for (int j = 0; j < right_size; j++)
		right_array[j] = array[mid + 1 + j];

	int l = 0, r = 0, k = left;

	while (l < left_size and r < right_size)
		if (left_array[l].height >= right_array[r].height)
			array[k++] = left_array[l++];
		else
		{
			array[k++] = right_array[r++];
			count += left_size - l;
		}

	while (l < left_size)
		array[k++] = left_array[l++];
	while (r < right_size)
		array[k++] = right_array[r++];
}

void merge_sort(Soldier *array, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	merge_sort(array, begin, mid);
	merge_sort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n;
	fin >> n;

	Soldier blank[n];
	for (int i = 0; i < n; i++)
		fin >> blank[i].height >> blank[i].name;

	merge_sort(blank, 0, n-1);

	fout << count;
	return 0;
}