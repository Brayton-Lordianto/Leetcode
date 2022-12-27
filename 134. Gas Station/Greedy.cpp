class Solution {
public:
    // the greedy solution is pretty tricky
    // but you basically want to find where all sum of h(i) is positive
    // where h(i) = cost[i] - gas[i]
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // check valid first
        int sum = 0; 
        for (int i = 0; i < gas.size(); ++i) sum += (gas[i] - cost[i]); 
        if (sum < 0) return -1; 

        int sumOfH = 0; 
        int start = 0; 
        for (int i = 0; i < gas.size(); ++i) {
            // check if the cumulative sum is still positive. 
            int H_i = gas[i] - cost[i];
            sumOfH += H_i; 
            if (sumOfH >= 0) continue; 
            
            // restart the total since it is a new start now. 
            sumOfH = 0; 
            start = i + 1; 
        }
        return start; 
    }
};