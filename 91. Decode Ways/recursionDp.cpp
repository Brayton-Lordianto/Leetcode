class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        dp.back() = 1; 
        dp[s.size() - 1] = s.back() == '0' ? 0 : 1;
        populateDp(s, dp, 0);
        return dp[0];
    }
    
    int populateDp(string& s, vector<int>& dp, int begin) {
        if (dp[begin] != -1) return dp[begin];
        char c = s[begin];
        // there is no number of decodings where a number starts with 0
        if (c == '0') {
            dp[begin] = 0;
            return dp[begin];
        }
        
        // calculate for the next as for single, and then as double only if the double is possible
        int res = 0; 
        res += populateDp(s, dp, begin + 1);
        if (begin + 1 < s.size() &&
           c == '1' ||
           c == '2' && s[begin + 1] - '0' <= 6
           ) res += populateDp(s, dp, begin + 2);
        
        // update the dp
        dp[begin] = res;
        return dp[begin]; 
    }
    
};