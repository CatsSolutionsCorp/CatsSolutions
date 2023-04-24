#include <vector>
#include <fstream>

void IntSwap(int* a, int* b)
{
	int buff;
	buff = *a;
	*a = *b;
	*b = buff;
}

class Heap
{
	std::vector<int*> _data;

	bool Comp(int* a, int* b)
	{
		if (*a != *b) return *a < *b;
		else return a < b;
	}

	void BuildHeap(int index)
	{
		if (index >= _data.size()) return;

		BuildHeap(index * 2 + 1);
		BuildHeap(index * 2 + 2);
		SiftDown(index);
	}

public:

	Heap(std::vector<int*> data)
	{
		_data = data;
		BuildHeap(0);
	}

	~Heap() { _data.~vector(); }

	void SiftDown(int index)
	{
		int swapInd = index;
		for (int i = 1; i <= 2; i++)
			if (_data.size() > index * 2 + i)
				if (Comp(_data[index * 2 + i], _data[swapInd])) swapInd = index * 2 + i;

		if (swapInd == index) return;

		std::swap(_data[index], _data[swapInd]);
		SiftDown(swapInd);

		return;
	}

	void SiftUp(int index)
	{
		if (!index) return;

		if (Comp(_data[index], _data[(index - 1) / 2]))
		{
			std::swap(_data[index], _data[(index - 1) / 2]);
			SiftUp((index - 1) / 2);
		}
	}

	int* Peek() { return _data[0]; }

	int* Pop()
	{
		int* res = _data[0];
		std::swap(_data[0], _data[_data.size() - 1]);
		_data.pop_back();
		SiftDown(0);
		return res;
	}

	void Push(int* elem)
	{
		_data.push_back(elem);
		SiftUp(_data.size() - 1);
	}

	bool Empty() { return !_data.size(); }

	int Size() { return _data.size(); }
};


int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int len, operations;
	int* arr;
	std::vector<int*> for_heap;

	fin >> len >> operations;
	arr = new int[len + operations];

	for (int i = 0; i < len; i++)
	{
		fin >> arr[i];
		for_heap.push_back(arr + i);
	}

	Heap min_heap = Heap(for_heap);

	for (int i = len; i < operations + len; i++)
	{
		int *ptr1 = min_heap.Pop(), 
			*ptr2 = min_heap.Pop();

		arr[i] = *ptr1 + *ptr2;
		min_heap.Push(arr + i);

		*ptr1 = 100000;
		*ptr2 = 100000;
	}

	for (int i = 0; i < operations + len; i++)
		if (arr[i] != 100000)
			fout << arr[i] << ' ';
}