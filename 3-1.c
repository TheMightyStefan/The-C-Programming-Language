#include <stdio.h>
#include <stdlib.h>

void sort(int v[], int n) {

    for (int index = 0; index < n; index++) 
        if (v[index] > v[index + 1]) {
            int aux = v[index];
            v[index] = v[index + 1];
            v[index + 1] = aux;
        }
}

int binsearch(int x, int v[], int n) {

    sort(v, n);
    
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

    int target = 2;
    int array[5] = {1,2,3,5,6};
   
    (binsearch(target, array, 9) != -1) ? 
        printf("\n%d\n", binsearch(target, array, 9)) : printf("\nNot Found\n");

    return 0;
}    
