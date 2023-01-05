class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int,int> counts; 
        for (int card: hand) counts[card]++;
        sort(hand.begin(), hand.end()); 

        for (int val : hand) {
            if (counts[val] == 0) continue;
            // since we are going sorted, this val MUST be able to be the first in the group
            int groups = counts[val];
            for (int i = 0; i < groupSize; ++i) {
                if (counts[val + i] < groups) return false;
                counts[val + i] -= groups; 
            }
        }

        return true; 
    }
};