/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 6: SortingAlgorithms

*/

#include <iostream>
#include <string>

using namespace std;

class SortingAlgorithms{
public:
    void BubbleSort(double arr[], int n);
    void SelectionSort(double arr[], int n);
    void InsertionSort(double arr[], int n);
    void QuickSort(double arr[], int left, int right, int n);
    void ReadFile(string fileName);

    // create pointer of array of doubles
    double *BubbleSortArray;
    double *InsertionSortArray;
    double *SelectionSortArray;
    double *QuickSortArray;

};
