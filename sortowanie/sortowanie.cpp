// C++ program for implementation of selection sort
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


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
void printArray(unsigned long *array,unsigned long arraySize)
{ 	unsigned long i;
	for (i=0; i < arraySize; i++)
		cout << array[i] << " ";
	cout << endl;
}

void swap(unsigned long *xp, unsigned long *yp)
{ 	unsigned long temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//-------------------------------------------------------------------------------------------
//selection ASC sort function -- all elements
//-------------------------------------------------------------------------------------------
void SelectionSortAsc(unsigned long main_arr[],unsigned long arraySize)
{	unsigned long temp_array[arraySize];
	unsigned long i,j,min,licznik,a;

	for (a=0; a<arraySize; a++)
	{temp_array[a] = main_arr[a];
	}

	for(i=0;i<(arraySize-1);i++)
	{	licznik=i;
		min=temp_array[i];

      for(j=i+1;j<(arraySize);j++) 	//select the min of the rest of array
	  {
		  if(min>temp_array[j])   		//ascending order for descending reverse
		  {	  licznik=j;  			//the position of the min element
			  min=temp_array[j];
		  }
	  }
	  unsigned long temp=temp_array[i] ;
	  temp_array[i]=temp_array[licznik];  		//swap
	  temp_array[licznik]=temp;
	}
	//cout << "Sorted ASC array: \n";
	//printArray(temp_array, arraySize );
}
//-------------------------------------------------------------------------------------------
//SelectionSortDesc
//-------------------------------------------------------------------------------------------
void SelectionSortDesc(unsigned long main_arr[],unsigned long arraySize)
{
	unsigned long temp_array[arraySize];
	unsigned long i,j,min,licznik,a;

	for (a=0; a<arraySize; a++)
	{temp_array[a] = main_arr[a];
	}

	for(i=0;i<(arraySize-1);i++)
	{	licznik=i;
		min=temp_array[i];

      for(j=i+1;j<(arraySize);j++) 	//select the min of the rest of array
	  {
		  if(min<temp_array[j])   		//ascending order for descending reverse
		  {	  licznik=j;  			//the position of the min element
			  min=temp_array[j];
		  }
	  }
	  unsigned long temp=temp_array[i] ;
	  temp_array[i]=temp_array[licznik];  		//swap
	  temp_array[licznik]=temp;
	}
	//cout << "Sorted DESC array: \n";
	//printArray(temp_array, arraySize );
}
//-------------------------------------------------------------------------------------------
//selection ASC sort function -- all parts elements
//-------------------------------------------------------------------------------------------

void PartSelectionSortAsc(unsigned long main_arr[],unsigned long arraySize)
{	unsigned long temp_arraySize = arraySize/5;
	unsigned long temp_array[temp_arraySize];
	unsigned long i,j,min,licznik, start_with, temp;
    int odcinek_pom =0, petla =0;
	double elapsed_seconds;
	time_t start_petla = time(0);
	time_t stop_petla = time(0);

		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = time(0);
                {	if (petla == 0) { start_with=0;} else { start_with = temp_arraySize*petla;}

                    std::cout << "odcinek_pom: "<< odcinek_pom << "; petla: "<< petla <<"; " << "PartSelectionSortAsc start: " << std::ctime(&start_petla) << std::endl;
                    //cout << "petla: "<< petla << std::endl;
                    cout << "start_with: "<< start_with << std::endl;
                    cout << "temp_arraySize: "<< temp_arraySize << std::endl;

                    //cout << "przepisanie danych\n";
                    for(i=0;i<=(temp_arraySize-1);i++)
                    {	temp_array[i] = main_arr[start_with]; start_with++; }
                    //cout << "Part Sorted ASC array: \n";

                    //printArray(array, arraySize );
                    //printArray(temp_array, temp_arraySize );

                    cout <<"Temp arraySize: "<< sizeof(temp_array)/sizeof(temp_array[0]) << std::endl;
                    licznik=0;
                    min=0;
                    //zaczynam sortowac
                    for(i=0;i<temp_arraySize;i++)
                    {	licznik=i;
                        min=temp_array[i];

                        for(j=i;j<temp_arraySize;j++) 	//select the min of the rest of array
                        {
                          if(min>temp_array[j])   			//ascending order for descending reverse
                          {	  licznik=j;  					//the position of the min element
                              min=temp_array[j];
                          }
                        }
                        temp=temp_array[i] ;
                        temp_array[i]=temp_array[licznik];  		//swap
                        temp_array[licznik]=temp;
                    }
                    //cout << "Part Sorted ASC array: \n";
                    //printArray(temp_array, temp_arraySize );
                }
                stop_petla = time(0);
				elapsed_seconds = stop_petla-start_petla;
                std::cout << "PartSelectionSortAsc sort end: " << std::ctime(&start_petla) << std::endl;
			    std::cout << "PartSelectionSortAsc sort elapsed time: " << elapsed_seconds << "s\n"<< std::endl;

			}
		}
}
//-------------------------------------------------------------------------------------------
//selection DESC sort function -- all parts elements
//-------------------------------------------------------------------------------------------
void PartSelectionSortDesc(unsigned long main_arr[],unsigned long arraySize)
{	unsigned long temp_arraySize = arraySize/5;
	unsigned long temp_array[temp_arraySize];
	unsigned long i,j,min,licznik, start_with, temp;
	int petla =0;

	//petla - odcinki
	for (petla =0; petla<5; petla++)
	{	if (petla == 0) { start_with=0;} else { start_with = temp_arraySize*petla;}
		cout << "petla: "<< petla << std::endl;
		cout << "start_with: "<< start_with << std::endl;
		cout << "temp_arraySize: "<< temp_arraySize << std::endl;

		//cout << "przepisanie danych\n";
		for(i=0;i<=(temp_arraySize-1);i++)
		{	temp_array[i] = main_arr[start_with]; start_with++; }
		//cout << "Part Sorted ASC array: \n";

		//printArray(array, arraySize );
		//printArray(temp_array, temp_arraySize );

		cout <<"Temp arraySize: "<< sizeof(temp_array)/sizeof(temp_array[0]) << std::endl;
		licznik=0;
		min=0;
		//zaczynam sortowac
		for(i=0;i<temp_arraySize;i++)
		{	licznik=i;
			min=temp_array[i];

			for(j=i;j<temp_arraySize;j++) 	//select the min of the rest of array
			{
			  if(min<temp_array[j])   			//descending order for descending reverse
			  {	  licznik=j;  					//the position of the min element
				  min=temp_array[j];
			  }
			}
			temp=temp_array[i] ;
			temp_array[i]=temp_array[licznik];  		//swap
			temp_array[licznik]=temp;
		}
		//cout << "Part Sorted ASC array: \n";
		//printArray(temp_array, temp_arraySize );
	}
}
//-------------------------------------------------------------------------------------------
//PartInsertionSortAsc
//-------------------------------------------------------------------------------------------
void PartInsertionSortAsc(unsigned long main_arr[], unsigned long arraySize)
{
	unsigned long temp_array[arraySize];
    unsigned long i, j, temp, start_with;
    unsigned long temp_arraySize = arraySize/5;

	int petla =0;
	//petla - odcinki
	for (petla =0; petla<5; petla++)
	{	if (petla == 0) { start_with=0;} else { start_with = temp_arraySize*petla;}
		cout << "petla: "<< petla << std::endl;
		cout << "start_with: "<< start_with << std::endl;
		cout << "temp_arraySize: "<< temp_arraySize << std::endl;

		//cout << "przepisanie danych\n";
		for(i=0; i<temp_arraySize; i++)
		{	temp_array[i] = main_arr[start_with]; start_with++; }

	    for (i = 1; i < temp_arraySize; i++)
	    {  	temp = temp_array[i];
	        j = i;

	        /* Move elements of arr[0..i-1], that are
	        greater than min, to one position ahead
	        of their current position */
	        while (j > 0 && temp <= temp_array[j-1] && j < temp_arraySize)
	        {
	            temp_array[j] = temp_array[j-1];
	            j = j - 1;
	        }
	        temp_array[j] = temp;
	    }
		//cout << "InsertionAsc array: \n";
		//printArray(temp_array, temp_arraySize );
	}
}

