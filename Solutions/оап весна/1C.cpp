#include <fstream>
#include <vector>
#include <iostream>

struct Value
{
	int value;
	size_t number;

	Value(int value = 0, size_t number = 0)
	{
		this->value = value;
		this->number = number;
	}
};

struct Tree
{
	std::vector<Value> values;
	std::vector<size_t> value_index_by_number;

	Tree()
	{
		values = {Value()};
		value_index_by_number = {0};
	}

	int get_value_by_number(size_t number)
	{
		size_t value_index = value_index_by_number[number];
		return values[value_index].value;
	}

	void add(int value)
	{
		size_t value_number = value_index_by_number.size();
		values.push_back(Value(value, value_number));
		value_index_by_number.push_back(value_number);
		sift_up(values.size() - 1);
	}

	int get_max_value()
	{
		if (values.size() < 2)
			throw std::exception();
		return values[1].value;
	}

	void change_value_at_number(size_t number, int new_value)
	{
		if (number < 1 or number >= value_index_by_number.size())
			throw std::exception();

		size_t value_index = value_index_by_number[number];
		if (value_index < 1 or value_index >= values.size())
			throw std::exception();

		values[value_index] = Value(new_value, number);

		sift_down(value_index);
		sift_up(value_index);
	}

	void swap_and_update_value_number_to_value_index(size_t index_of_a, size_t index_of_b)
	{
		if (index_of_a < 1 or index_of_a >= values.size() or index_of_b < 1 or index_of_b >= values.size())
		{
			throw std::out_of_range("");
		}

		std::swap(values[index_of_a], values[index_of_b]);
		value_index_by_number[values[index_of_a].number] = index_of_a;
		value_index_by_number[values[index_of_b].number] = index_of_b;
	}

	void sift_up(size_t index)
	{
		size_t i = index;
		while (true)
		{
			if (i == 1)
				break;

			if (i >= values.size())
				return;
			Value value = values[i];

			size_t parent_i = i / 2;
			if (parent_i < 1)
				break;
			Value parent = values[parent_i];

			if (parent.value < value.value)
			{
				swap_and_update_value_number_to_value_index(i, parent_i);
				i = parent_i;
			}
			else
			{
				break;
			}
		}
	}

	void sift_down(size_t index)
	{
		size_t i = index;
		while (true)
		{
			if (i < 1 or i >= values.size())
				return;
			Value value = values[i];

			size_t left_child_i = i * 2;
			bool left_child_exists = left_child_i >= 1 and left_child_i < values.size();

			size_t right_child_i = i * 2 + 1;
			bool right_child_exists = right_child_i >= 1 and right_child_i < values.size();

			int swap = -1;

			if (left_child_exists and values[left_child_i].value > value.value and
				right_child_exists and values[right_child_i].value > value.value)
			{
				if (values[left_child_i].value >= values[right_child_i].value)
				{
					swap = 0;
				}
				else
				{
					swap = 1;
				}
			}
			else if (left_child_exists and values[left_child_i].value > value.value)
			{
				swap = 0;
			}
			else if (right_child_exists and values[right_child_i].value > value.value)
			{
				swap = 1;
			}

			if (swap == 0)
			{
				swap_and_update_value_number_to_value_index(i, left_child_i);
				i = left_child_i;
				continue;
			}
			else if (swap == 1)
			{
				swap_and_update_value_number_to_value_index(i, right_child_i);
				i = right_child_i;
				continue;
			}
			return;
		}
	}
};

int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n, m;
	fin >> n >> m;

	Tree tree;

	for (size_t i = 1; i <= n; ++i)
	{
		int a;
		fin >> a;
		tree.add(a);
	}

	for (size_t i = 0; i < m; ++i)
	{
		int num, val;
		fin >> num >> val;

		tree.change_value_at_number(num, tree.get_value_by_number(num) + val);

		int max = tree.get_max_value();
		fout << max << '\n';
	}
}