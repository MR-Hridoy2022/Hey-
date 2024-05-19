#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *A = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array A
    qsort(A, M, sizeof(int), compare);

    // Initialize the permutation array P
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        P[i] = i + 1;
    }

    // Check feasibility and create the lexicographically smallest permutation
    int impossible = 0;
    for (int i = 0; i < M; i++) {
        int length = A[i];
        if (length == 1) {
            impossible = 1;
            break;
        }
        for (int j = 0; j <= N - length; j++) {
            int is_valid = 0;
            for (int k = 1; k < length; k++) {
                if (P[j + k - 1] + 1 != P[j + k]) {
                    is_valid = 1;
                    break;
                }
            }
            if (!is_valid) {
                impossible = 1;
                break;
            }
        }
        if (impossible) break;
    }

    if (impossible) {
        printf("-1\n");
    } else {
        for (int i = 0; i < N; i++) {
            printf("%d ", P[i]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(A);
    free(P);

    return 0;
}
