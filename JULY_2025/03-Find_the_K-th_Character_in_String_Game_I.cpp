#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while(str.size() < k){
            string temp = "";
            for(int i = 0;i < str.size(); i++){
                char nextChar = (str[i] == 'z') ? 'a' : str[i] + 1;
                temp += nextChar;
            }
            str += temp;
        }
        return char(str[k-1]);
    }
};

int main() {
    int k;
    cin>>k;

    Solution sol;
    char result = sol.kthCharacter(k);
    cout << result << endl;

    return 0;
}