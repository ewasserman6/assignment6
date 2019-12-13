/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 6: SortingAlgorithms
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "SortingAlgorithms.h"

using namespace std;

/* This function takes in the file name as a string. It then adds each double to the array.
The sorting algorithms are than called with the time being tracked. */
void SortingAlgorithms::ReadFile(string fileName){
    clock_t start;
    clock_t stop;
    double totalTime;

    string line;
    double num;
    int lineNum = 1;
    int numDoubles;
    string n;
    ifstream inFile;
    inFile.open(fileName.c_str());

    getline(inFile, n);
    numDoubles = atoi(n.c_str());

    BubbleSortArray = new double[numDoubles];
    SelectionSortArray = new double[numDoubles];
    InsertionSortArray = new double[numDoubles];
    QuickSortArray = new double[numDoubles];

    for(int i = 0; i < numDoubles; ++i){
        lineNum++;

        getline(inFile, line);

        try{
            num = atof(line.c_str());
        }
        catch(exception e){
            cout << "Failure" << endl;
            break;
        }

        BubbleSortArray[i] = num;
        SelectionSortArray[i] = num;
        InsertionSortArray[i] = num;
        QuickSortArray[i] = num;

    }
    inFile.close();

    start = clock();
    BubbleSort(BubbleSortArray, numDoubles);
    stop = clock();
    cout << "Start Time: " << start << endl;
    cout << "Stop Time: " << stop << endl;
    totalTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000;
    cout << "Time: " << totalTime << endl;
    cout << endl;

    start = clock();
    SelectionSort(SelectionSortArray, numDoubles);
    stop = clock();
    cout << "Start Time: " << start << endl;
    cout << "Stop Time: " << stop << endl;
    totalTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000;
    cout << "Time: " << totalTime << endl;
    cout << endl;

    start = clock();
    InsertionSort(InsertionSortArray, numDoubles);
    stop = clock();
    cout << "Start Time: " << start << endl;
    cout << "Stop Time: " << stop << endl;
    totalTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000;
    cout << "Time: " << totalTime << endl;
    cout << endl;

    start = clock();
    QuickSort(QuickSortArray, QuickSortArray[0], QuickSortArray[numDoubles], numDoubles);
    stop = clock();
    cout << "Start Time: " << start << endl;
    cout << "Stop Time: " << stop << endl;
    totalTime = (float(stop - start)/CLOCKS_PER_SEC) * 1000;
    cout << "Time: " << totalTime << endl;

}

/* Bubble sort algorithm */
void SortingAlgorithms::BubbleSort(double arr[], int n){
    for(int i = 0; i < n; ++i){
        double temp = 0;
        for(int j = 0; j < n; ++j){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "BubbleSort: " << endl;

    for(int f = 1; f < n+1; ++f){
        cout << arr[f] << endl;
    }

}

/* Selection sort algorithm */
void SortingAlgorithms::SelectionSort(double arr[], int n){
    int minIndex, tmp;
    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    cout << "Selection Sort: " << endl;

    for(int f = 0; f < n; ++f){
        cout << arr[f] << endl;
    }
}

/* Insertion sort algorithm */
void SortingAlgorithms::InsertionSort(double arr[], int n){
    for(int j = 1; j < n; ++j){
        double temp = arr[j];
        int k = j;
        while(k > 0 && arr[k-1] >= temp){
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = temp;
    }
    cout << "Insertion Sort: " << endl;

    for(int i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }
}

/* Quick sort algorithm */
void SortingAlgorithms::QuickSort(double arr[], int left, int right, int n) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
      if (left < j)
            QuickSort(arr, left, j, n);
      if (i < right)
            QuickSort(arr, i, right, n);


    cout << "Quick Sort: " << endl;

    /*for(int f = 0; f < n; ++f){
        cout << arr[f] << endl;
    }*/
}
