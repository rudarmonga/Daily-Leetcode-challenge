#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        char prev = word[0];
        int streak = 0;
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(word[i] == prev) {
                streak++;
            } else {
                count += streak;
                prev = word[i];
                streak = 0;
            }
        }
        count += streak;
        return count;
    }
};

int main() {
    string word;
    cin >> word;

    Solution sol;
    int result = sol.possibleStringCount(word);
    cout << result << endl;

    return 0;
}