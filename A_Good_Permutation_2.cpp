#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    set<int> available;
    for (int i = 1; i <= N; ++i) {
        available.insert(i);
    }

    vector<int> P;
    for (int i = 1; i <= N; ++i) {
        for (auto it = available.begin(); it != available.end(); ++it) {
            int current = *it;
            bool valid = true;
            for (int j = 0; j < M; ++j) {
                int len = A[j];
                if (P.size() >= len - 1) {
                    bool formsSubsequence = true;
                    for (int k = 0; k < len - 1; ++k) {
                        if (P[P.size() - (len - 1) + k] != k + 1) {
                            formsSubsequence = false;
                            break;
                        }
                    }
                    if (formsSubsequence && current == len) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                P.push_back(current);
                available.erase(it);
                break;
            }
        }
    }
    
    if (P.size() != N) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << P[i];
        }
        cout << endl;
    }
    
    return 0;
}
