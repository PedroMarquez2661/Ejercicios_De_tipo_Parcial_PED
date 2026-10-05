#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n ){
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[minIdx])
            {
                minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
        
    }
    
}