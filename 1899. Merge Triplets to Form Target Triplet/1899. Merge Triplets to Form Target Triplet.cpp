class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int r0 = 0, r1 = 0, r2 = 0;
        for (auto& triplet : triplets) {
            int a = triplet[0], b = triplet[1], c = triplet[2];

            // the selection of the triplet is itself
            // if it is feasible to be used
            if (a > x || b > y || c > z) continue; 
            r0 = max(r0, a), r1 = max(r1, b), r2 = max(r2, c);
            if (r0 == x && r1 == y && r2 == z) return true;
        }
        return (r0 == x && r1 == y && r2 == z); 
    }
};