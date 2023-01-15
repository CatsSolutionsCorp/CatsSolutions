#include <fstream> 

int main() {
	int* a, n, points = 0;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	a = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		char buff;
		fin >> buff;
		if (buff == '+') {
			points += a[i];
		}
	}

	fout << points;

	return 0;
}