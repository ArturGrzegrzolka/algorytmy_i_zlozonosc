// C++ program for implementation of selection sort
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
//#include <stdio.h>
//#include <time.h>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <vector>


using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
//const std::string currentDateTime() {
//    auto      now = time(0);
//    struct tm  tstruct;
//    char       buf[80];
//    tstruct = *localtime(&now);
//    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
//    // for more information about date/time format
//    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
//    return buf;
//}

void f_current_time(string sorting_type, string par1)
{
    time_t curr_time;
	curr_time = time(NULL);

	char *tm = ctime(&curr_time);
	if (par1=="Start" )
        {cout << sorting_type << " start : " << tm; }
    else
        {cout << sorting_type << " stop : " << tm; }
}
//-------------------------------------------------------------------------------------------
// Function to print an array
//-------------------------------------------------------------------------------------------
void printArray(int  *array, int  arraySize)
{ 	int  i;
	for (i=0; i < arraySize; i++)
		cout << array[i] << " ";
	cout << endl;
}

void swap(int  *xp, int  *yp)
{ 	int  temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//-------------------------------------------------------------------------------------------
//selection ASC sort function -- all elements
//-------------------------------------------------------------------------------------------
void SelectionSortAsc(vector <int> *main_arr,int  arraySize)
{	int  temp_array[arraySize];
	int  i,j,min,licznik,a;

	for (a=0; a<main_arr->size(); a++)
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
	  int  temp=temp_array[i] ;
	  temp_array[i]=temp_array[licznik];  		//swap
	  temp_array[licznik]=temp;
	}
	//cout << "Sorted ASC array: \n";
	//printArray(temp_array, arraySize );
}
//-------------------------------------------------------------------------------------------
//SelectionSortDesc
//-------------------------------------------------------------------------------------------
void SelectionSortDesc(int  main_arr[],int  arraySize)
{
	int  temp_array[arraySize];
	int  i,j,min,licznik,a;

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
	  int  temp=temp_array[i] ;
	  temp_array[i]=temp_array[licznik];  		//swap
	  temp_array[licznik]=temp;
	}
	//cout << "Sorted DESC array: \n";
	//printArray(temp_array, arraySize );
}
//-------------------------------------------------------------------------------------------
//selection ASC sort function -- all parts elements
//-------------------------------------------------------------------------------------------

