#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        char swapped = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }
        if (swapped) return;
    }
}

int main() {
    int array[] = {2, 1, 3, 4, 7, 6, 5};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);

    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("]\n");
    return 0;
}
