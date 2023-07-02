#include <fstream>


void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;


    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }


    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}


int main(){
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");


    int time_extr;
    int air_count;


    fin >> air_count >> time_extr;
    int array[air_count];
   
    for(int i = 0 ; i < air_count; i++)
        fin >> array[i];
   
    quickSort(array, 0, air_count-1);


    int counter = 0;


    for(int i = 0 ; i < air_count; i++)
    {
        if (counter < array[i])
            counter = array[i];


        counter+=time_extr;
    }
    fout << counter;
}