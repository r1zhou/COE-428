#include "mySort.h"
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int left[n1], right[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) myCopy(&arr[l + i], &left[i]);
    for (j = 0; j < n2; j++) myCopy(&arr[m + 1+ j], &right[j]);
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (myCompare(left[i], right[j]) <= 0) {
            myCopy(&left[i], &arr[k]);
            i++;
        }
        else {
            myCopy(&right[j], &arr[k]);
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        myCopy(&left[i], &arr[k]);
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        myCopy(&right[j], &arr[k]);
        j++;
        k++;
    }
}

void mySort(int array[], unsigned int first, unsigned int last) {
    
    if (first < last)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = first+(last-first)/2;
 
        // Sort first and second halves
        mySort(array, first, middle);
        mySort(array, middle+1, last);
 
        merge(array, first, middle, last);
    }
}
