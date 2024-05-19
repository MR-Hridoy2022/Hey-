#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findMinM(int A) {
    int left = 1, right = 2e5;
    while (left < right) {
        int mid = (left + right) / 2;
        if (mid * (mid - 1) / 2 >= A)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        int A_i = A[i];
        int M = findMinM(A_i);
        if (M * (M - 1) / 2 == A_i) {
            cout << M - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