void PartSelectionSortAsc(int  main_arr[],int  arraySize)
{	int  temp_arraySize = arraySize/5;
	int  temp_array[temp_arraySize];
	int  i,j,min,licznik, start_with, temp;
    int odcinek_pom =0, petla =0;
	float elapsed_seconds;
	auto start_petla = std::chrono::system_clock::now();
	auto stop_petla = std::chrono::system_clock::now();

		//petla - odcinki
		for (odcinek_pom =0; odcinek_pom<5; odcinek_pom++)
		{
			cout << "odcinek_pom: "<< odcinek_pom << std::endl;
			for (petla =0; petla<5; petla++)
			{
				start_petla = std::chrono::system_clock::now();
                {	if (petla == 0) { start_with=0;} else { start_with = temp_arraySize*petla;}

                    std::cout << "odcinek_pom: "<< odcinek_pom << "; petla: "<< petla <<"; " ;
                    //std::cout << "PartSelectionSortAsc start: " << std::chrono::system_clock::to_time_t(start_petla) << std::endl;
                    //cout << "petla: "<< petla << std::endl;
                    f_current_time("Part Ascending Selection Sort", "Start");

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
                stop_petla = std::chrono::system_clock::now();
				elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(stop_petla - start_petla).count();
                std::cout << "odcinek_pom: "<< odcinek_pom << "; petla: "<< petla <<"; " ;
                f_current_time("Part Ascending Selection Sort", "Stop");

                //std::cout << "PartSelectionSortAsc sort end: " << std::chrono::system_clock::to_time_t(stop_petla) << std::endl;
			    std::cout << "PartSelectionSortAsc sort elapsed time: " << elapsed_seconds << "ms\n"<< std::endl;

			}
		}
}
//-------------------------------------------------------------------------------------------
//selection DESC sort function -- all parts elements
//-------------------------------------------------------------------------------------------
void PartSelectionSortDesc(int  main_arr[],int  arraySize)
{	int  temp_arraySize = arraySize/5;
	int  temp_array[temp_arraySize];
	int  i,j,min,licznik, start_with, temp;
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
void PartInsertionSortAsc(int  main_arr[], int  arraySize)
{
	int  temp_array[arraySize];
    int  i, j, temp, start_with;
    int  temp_arraySize = arraySize/5;

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
void PartInsertionSortDesc(int  main_arr[], int  arraySize)
{
	int  temp_array[arraySize];
    int  i, j, temp, start_with;
    int  temp_arraySize = arraySize/5;

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
void InsertionAscSort(int  main_arr[], int  arraySize)
{
	int  temp_array[arraySize];
    int  i, j, temp;

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
void InsertionDescSort(int  main_arr[], int  arraySize)
{
	int  temp_array[arraySize];
    int  i, j, temp;

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
void MergeAsc(int  arr[], int  left, int  mid, int  right)
{   int  n1 = mid - left + 1;
    int  n2 = right - mid;
    int  i, j, k;
    if(left>=right)
    { return;//returns recursively
    }
    // Create temp arrays
    int  L[n1], R[n2];
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
void MergeDesc(int  arr[], int  low, int  mid, int  high )
{	int  i=low,j=mid+1,k=0;
	int  temp[high-low+1];

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
void MergeSort(int  arr[],int  left,int  right, char direction)
{
    if(left>=right)
	{	return;//returns recursively
    }
    int  mid = left+(right-1-left)/2;
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

void MergeSortArray(int  local_arr[], int  localarraySize, char direction, char partsort)
{
	int  temp_array[localarraySize];
	int  i, start_with;
	int  temp_part_arraySize = localarraySize/5;
	int  temp_part_array[temp_part_arraySize];
	double elapsed_seconds;
	auto  start_petla = chrono::system_clock::now(); //time(0);
	auto  stop_petla = chrono::system_clock::now(); //time(0);

	//cout << "MergeSort temporary size : "<<sizeof(temp_array)/sizeof(temp_array[0]) <<endl;

	if (direction == 'A' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = local_arr[i];	}
		MergeSort(temp_array, 0, localarraySize-1,direction);
		//cout << "MergeSort array size : "<<localarraySize <<endl;
		//cout << "MergeSort array: ";
		//printArray(temp_array, localarraySize );
	}
	else if (direction == 'D' && partsort =='N')
    {
		for (i=0; i<localarraySize; i++)
		{temp_array[i] = local_arr[i];	}
		MergeSort(temp_array, 0, localarraySize-1,direction);
		//cout << "MergeSort array size : "<<localarraySize <<endl;
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
				start_petla = chrono::system_clock::now(); //time(0);
				//std::cout << "Selection sort start: " << std::chrono::system_clock::to_time_t(start_petla) << std::endl;
                f_current_time("Part Ascending Merge Sort", "Start");

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

				//	cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = local_arr[start_with]; start_with++; }

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,direction);

				stop_petla = chrono::system_clock::now(); //time(0);
				//std::cout << "Selection sort end: " << std::chrono::system_clock::to_time_t(stop_petla)<< std::endl;
                f_current_time("Part Ascending Merge Sort", "Stop");

			    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_petla - start_petla).count() << "ms\n"<< std::endl;
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
				start_petla = chrono::system_clock::now(); //time(0);
				//std::cout << "Part Descending Merge sort start: " << std::chrono::system_clock::to_time_t(start_petla) << std::endl;
                f_current_time("Part Descending Merge Sort", "Start");

					if (odcinek_pom == 0) { start_with=0;} else { start_with = temp_part_arraySize*odcinek_pom;}
					cout << "petla: "<< petla+1 << std::endl;
					cout << "start_with: "<< start_with << std::endl;
					cout << "temp_arraySize: "<< temp_part_arraySize << std::endl;

					cout << "przepisanie danych\n";
					for(i=0; i<temp_part_arraySize; i++)
					{	temp_part_array[i] = local_arr[start_with]; start_with++; }

					MergeSort(temp_part_array, 0, temp_part_arraySize-1,direction);
				stop_petla = chrono::system_clock::now(); //time(0);
				//elapsed_seconds = stop_petla-start_petla;
			    f_current_time("Part Descending Merge Sort", "Stop");
                //std::cout << "Selection sort end: " << std::chrono::system_clock::to_time_t(stop_petla)<< std::endl;
			    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_petla - start_petla).count() << "ms\n"<< std::endl;
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
	int  total_numbers =200000, tmp_max_numbers =50000 ;
	//total_numbers musi dzielic sie bez reszty przez 100000
	//int  main_arr[total_numbers], temp_arr[total_numbers];
	std::vector <int> main_arr; //(total_numbers);
	std::vector <int> temp_arr; //(total_numbers);
	int i,j,k;
	//int  main_arr[total_numbers] = {315,309,306,313,358,325,323,321, 115,9,6,13,58,25,23,21,
	//312,302,307,301,308,322,341,325, 12,2,7,1,8,22,41,25, 362,324,372,334,319,318,319,316, 62,24,72,34,19,18,119,116,
	//323,321,312,320,317,311,328,341, 123,121,112,120,117,111,128,141, 325,362,358,324,372,334,314,318,
	//125,162,158,124,172,134,114,118};
	cout <<"Program start\n";

	int  arraySize = sizeof(main_arr)/sizeof(main_arr[0]);
	double elapsed_seconds;
	auto start_sort = chrono::system_clock::now();
	auto stop_sort  = chrono::system_clock::now();
	auto t_c        = std::chrono::system_clock::to_time_t(start_sort);

	for (int  i=0; i<total_numbers; i++)
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
		cout << "W. Koniec programu				    "	<< endl;

		cout<<"Wybieram : ";

		v_znak = getchar();
		switch (v_znak)
		{
			case '1':
				//-------------------------------------------------------------------------------------------
					cout <<"arraySize: "<< arraySize << std::endl;
					start_sort  = chrono::system_clock::now();
					f_current_time("Ascending Selection Sort", "Start");

						SelectionSortAsc(&main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = chrono::system_clock::now();
				    f_current_time("Ascending Selection sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "ms\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '2':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Descending Selection Sort", "Start");

						SelectionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = chrono::system_clock::now();
					f_current_time("Descending Selection Sort", "Stop");
					std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '3':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Ascending Insertion Sort", "Start");

						InsertionAscSort(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = chrono::system_clock::now();
					f_current_time("Ascending Insertion Sort", "Stop");
					std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '4':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Descending Insertion Sort", "Start");

						InsertionDescSort(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;
					stop_sort = chrono::system_clock::now();
					f_current_time("Descending Insertion Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '5':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Ascending Merge Sort", "Start");
                        if (arraySize > tmp_max_numbers)
                        {i = arraySize/tmp_max_numbers; }
                        else {i = 1; }
                        cout << "i: " << i << endl;
                        for (k=0; k<i; k++)
                        {   cout << "k: " << k << endl;
                            j=0;
                            for (j=0; j<(tmp_max_numbers-1)*(k+1); j++)
                            {   //przepisanie czesci tablicy do tymczasowej tablicy
                                temp_arr[j]=main_arr[j+((tmp_max_numbers-1)*(k+1))];
                            }

                            MergeSortArray(temp_arr, tmp_max_numbers,'A','N');
                        }
						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Ascending Merge Sort", "Stop");
					std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "ms\n"<< std::endl;
					getch();
				system("cls");
				break;
			case '6':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Descending Merge Sort", "Start");
                        if (arraySize > tmp_max_numbers)
                        {i = arraySize/tmp_max_numbers; }
                        else {i = 1; }
                        cout << "i: " << i << endl;
                        for (k=0; k<i; k++)
                        {   cout << "k: " << k << endl;
                            j=0;
                            for (j=0; j<(tmp_max_numbers-1)*(k+1); j++)
                            {   //przepisanie czesci tablicy do tymczasowej tablicy
                                temp_arr[j]=main_arr[j+((tmp_max_numbers-1)*(k+1))];
                            }
                            MergeSortArray(temp_arr, tmp_max_numbers,'D','N');
                        }
						cout << "main array size: "<< sizeof(main_arr)/sizeof(main_arr[0]) << endl;
					stop_sort = chrono::system_clock::now();
					f_current_time("Descending Merge Sort", "Stop");
					std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "ms\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'A':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Selection Sort", "Start");

						PartSelectionSortAsc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Selection Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'B':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Descending Selection Sort", "Start");

						PartSelectionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Descending Selection Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'C':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Insertion Sort", "Start");

						PartInsertionSortAsc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Insertion Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort- start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'D':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Descending Insertion Sort", "Start");

						PartInsertionSortDesc(main_arr, arraySize);
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Descending Insertion Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'E':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Merge Sort", "Start");

						MergeSortArray(main_arr, arraySize,'A','Y');
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Ascending Merge Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
					getch();
				system("cls");
				break;
			case 'F':
				//-------------------------------------------------------------------------------------------
					start_sort = chrono::system_clock::now();
					f_current_time("Part Descending Merge Sort", "Start");

						MergeSortArray(main_arr, arraySize,'D','Y');
						cout << "main array size: "<<sizeof(main_arr)/sizeof(main_arr[0])<<endl;

					stop_sort = chrono::system_clock::now();
					f_current_time("Part Descending Merge Sort", "Stop");
				    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop_sort - start_sort).count() << "s\n"<< std::endl;
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

