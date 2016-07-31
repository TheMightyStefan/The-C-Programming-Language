#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n) {
    
    int mid = 0; 
    int low = 0;
    int high = n - 1;

    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid]) 
            high = mid - 1;
        else  
            low = mid + 1;
    }

    if (x == v[mid]) 
        return mid;
    else 
        return -1;
}

int main() {

    int target = 5;
    int array[5] = {1,2,3,5,6};
   
    if (binsearch(target, array, 9) > 0)  
        printf("\n%d\n", binsearch(target, array, 9));
    else 
        printf("\nNot Found\n");

    return 0;
}      
