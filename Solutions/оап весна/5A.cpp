#include <fstream>
#include <vector>

int main() 
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    std::vector<char> arr;
    int n, count = 0;

    fin >> n;

    for (int i = 0; i < n; i++) 
    {
        char temp;
        
        fin >> temp;
        
        arr.push_back(temp);
    }

    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            count++;

    if(arr[n - 1] == 'B')
        count++;

    fout << count;

    return 0;
}