//-------------------------------------------------------------------------------------------
//PartInsertionSortDesc
//-------------------------------------------------------------------------------------------
void PartInsertionSortDesc(unsigned long main_arr[], unsigned long arraySize)
{
	unsigned long temp_array[arraySize];
    unsigned long i, j, temp, start_with;
    unsigned long temp_arraySize = arraySize/5;

	int petla =0;
	//petla - odcinki
	for (petla =0; petla<5; petla++)
	{	if (petla == 0) { start_with=0;} else { start_with = temp_arraySize*petla;}
		cout << "petla: "<< petla << std::endl;
		cout << "start_with: "<< start_with << std::endl;
		cout << "temp_arraySize: "<< temp_arraySize << std::endl;

		//cout << "przepisanie danych\n";
		for(i=0; i<temp_arraySize; i++)
		{	temp_array[i] = main_arr[start_with]; start_with++; }

	    for (i = 1; i < temp_arraySize; i++)
	    {  	temp = temp_array[i];
	        j = i;

	        /* Move elements of arr[0..i-1], that are
	        greater than min, to one position ahead
	        of their current position */
	        while (j > 0 && temp >= temp_array[j-1] && j < temp_arraySize)
	        {
	            temp_array[j] = temp_array[j-1];
	            j = j - 1;
	        }
	        temp_array[j] = temp;
	    }
		//cout << "InsertionDesc array: \n";
		//printArray(temp_array, temp_arraySize );
	}
}
//-------------------------------------------------------------------------------------------
//InsertionAscSort
//-------------------------------------------------------------------------------------------
void InsertionAscSort(unsigned long main_arr[], unsigned long arraySize)
{
	unsigned long temp_array[arraySize];
    unsigned long i, j, temp;

	for (i=0; i<arraySize; i++)
	{temp_array[i] = main_arr[i];	}

    for (i = 1; i < arraySize; i++)
    {  	temp = temp_array[i];
        j = i;

        /* Move elements of arr[0..i-1], that are
        greater than min, to one position ahead
        of their current position */
        while (j > 0 && temp <= temp_array[j-1] && j < arraySize)
        {
            temp_array[j] = temp_array[j-1];
            j = j - 1;
        }
        temp_array[j] = temp;
    }
	//cout << "InsertionAsc array: \n";
	//printArray(temp_array, arraySize );
}

