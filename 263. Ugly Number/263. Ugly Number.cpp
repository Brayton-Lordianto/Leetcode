class Solution {
public:
    bool isUgly(int n) {
        // keep dividing by 2, 3, 5 
        // if the end result is 1 then we know that there are no other prime factors
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3; 
        while (n % 5 == 0) n /= 5; 
        return n == 1; 
    }
};