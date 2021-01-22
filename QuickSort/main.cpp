// C++ program for implementation of selection sort
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

//-------------------------------------------------------------------------------------------
// Function to print an array
//-------------------------------------------------------------------------------------------
void printArray(int *array,int arraySize)
{ 	int i;
	for (i=0; i < arraySize; i++)
		cout << array[i] << " ";
	cout << endl;
}

void swap(int *xp, int *yp)
{ 	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//-------------------------------------------------------------------------------------------
// merge sort
//-------------------------------------------------------------------------------------------
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeAsc(int *arr, int left, int m, int right)
{
//    int arraySize = sizeof(arr)/sizeof(arr[0]);
    int n1 = m - left + 1;
    int n2 = right - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = left;

    while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
        else {
                arr[k] = R[j];
                j++;
            }
        k++;
        usleep(1);
    }
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        usleep(1);
    }
}
//-------------------------------------------------------------------------------------------
void MergeDesc(int *arr, int low, int mid, int high )
{	int i=low,j=mid+1,k=0;
	int temp[high-low+1];

	while(i<=mid && j<= high)
	{	if(arr[i]>arr[j])               //comparison step
	    {
	        temp[k++]=arr[i++];
	    }
	    else
        {
            temp[k++]=arr[j++];
        }
    usleep(1);
	}
	while(i<=mid)
	    {
	        temp[k++]=arr[i++];
            usleep(1);
	    }
	while(j<=high)
	    {
	        temp[k++]=arr[j++];
            usleep(1);
	    }
	for(i=low;i<=high;i++)
	{
	    arr[i]=temp[i-low];
        usleep(1);
	}
	return;
}
//-------------------------------------------------------------------------------------------
// left is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void MergeSort(int *arr ,int left,int right, char direction)
{
    if(left>=right)
	{	return;//returns recursively
    }

    int mid = left+(right-left)/2;
    if (direction == 'A')
    {	MergeSort(arr,left,mid,'A');
	    MergeSort(arr,mid+1,right,'A');
	    MergeAsc(arr,left,mid,right);
	}
	else
    {	MergeSort(arr,left,mid,'D');
	    MergeSort(arr,mid+1,right,'D');
	    MergeDesc(arr,left,mid,right);
	}
}

void MergeSortArray(int *local_arr, int localarraySize, char direction, char partsort)
{
	int temp_array[localarraySize];
	int i, start_with;
	int temp_part_arraySize = localarraySize/5;
	int temp_part_array[temp_part_arraySize];
	double elapsed_seconds;
	time_t start_petla = time(0);
	time_t stop_petla = time(0);

	cout << "MergeSort temporary size : "<<sizeof(temp_array)/sizeof(temp_array[0]) <<endl;

	if (direction == 'A' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = *local_arr; local_arr++;	}

		MergeSort(temp_array, 0, localarraySize-1,'A');
		cout << "MergeSort array size : "<<localarraySize <<endl;
		//cout << "MergeSort array: ";
		//printArray(temp_array, localarraySize );
	}
	else if (direction == 'D' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = *local_arr; local_arr++;	}

		MergeSort(temp_array, 0, localarraySize-1,'D');
		cout << "MergeSort array size : "<<localarraySize <<endl;
		//cout << "MergeSort array: ";
		//printArray(temp_array, localarraySize );
	}
    else if (direction == 'A' && partsort =='Y')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "Selection sort start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

				//	cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = local_arr[start_with]; start_with++; }
                    std::cout << "zaczynam od : "<< start_with << " elementu tj :" << temp_array[start_with]<< std::endl;

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,'A');
                    cout << "MergeSort array size : "<<localarraySize <<endl;

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "Selection sort end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
			//cout << "MergeSort array: ";
			//printArray(temp_part_array, temp_part_arraySize );
		}
	}
    else if (direction == 'D' && partsort =='Y')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "Selection sort start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

					cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = local_arr[start_with]; start_with++; }

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,'D');
                    cout << "MergeSort array size : "<<localarraySize <<endl;

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "Selection sort end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
			//cout << "MergeSort array: ";
			//printArray(temp_part_array, temp_part_arraySize );
	    }
	}
}
//-------------------------------------------------------------------------------------------
int partition(int *arr, int low, int high, char direction)
{
    // pivot
    int pivot = arr[high];
    //cout << "pivot: " << pivot << endl;
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
                usleep(1);
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
                usleep(1);
            }
        }
        swap(arr[i + 1], arr[high]);
    }
    return (i + 1);
}
//-------------------------------------------------------------------------------------------
// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int *arr, int low, int high, char pivot_element, char direction)
{   // Generate a random number in between
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
//-------------------------------------------------------------------------------------------
void QuickSortUnified(int *arr, int low, int high, char pivot_element, char direction)
{
    if (low < high) {

        int pi = partition_r(arr, low, high, pivot_element, direction);

        // Separately sort elements before
        // partition and after partition
        QuickSortUnified(arr, low, pi - 1, pivot_element, direction);
        QuickSortUnified(arr, pi + 1, high, pivot_element, direction);
    }
}
//-------------------------------------------------------------------------------------------
void QuickSort(int *tab, int left, int rigth, int arraySize, char direction, char pivot_element)
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

        //cout << "QuickSort array after: ";
        //printArray(temp_array, arraySize );
    }
    return;
}
//-------------------------------------------------------------------------------------------
void PartQuickSort(int *tab, int arraySize, char direction)
{
	int i, start_with;
	int temp_part_arraySize = ceil(arraySize/5);
	int temp_part_array[temp_part_arraySize];
	double elapsed_seconds;
	time_t start_petla = time(0);
	time_t stop_petla = time(0);

//    for (int i=0; i<arraySize; i++)
//    {temp_array[i] = *tab; tab++;	}
//    cout << "p: "<< p <<" r: "<< r <<endl;
//    cout << "QuickSort array before: ";
//    printArray(temp_array, arraySize );
//    if (direction =='A')
//        {QuickSortUnified (temp_array, p, r ,'A');  }
//    else
//        {QuickSortUnified (temp_array, p, r ,'D' ); }

    if (direction == 'A')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "PartQuickSort start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

				//	cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = tab[start_with]; start_with++; }

                    QuickSortUnified (temp_part_array, 0, temp_part_arraySize ,'R', 'A');

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "PartQuickSort end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
		}
	}
    else if (direction == 'D')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "PartQuickSort start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

					cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = tab[start_with]; start_with++; }

                    QuickSortUnified (temp_part_array, 0, temp_part_arraySize, 'R', 'D');

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "PartQuickSort end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
	    }
	}
    //cout << "PartQuickSort array after: ";
    //printArray(temp_part_array, temp_part_arraySize );
    return;
}

