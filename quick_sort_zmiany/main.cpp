// pivotem jest losowy element
// C++ implementation QuickSort
// using Lomuto's partition Scheme.
#include <cstdlib>

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and
// places all smaller (smaller than pivot)
// to left of pivot and all greater
// elements to right of pivot
int partition(int arr[], int low, int high, char direction)
{
    // pivot
    int pivot = arr[high];
    cout << "pivot: " << pivot << endl;
    // Index of smaller element
    int i;

    if (direction =='A')
    {   i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {   // If current element is smaller
            // than or equal to pivot
            if (arr[j] <= pivot)
            {   // increment index of
                // smaller element
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
    }
    else
    {   i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {   // If current element is smaller
            // than or equal to pivot
            if (arr[j] >= pivot)
            {   // decrement index of
                // highest element
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
    }
    return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high, char pivot_element, char direction)
{
    // Generate a random number in between
    // low .. high
    //srand(time(NULL));
    //int random = low + rand() % (high - low);
    int random;

    if (pivot_element =='R')
        random = high; // + rand() % (high - low);
    else if (pivot_element =='M')
        random = ceil(high/2); // + rand() % (high - low);
    else if (pivot_element =='L')
        random = low;

    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high, direction);
}

/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void QuickSortUnified(int arr[], int low, int high, char pivot_element, char direction)
{
    if (low < high) {

        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high, pivot_element, direction);

        // Separately sort elements before
        // partition and after partition
        QuickSortUnified(arr, low, pi - 1, pivot_element, direction);
        QuickSortUnified(arr, pi + 1, high, pivot_element, direction);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//-------------------------------------------------------------------------------------------
void quickSort(int *tab, int left, int rigth, int arraySize, char direction, char pivot_element)
{   int temp_array[arraySize];

    if (left < rigth)
    {   for (int i=0; i<arraySize; i++)
		{temp_array[i] = *tab; tab++;	}
		//cout << "p: "<< p <<" r: "<< r <<endl;
        //cout << "QuickSort array before: ";
        //printArray(temp_array, arraySize );
        if (direction =='A')
            {QuickSortUnified (temp_array, left, rigth, pivot_element, direction );  }
        else
            {QuickSortUnified (temp_array, left, rigth, pivot_element, direction ); }

        cout << "QuickSort array after: ";
        printArray(temp_array, arraySize );
    }
    return;
}
// Driver Code
int main()
{
    int arr[] = { 6, 10, 7, 3, 11, 8, 4, 9, 12, 1, 5, 2 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, arr_size - 1, arr_size, 'A', 'R');
    quickSort(arr, 0, arr_size - 1, arr_size, 'A', 'M');
    quickSort(arr, 0, arr_size - 1, arr_size, 'A', 'L');

    printf("Sorted array: ");
    printArray(arr, arr_size);

    quickSort(arr, 0, arr_size - 1, arr_size, 'D', 'R');
    quickSort(arr, 0, arr_size - 1, arr_size, 'D', 'M');
    quickSort(arr, 0, arr_size - 1, arr_size, 'D', 'L');
    return 0;
}
