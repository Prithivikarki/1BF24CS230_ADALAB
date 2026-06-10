#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[low + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int N;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    int A[N];

    printf("Enter elements:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Original array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    clock_t start = clock();

    mergeSort(A, 0, N - 1);

    clock_t end = clock();

    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nExecution Time = %f seconds\n", time_taken);

    return 0;
}