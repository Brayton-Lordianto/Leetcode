class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones) pq.push(stone);
        while (pq.size() > 1) {
            int heaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();
            
            if (heaviest == secondHeaviest) continue; 
            pq.push(heaviest - secondHeaviest); 
        }
        return pq.size() ? pq.top() : 0; 
    }
};