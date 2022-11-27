class Solution {
public:
    int rob(vector<int>& nums) {
        // same as the house robber, except we keep two additional states that will definitely not be met by the first and the second last.
        // therefore we can decide whether to use the last or not. The last can only be used if first and second last are all skipped. 
        int robPrev = 0, skipPrev = 0, endRobPrev = 0, endSkipPrev = 0; 
        for (int i = 0; i < nums.size() - 1; ++i) {
            int robCurr = skipPrev + nums[i];
            int skipCurr = max(robPrev, skipPrev);
            robPrev = robCurr, skipPrev = skipCurr; 
            
            if (i == 0 || i == nums.size() - 2) continue; 
            int endRobCurr = endSkipPrev + nums[i];
            int endSkipCurr = max(endRobPrev, endSkipPrev);
            endRobPrev = endRobCurr, endSkipPrev = endSkipCurr; 
        }
        int skipLast = max(robPrev, skipPrev);
        int robLast = max(endRobPrev, endSkipPrev) + nums.back(); 
        return max(skipLast, robLast); 
    }
};