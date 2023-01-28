#include <fstream>
#include <iostream>

int main() {
	int n, points = 4, diff = 2, pointsDiff = 1;
	bool firstRun = true;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> n;

	if (n < 4) {
		fout << n;
		return 0;
	}
	else if (n == 4) {
		fout << 3;
		return 0;
	}
	else if (n == 5) {
		fout << 4;
		return 0;
	}

	for (int currStep = 6; currStep <= n;) {
		currStep += diff;

		if (currStep > n) {
			break;
		}

		points++;
		pointsDiff++;

		if (pointsDiff == 2) {
			diff++;
			pointsDiff = 0;
		}

	}

	fout << points;

	return 0;
}