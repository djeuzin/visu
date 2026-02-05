#include "../src/visu.h"
#include <stdio.h>

void bubble_sort(int* v, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-1; j++) {
            if(v[j] > v[j+1])
                swap(v, j, j+1);
        }
    }
}

int main() {
    visu(bubble_sort, "Bubble sort");

    return 0;
}