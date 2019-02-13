#include "mySort.h"
#include <stdio.h>

void mySort(int array[], unsigned int first, unsigned int last) {
	
	int c, d, t;
	for (c = 1; c <= (last - first); c++) {
    	d = c;
 		
    	while (d > 0 && (myCompare(array[d], array[d-1]) < 0)) {
    		mySwap(&array[d], &array[d-1]);
    		d--;
    	}

	}
}
