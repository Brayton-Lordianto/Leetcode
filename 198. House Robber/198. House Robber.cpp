class Solution {
public:
    int rob(vector<int>& nums) {
        // same idea to use states. 
        // only thing to recognize is that skipping curr will be max of either since it will not affect 
        int robPrev = 0, skipPrev = 0; 
        for (int num : nums) {
            int skipCurr = max(robPrev, skipPrev); 
            int useCurr = skipPrev + num;
            robPrev = useCurr, skipPrev = skipCurr;
        }
        return max(robPrev, skipPrev); 
    }
};