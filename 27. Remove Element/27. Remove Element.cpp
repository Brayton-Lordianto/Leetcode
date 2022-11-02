#include <vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // you can go from the backward 
        int l = nums.size() - 1, r = nums.size() - 1, k = nums.size(); 
        while (l >= 0) {
            if (nums[l] == val) {
                nums[l] = nums[r];
                --r;
                --k;
            }
            --l;
        }
        return k; 
    }
};