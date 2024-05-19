#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    unordered_set<int> A_set;
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
        A_set.insert(A[i]);
    }

    vector<int> perm(N);
    for (int i = 0; i < N; ++i) {
        perm[i] = i;
    }

    int valid_count = 0;

    do {
        vector<int> B = perm;
        vector<bool> in_A(N, false);
        for (int val : A) {
            in_A[val] = true;
        }

        bool is_valid = true;
        for (int i = 0; i < N && !A_set.empty(); ++i) {
            int mex = 0;
            while (mex < N && in_A[mex]) {
                ++mex;
            }
            if (A_set.count(mex)) {
                in_A[mex] = false;
                A_set.erase(mex);
            }
            else if (B[i] != mex) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            ++valid_count;
        }

    } while (next_permutation(perm.begin(), perm.end()));

    cout << valid_count % MOD << endl;

    return 0;
}
