int countSubstrings(char * s){
    int n = strlen(s);
    int dp[n][n];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dp[i][j] = 1; 
    
    int count = n;
    // length means the offset. so length 1 means length 2 substring.
    // we go by stride so we know that all is covered
    for (int length = 1; length < n; ++length) {
        for (int begin = 0; begin < n; ++begin) {
            int end = begin + length;
            if (end >= n) break; 
            dp[begin][end] = (dp[begin + 1][end - 1] && s[begin] == s[end]);
            if (dp[begin][end]) ++count; 
        }
    }
    
    return count;
}