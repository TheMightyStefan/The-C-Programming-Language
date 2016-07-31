#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n) {
    
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x != v[mid]) 
            (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
        else 
            return mid;
    }
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
