/**
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    size_t l = s.length();
    vector<bool> dp(l + 1, false);
    dp[0] = true;
    for (int i = 0; i < l; i++) {
      for (int j = i; j >= 0; j--) {
        string sub = s.substr(j, i - j + 1);
        if (dict.find(sub) != dict.end() && dp[j]) {
          dp[i+1] = true;
          break;
        }
      }
    }
    return dp[l];
  }
};