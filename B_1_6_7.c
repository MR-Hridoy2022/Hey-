#include <stdio.h>
#include <stdint.h>

#define MOD 998244353

// Function to calculate the power of 10
uint64_t power_of_10(int digits) {
    uint64_t result = 1;
    while (digits > 0) {
        result *= 10;
        digits--;
    }
    return result;
}

// Function to solve a single test case
uint64_t solve_case(int A1, int A2, int A3) {
    uint64_t minX1 = power_of_10(A1 - 1);
    uint64_t maxX1 = power_of_10(A1) - 1;
    uint64_t minX2 = power_of_10(A2 - 1);
    uint64_t maxX2 = power_of_10(A2) - 1;
    uint64_t minX3 = power_of_10(A3 - 1);
    uint64_t maxX3 = power_of_10(A3) - 1;

    if (minX1 + minX2 > maxX3 || maxX1 + maxX2 < minX3) {
        return 0;
    }

    // Calculate number of valid (X1, X2) pairs for each valid X3
    uint64_t count = 0;
    for (uint64_t X3 = minX3; X3 <= maxX3; X3++) {
        uint64_t startX1 = (X3 > maxX2) ? (X3 - maxX2) : minX1;
        uint64_t endX1 = (X3 > minX2) ? (X3 - minX2) : maxX1;

        if (startX1 < minX1) startX1 = minX1;
        if (endX1 > maxX1) endX1 = maxX1;

        if (startX1 <= endX1) {
            count = (count + (endX1 - startX1 + 1)) % MOD;
        }
    }

    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A1, A2, A3;
        scanf("%d %d %d", &A1, &A2, &A3);
        printf("%lu\n", solve_case(A1, A2, A3));
    }

    return 0;
}
