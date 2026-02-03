#include "helpers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printArr(int *arr, int arrSize)
{
    printf("[ ");
    int index;
    for (index = 0; index < arrSize; index++)
    {
        printf("%d", arr[index]);
        if (index != arrSize - 1)
            printf(", ");
    }
    printf(" ]");
}

int *bubbleSort(int *arr, int arrSize)
{
    int *sorted = (int *)malloc(arrSize * sizeof(int));
    int cpyIndex;
    for (cpyIndex = 0; cpyIndex < arrSize; cpyIndex++)
    {
        sorted[cpyIndex] = arr[cpyIndex];
    }

    bool isSwapped = true;
    while (isSwapped)
    {
        isSwapped = false;

        int index;
        for (index = 0; index < arrSize - 1; index++)
        {
            if (sorted[index] > sorted[index + 1])
            {
                int temp = sorted[index];
                sorted[index] = sorted[index + 1];
                sorted[index + 1] = temp;

                isSwapped = true;
            }
        }
    }

    return sorted;
}

double getMedian(int *arr, int arrSize)
{
    int *sorted = bubbleSort(arr, arrSize);

    double median;

    if (arrSize % 2 == 0)
    {
        int lower = (arrSize / 2) - 1;
        median = ((double)(sorted[lower] + sorted[(lower + 1)])) / 2.0;
    }
    else
        median = (double)sorted[arrSize / 2];

    return median;
}

int getArrMax(int *arr, int arrSize)
{

    int max = 0;
    int i;
    for (i = 0; i < arrSize; i++)
        if (max < arr[i])
            max = arr[i];

    return max;
}

int *getMode(int *arr, int arrSize, int *modeSize)
{
    int *sorted = bubbleSort(arr, arrSize);
    int *noDup = (int *)malloc(sizeof(int));
    noDup[0] = sorted[0];
    int noDupSize = 1;

    // Remove duplicates
    int index;
    int current = sorted[0];
    for (index = 1; index < arrSize; index++)
    {
        if (current == sorted[index])
            continue;

        noDupSize++;
        current = sorted[index];
        noDup = (int *)realloc(noDup, noDupSize * sizeof(int));
        noDup[noDupSize - 1] = current;
    }

    int *countArr = calloc(0, noDupSize * sizeof(int));

    int i;
    for (i = 0; i < noDupSize; i++)
    {
        int j;
        for (j = 0; j < arrSize; j++)
        {
            if (noDup[i] == sorted[j])
            {
                countArr[i]++;
            }
        }
    }

    printf("No Duplicate Array: ");
    printArr(noDup, noDupSize);
    printf("\n");

    printf("Count Array: ");
    printArr(countArr, noDupSize);
    printf("\n");

    int *modeArr = malloc(1);
    int _modeSize = 0;

    int max = getArrMax(countArr, noDupSize);

    for (i = 0; i < noDupSize; i++)
    {
        if (countArr[i] == max)
        {

            _modeSize++;
            modeArr = (int *)realloc(modeArr, _modeSize * sizeof(int));
            modeArr[_modeSize - 1] = sorted[i];
        }
    }

    *modeSize = _modeSize;
    return modeArr;
}
