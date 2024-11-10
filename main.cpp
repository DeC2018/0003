#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1)
                --count[s[l++]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