//-------------------------------------------------------------------------------------------
//InsertionDescSort
//-------------------------------------------------------------------------------------------
void InsertionDescSort(unsigned long main_arr[], unsigned long arraySize)
{
	unsigned long temp_array[arraySize];
    unsigned long i, j, temp;

	for (i=0; i<arraySize; i++)
	{temp_array[i] = main_arr[i];	}

    for (i = 1; i < arraySize; i++)
    {  	temp = temp_array[i];
        j = i;

        /* Move elements of arr[0..i-1], that are
        greater than min, to one position ahead
        of their current position */
        while (j > 0 && temp >= temp_array[j-1] && j < arraySize)
        {
            temp_array[j] = temp_array[j-1];
            j = j - 1;
        }
        temp_array[j] = temp;
    }
	//cout << "InsertionDesc array: \n";
	//printArray(temp_array, arraySize );
}
//-------------------------------------------------------------------------------------------
// merge sort
//-------------------------------------------------------------------------------------------
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeAsc(unsigned long arr[], unsigned long left, unsigned long mid, unsigned long right)
{   unsigned long n1 = mid - left + 1;
    unsigned long n2 = right - mid;
    unsigned long i, j, k;
    if(left>=right)
    { return;//returns recursively
    }
    // Create temp arrays
    unsigned long L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for ( i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for ( j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // Initial index of first subarray
     i = 0;
    // Initial index of second subarray
     j = 0;
    // Initial index of merged subarray
     k = left;
    while (i < n1 && j < n2)
    {   if (L[i] <= R[j])
        {   arr[k] = L[i];
            i++;    }
        else
        {   arr[k] = R[j];
            j++;    }
        k++;
    }   // Copy the remaining elements of
        // L[], if there are any
    while (i < n1)
    {   arr[k] = L[i];
        i++;
        k++;    }
        // Copy the remaining elements of
        // R[], if there are any
    while (j < n2)
    {   arr[k] = R[j];
        j++;
        k++;    }
}
//-------------------------------------------------------------------------------------------
void MergeDesc(unsigned long arr[], unsigned long low, unsigned long mid, unsigned long high )
{	unsigned long i=low,j=mid+1,k=0;
	unsigned long temp[high-low+1];

	if(low>=high)
    { return;//returns recursively
    }
	while(i<=mid && j<= high)
	{	if(arr[i]>arr[j])               //comparison step
	        temp[k++]=arr[i++];
	    else
	        temp[k++]=arr[j++];
	}
	while(i<=mid)
	    {
	        temp[k++]=arr[i++];
	    }
	while(j<=high)
	    {
	        temp[k++]=arr[j++];
	    }
	for(i=low;i<=high;i++)
	{
	    arr[i]=temp[i-low];
	}
	return;
}
//-------------------------------------------------------------------------------------------
// left is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void MergeSort(unsigned long arr[],unsigned long left,unsigned long right, char direction)
{
    if(left>=right)
	{	return;//returns recursively
    }
    unsigned long mid = left+(right-1-left)/2;
    if (direction == 'A')
    {	MergeSort(arr,left,mid,direction);
	    MergeSort(arr,mid+1,right,direction);
	    MergeAsc(arr,left,mid,right);
	}
	else
    {	MergeSort(arr,left,mid,direction);
	    MergeSort(arr,mid+1,right,direction);
	    MergeDesc(arr,left,mid,right);
	}
}

void MergeSortArray(unsigned long local_arr[], unsigned long localarraySize, char direction, char partsort)
{
	unsigned long temp_array[localarraySize];
	unsigned long i, start_with;
	unsigned long temp_part_arraySize = localarraySize/5;
	unsigned long temp_part_array[temp_part_arraySize];
	double elapsed_seconds;
	time_t start_petla = time(0);
	time_t stop_petla = time(0);

	cout << "MergeSort temporary size : "<<sizeof(temp_array)/sizeof(temp_array[0]) <<endl;

	if (direction == 'A' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = local_arr[i];	}
		MergeSort(temp_array, 0, localarraySize-1,direction);
		cout << "MergeSort array size : "<<localarraySize <<endl;
		//cout << "MergeSort array: ";
		//printArray(temp_array, localarraySize );
	}
	else if (direction == 'D' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = local_arr[i];	}
		MergeSort(temp_array, 0, localarraySize-1,direction);
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

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,direction);

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

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,direction);
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
// main program
int main()
{ 	char v_znak;
	unsigned long total_numbers =200000;
	unsigned long main_arr[total_numbers];
	//unsigned long main_arr[total_numbers] = {315,309,306,313,358,325,323,321, 115,9,6,13,58,25,23,21, //312,302,307,301,308,322,341,325, 12,2,7,1,8,22,41,25, 362,324,372,334,319,318,319,316, 62,24,72,34,19,18,119,116, //323,321,312,320,317,311,328,341, 123,121,112,120,117,111,128,141, 325,362,358,324,372,334,314,318, //125,162,158,124,172,134,114,118};
	//unsigned long Selection_arr[total_numbers] = {};
	cout <<"Program start\n";
	//unsigned long Insertion_arr[total_numbers] = {};
	//unsigned long Merge_arr[total_numbers] = {};

	unsigned long arraySize = sizeof(main_arr)/sizeof(main_arr[0]);
	time_t start_sort = time(0);
	time_t stop_sort = time(0);
	double elapsed_seconds; // = stop_sort-start_sort;

	for (unsigned long i=0; i<total_numbers; i++)
	{
	    main_arr[i] = rand();
	    //cout << main_arr[i] << " ";
	}

	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout <<"********************* MENU *********************"	<< endl;
		cout << "1. SelectionSortAsc  calego zbioru	"	<< endl;
		cout << "2. SelectionSortDesc calego zbioru	"	<< endl;
		cout << "3. InsertionAscSort  calego zbioru	"	<< endl;
		cout << "4. InsertionDescSort  calego zbioru"	<< endl;
		cout << "5. MergeSort ASC calego zbioru		"	<< endl;
		cout << "6. MergeSort DESC calego zbioru	"	<< endl;
		cout << "A. PartSelectionSortAsc			"	<< endl;
		cout << "B. PartSelectionSortDesc			"	<< endl;
		cout << "C. PartInsertionSortAsc			"	<< endl;
		cout << "D. PartInsertionSortDesc			"	<< endl;
		cout << "E. PartMergeSort ASC				"	<< endl;
		cout << "F. PartMergeSort DESC				"	<< endl;

		cout<<"Wybieram : ";

		v_znak = getchar();
		switch (v_znak)
		{
			case '1':
				//-------------------------------------------------------------------------------------------
					cout <<"arraySize: "<< arraySize << std::endl;
					start_sort = time(0);
					std::cout << "Selection sort start: " << std::ctime(&start_sort) << std::endl;

						SelectionSortAsc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Selection sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '2':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Selection sort start: " << std::ctime(&start_sort) << std::endl;

						SelectionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Selection sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '3':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "InsertionSort ASC sort start: " << std::ctime(&start_sort) << std::endl;

						InsertionAscSort(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Selection sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '4':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "InsertionSort DESC sort start: " << std::ctime(&start_sort) << std::endl;

						InsertionDescSort(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "InsertionSort sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '5':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "MergeSort ASC start: " << std::ctime(&start_sort) << std::endl;

						MergeSortArray(main_arr, arraySize,'A','N');
						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "MergeSort ASC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '6':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "MergeSort DESC start: " << std::ctime(&start_sort) << std::endl;

						MergeSortArray(main_arr, arraySize,'D','N');
						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "MergeSort DESC end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'A':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part Selection Asc sort start: " << std::ctime(&start_sort) << std::endl;

						PartSelectionSortAsc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part Selection Asc sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'B':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part Selection Desc sort start: " << std::ctime(&start_sort) << std::endl;

						PartSelectionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part Selection Desc sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'C':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part Insertion Asc sort start: " << std::ctime(&start_sort) << std::endl;

						PartInsertionSortAsc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part Insertion Asc sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'D':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part Insertion Desc sort start: " << std::ctime(&start_sort) << std::endl;

						PartInsertionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part Insertion Desc sort end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'E':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part MergeSort Asc start: " << std::ctime(&start_sort) << std::endl;

						MergeSortArray(main_arr, arraySize,'A','Y');
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part MergeSort Asc end: " << std::ctime(&stop_sort)<< std::endl;
				    std::cout << "elapsed time: " << elapsed_seconds << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'F':
				//-------------------------------------------------------------------------------------------
					start_sort = time(0);
					std::cout << "Part MergeSort Desc start: " << std::ctime(&start_sort) << std::endl;

						MergeSortArray(main_arr, arraySize,'D','Y');
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = time(0);
					elapsed_seconds = stop_sort-start_sort;
				    std::cout << "Part MergeSort Desc end: " << std::ctime(&stop_sort)<< std::endl;
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

