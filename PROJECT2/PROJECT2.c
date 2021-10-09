#include <stdio.h>
#include <stdlib.h>

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
    int T = 0;
    int N = 0;
    int C[100000];
    int result = 0;
    int sum = 0;
    freopen("shopping.txt", "r", stdin);
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &C[j]);
        }

        quickSort(C, 0, N - 1);
        if (N % 3 == 0) {
            for (int i = 0; i < N; i++)
            {
                if (i % 3 == 0) {
                    C[i] = 0;
                }
                result += C[i];
            }
        }
        else if (N % 3 == 1) {
            for (int i = 1; i < N; i++) {
                sum = C[0];
                if (i % 3 == 1) {
                    C[i] = 0;
                }
                result += C[i];
            }
            result = result + sum;
        }
        else if (N % 3 == 2) {
            for (int i = 2; i < N; i++) {
                sum = C[0] + C[1];
                if (i % 3 == 2) {
                    C[i] = 0;
                }
                result += C[i];
            }
            result = result + sum;
        }
        printf("%d\n", result);
        sum = 0;
        result = 0;

    }
}