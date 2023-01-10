#include <fstream>
#include <iostream>

bool search(int * a2, int * a3, int num, int n2, int n3) {
	
	//поиск по второму массиву
	int low = 0, high = n2 - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (a2[mid] == num) {
			goto thirdArrSearch;
		}

		if (a2[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	
	return false;

thirdArrSearch:

	//поиск по третьему массиву
	low = 0; 
	high = n3 - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (a3[mid] == num) {
			return true;
		}

		if (a3[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	return false;
}

int main() {
	int * a1, * a2, * a3, n1, n2, n3, tripletsCnt = 0, max_n;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> n1 >> n2 >> n3;
	std::cout << n1 << " " << n2 << " " << n3;

	a1 = new int[n1];
	a2 = new int[n2];
	a3 = new int[n3];

	max_n = std::max(std::max(n1, n2), n3);

	for (int i = 0; i < n1; i++) {
		fin >> a1[i];
	}

	for (int i = 0; i < n2; i++) {
		fin >> a2[i];
	}

	for (int i = 0; i < n3; i++) {
		fin >> a3[i];
	}

	if (n1 == max_n) {
		for (int i = 0; i < n1; i++) {
			if (a1[i] > a2[n2 - 1] || a1[i] > a3[n3 - 1]) {
				goto a;
			}
			if (search(a2, a3, a1[i], n2, n3)) {
				tripletsCnt++;
			}

		}

	}
	else if (n2 == max_n) {
		for (int i = 0; i < n2; i++) {
			if (a2[i] > a1[n1 - 1] || a2[i] > a3[n3 - 1]) {
				goto a;
			}
			if (search(a1, a3, a2[i], n1, n3)) {
				tripletsCnt++;
			}

		}
	}
	else if (n3 == max_n) {
		for (int i = 0; i < n3; i++) {
			if (a3[i] > a1[n1 - 1] || a3[i] > a2[n2 - 1]) {
				goto a;
			}
			if (search(a1, a2, a3[i], n1, n2)) {
				tripletsCnt++;
			}
		}
	}
a:

	fout << tripletsCnt;

	return 0;
}