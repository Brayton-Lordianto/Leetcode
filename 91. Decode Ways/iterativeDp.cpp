class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        dp.front() = 1; 
        dp[1] = s.front() == '0' ? 0 : 1;
        
        for (int i = 1; i < s.size(); ++i) {
            // is the num of decodings for the back
            int dpIdx = i + 1;
            char c = s[i];
            char prevc = s[i - 1];
            // single. now this is only allowed if the current is not zero.
            int numOfDecodings = 0;
            if (c != '0') numOfDecodings = dp[dpIdx - 1]; 
            // double. since we are checking backwards, the conditions must be placed on the back not the current
            if (
                prevc == '1' || 
                (prevc == '2' && c - '0' <= 6)
               ) numOfDecodings += dp[dpIdx - 2];
            // update dp
            dp[dpIdx] = numOfDecodings;
        } 
        
        
        
        return dp.back();
    }
};