//-------------------------------------------------------------------------------------------
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int *arr, int n, int i, char direction)
{
    int largest = i; // Initialize largest as root
    int smallest = i; // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (direction =='A')
    {   // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
        // If largest is not root
        if (largest != i)
        {   swap(arr[i], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest,direction);
            usleep(1);
        }
    }
    else
    {   // If left child is smaller than root
        if (l < n && arr[l] < arr[smallest])
            smallest = l;

        // If right child is smaller than smallest so far
        if (r < n && arr[r] < arr[smallest])
            smallest = r;
        // If smallest is not root
        if (smallest != i)
        {   swap(arr[i], arr[smallest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, smallest,direction);
            usleep(1);
        }
    }
}

// main function to do heap sort
void heapSort(int *arr, int n, char direction)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i,direction);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {   // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0,direction);
    }
    //cout << "heapSort array after: ";
    //printArray(arr, n );
}
//-------------------------------------------------------------------------------------------
void PartHeapSort(int *tab, int arraySize, char direction)
{
	int i, start_with;
	int temp_part_arraySize = arraySize/5;
	int temp_part_array[temp_part_arraySize];
	double elapsed_seconds;
	time_t start_petla = time(0);
	time_t stop_petla = time(0);

//    for (int i=0; i<arraySize; i++)
//    {temp_array[i] = *tab; tab++;	}
//    cout << "p: "<< p <<" r: "<< r <<endl;
//    cout << "QuickSort array before: ";
//    printArray(temp_array, arraySize );
//    if (direction =='A')
//        {QuickSortUnified (temp_array, p, r ,'A');  }
//    else
//        {QuickSortUnified (temp_array, p, r ,'D' ); }

    if (direction == 'A')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "HeapSort Asc start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

				//	cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = tab[start_with]; start_with++; }

                    heapSort (temp_part_array, temp_part_arraySize ,'A');

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "HeapSort Asc end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
		}
	}
    else if (direction == 'D')
    {
		int odcinek_pom =0, petla =0;
		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
				std::cout << "HeapSort Desc start: " << std::ctime(&start_petla) << std::endl;

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

					cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = tab[start_with]; start_with++; }

                    heapSort (temp_part_array, temp_part_arraySize, 'D');

				stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
			    std::cout << "HeapSort Desc end: " << std::ctime(&stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
			}
	    }
	}
    cout << "HeapSort array after: ";
    printArray(temp_part_array, temp_part_arraySize );
    return;
}
//-------------------------------------------------------------------------------------------
// main program
int main()
{ 	char v_znak;
	int total_numbers =160000;
	int main_arr[total_numbers];

	//int total_numbers =10;
	//int main_arr[total_numbers] = { 315,309,306,313,358,325,323,321,115,9};
	/*,
                                    389,211,1  ,18 ,69 ,169,7  ,114,118,269,
                                    6  ,13 ,58 ,25 ,23 ,21 ,512,302,307,301,
                                    308,322,342,338,412,2  ,7  ,10 ,8  ,22,
                                    41 ,25 ,363,326,371,344,339,348,319,316,
                                    469,487,468,415,401,408,480,471,467,462,
                                    62 ,24 ,72 ,34 ,19 ,18 ,119,116,329,356,
                                    312,320,317,311,328,341,123,121,112,110,
                                    120,117,111,128,141,325,362,358,324,500,
                                    372,334,314,318,125,162,158,124,172,134
                                    };*/
	cout <<"Program start\n";

	int arraySize = sizeof(main_arr)/sizeof(main_arr[0]);
	time_t start_sort = time(0);
	time_t stop_sort = time(0);
	double elapsed_seconds; // = stop_sort-start_sort;

	for (int i=0; i<total_numbers; i++)
	{
	    main_arr[i] = rand() % 500000 + 100;
	    //cout << main_arr[i] << " ";
	}

	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout <<"********************* MENU *********************"	<< endl;
		cout << "1. MergeSort ASC calego zbioru		"	<< endl;
		cout << "2. MergeSort DESC calego zbioru	"	<< endl;
		cout << "3. QuickSort ASC pivot = 0	        "	<< endl;
		cout << "4. QuickSort DESC pivot = 0	    "	<< endl;
		cout << "5. QuickSort ASC pivot = middle    "	<< endl;
		cout << "6. QuickSort DESC pivot = middle   "	<< endl;
		cout << "7. QuickSort ASC pivot = last      "	<< endl;
		cout << "8. QuickSort DESC pivot = last     "	<< endl;
		cout << "9. HeapSort ASC calego zbioru	    "	<< endl;
		cout << "0. HeapSort DESC calego zbioru	    "	<< endl;
        cout << "-----------------------------------"	<< endl;
		cout << "A. PartMergeSort ASC				"	<< endl;
		cout << "B. PartMergeSort DESC				"	<< endl;
		cout << "C. Part QuickSort ASC				"	<< endl;
		cout << "D. Part QuickSort DESC				"	<< endl;
		cout << "E. Part HeapSort ASC				"	<< endl;
		cout << "F. Part HeapSort DESC				"	<< endl;
		cout<<"Wybieram : ";

		v_znak = getchar();
		switch (v_znak)
		{   case '1':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "MergeSort ASC start: " << std::ctime(&start_sort) << std::endl;

						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						MergeSortArray(main_arr, arraySize,'A','N');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "MergeSort ASC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '2':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "MergeSort DESC start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						MergeSortArray(main_arr, arraySize,'D','N');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "MergeSort DESC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '3':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort Asc start: " << std::ctime(&start_sort) << std::endl;

						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'A', 'L'); // wywolanie funkcji sortujacej - pivotem jest pierwszy element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
            case '4':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort DESC start: " << std::ctime(&start_sort) << std::endl;

						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'D', 'L'); // wywolanie funkcji sortujacej - pivotem jest pierwszy element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort DESC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '5':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort Asc start: " << std::ctime(&start_sort) << std::endl;

						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'A', 'M'); // wywolanie funkcji sortujacej - pivotem jest srodkowy element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
            case '6':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort DESC start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'D', 'M'); // wywolanie funkcji sortujacej - pivotem jest srodkowy element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort DESC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '7':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort Asc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'A', 'R'); // wywolanie funkcji sortujacej - pivotem jest ostatni element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
            case '8':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "QuikSort DESC start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						QuickSort(main_arr, 0, arraySize - 1, arraySize, 'D', 'R'); // wywolanie funkcji sortujacej - pivotem jest ostatni element

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "QuikSort DESC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
            case '9':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "HeapSort Asc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						heapSort(main_arr,arraySize,'A'); // wywolanie funkcji sortujacej

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "HeapSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
            case '0':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "HeapSort Desc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						heapSort(main_arr,arraySize,'D'); // wywolanie funkcji sortujacej

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "HeapSort Desc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'A':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part MergeSort Asc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						MergeSortArray(main_arr, arraySize,'A','Y');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part MergeSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'B':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part MergeSort Desc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						MergeSortArray(main_arr, arraySize,'D','Y');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part MergeSort Desc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'C':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part QuickSort Asc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						PartQuickSort(main_arr, arraySize,'A');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part QuickSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'D':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part QuickSort Desc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						PartQuickSort(main_arr, arraySize,'D');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part QuickSort Desc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 'E':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part HeapSort Asc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						PartHeapSort(main_arr, arraySize,'A');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part HeapSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'F':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part HeapSort Desc start: " << std::ctime(&start_sort) << std::endl;

                        cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
						PartHeapSort(main_arr, arraySize,'D');

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part HeapSort Desc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;

                case 'W':
				exit(0);
				break;
			default:
				cout << "Nie ma takiej opcji w menu."<< flush;
				Sleep(750);
				break;
		}
	} while (v_znak!='W');
//-------------------------------------------------------------------------------------------
    return 0;
}

