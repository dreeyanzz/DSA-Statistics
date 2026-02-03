#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(void)
{

    int arrSize;
    int *arr;

    printf("Size of the array?: ");
    scanf("%d", &arrSize);

    arr = (int *)malloc(arrSize * sizeof(int));

    int index;
    for (index = 0; index < arrSize; index++)
    {
        printf("Element %d: ", (index + 1));
        scanf("%d", &arr[index]);
    }

    printf("Input array: ");
    printArr(arr, arrSize);
    printf("\n\n");

    int *sorted = bubbleSort(arr, arrSize);
    printf("Sorted: ");
    printArr(sorted, arrSize);
    printf("\n\n");

    double median = getMedian(arr, arrSize);
    printf("Median: ");
    printf("%.2lf", median);
    printf("\n\n");

    int modeSize;
    int *modes = getMode(arr, arrSize, &modeSize);
    printf("Mode size: %d\n", modeSize);
    printf("Mode(s): ");
    printArr(modes, modeSize);

    return 0;
}
