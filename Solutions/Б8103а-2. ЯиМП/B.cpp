#include <fstream>

int main() {
	int a, b, temp;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> a >> b;

	if (a > b) {
		temp = a;
		a = b;
		b = a;
	}
	if ((a % 2 != 0 && (b - a - 1) % 4 == 2) || (a % 2 == 0 && (b - a - 1) % 4 == 0)) {
		if ((b - a) == 0) {
			fout << 0;
			return 0;
		}

		fout << b - a - 1 + a - 1;

		return 0;
	}
	else {
		fout << 0;
		return 0;
	}
}