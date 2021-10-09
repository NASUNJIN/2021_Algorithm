#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int tmp[100000];

void merge(int A[], int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q) {
        tmp[t++] = A[i++];
    }
    while (j <= r) {
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while (i <= r) {
        A[i++] = tmp[t++];
    }
}
void mergeSort(int A[], int p, int r) {
    int q = (p + r) / 2;
    if (p < r) {
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    int k, z;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            k = A[i];
            A[i] = A[j];
            A[j] = k;
        }
    }
    z = A[i + 1];
    A[i + 1] = A[r];
    A[r] = z;
    return i + 1;
}
void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
int main() {
    int mergeInput[100000], quickInput[100000];
    clock_t MergeStart, QuickStart, MergeEnd, QuickEnd;
    float MergeResult, QuickResult;

    for (int i = 0; i < 10; i++) {
        mergeInput[i] = rand();
        quickInput[i] = mergeInput[i];
    }


    mergeSort(mergeInput, 0, 9);
    printf("Merge Sort : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", mergeInput[i]);
    }
    quickSort(quickInput, 0, 9);
    printf("\nQuick Sort : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", quickInput[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 100000; i++) {
            mergeInput[i] = rand();
            quickInput[i] = mergeInput[i];
        }
        MergeStart = clock();
        mergeSort(mergeInput, 0, 99999);
        MergeEnd = clock();
        MergeResult = (float)(MergeEnd - MergeStart) / CLOCKS_PER_SEC;

        printf("Merge Sort : ");
        printf("%fsec ", MergeResult);
        QuickStart = clock();
        quickSort(quickInput, 0, 99999);
        QuickEnd = clock();
        QuickResult = (float)(QuickEnd - QuickStart) / CLOCKS_PER_SEC;
        printf("Quick Sort : ");
        printf("%fsec ", QuickResult);
        printf("\n");
    }
}