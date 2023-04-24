#include <fstream>
#include <vector>

int main()
{
	std::ifstream fin("input.txt");
	
	std::vector<char> pancakes;

	int n;

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		char buff;
		fin >> buff;
		pancakes.push_back(buff);
	}

	char state[] = { 'B', 'W' };
	int want = 0;
	int res = 0;

	for (int i = pancakes.size() - 1; i >= 0; i--)
		if (pancakes[i] == state[want])
		{
			res++;
			want = (want + 1) % 2;
		}

	std::ofstream fout("output.txt");

	fout << res;

	return 0;
}