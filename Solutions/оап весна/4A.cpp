#include <iostream>

void swap(int *a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}

void func(int *a, int n)
{
    int j = n-2, k = n-1;
    while (j != -1 and a[j] >= a[j+1]) 
		j--;

    if (j == -1)
		return;

    while (a[j] >= a[k]) 
		k--;
    swap(a, j, k);

    int l = j + 1, r = n - 1; 
    while (l<r)
    	swap(a, l++, r--);

	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << '\n';

    return func(a, n);
}

int main() 
{
	int n, *a;
	std::cin >> n;
	a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		std::cout << a[i] << " ";
	}
	std::cout << '\n';

	func(a, n);

	return 0;
}