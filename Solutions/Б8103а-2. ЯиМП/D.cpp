#include <iostream>
#include <string>

int main() {
	int n, word = 1, firstI_ofWord;
	bool exitCond = false;
	std::string line;
	std::getline(std::cin, line);
	std::cin >> n;
	
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			word++;
			firstI_ofWord = i;
		}
		else if (word == n)
		{
			std::cout << line[i];
		}
		if (word > n) {
			exitCond = true;
			break;
		}
	}
	
	if (exitCond == false) {
		for (int i = firstI_ofWord; i < line.size(); i++) {
			std::cout << line[i];
		}
	}

	return 0;
}