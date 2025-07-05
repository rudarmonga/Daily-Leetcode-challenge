#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1);
        lengths[0] = 1;

        for (int i = 0; i < n; ++i) {
            if (lengths[i] > 1e14) {
                lengths[i + 1] = 1e14;
            } else {
                lengths[i + 1] = lengths[i] * 2;
            }
        }

        long long pos = k;
        int shift = 0;

        for (int i = n - 1; i >= 0; --i) {
            long long half = lengths[i];
            if (pos > half) {
                pos -= half;
                if (operations[i] == 1) shift++;
            }
        }

        char result = 'a' + (shift % 26);
        return result;
    }
};

int main() {
    Solution sol;
    
    long long k;
    int n;

    cin >> k;

    cin >> n;

    vector<int> operations(n);
    for (int i = 0; i < n; ++i) {
        cin >> operations[i];
    }

    char result = sol.kthCharacter(k, operations);

    return 0;
}
