class Solution {
public:
    //expansion solution. exploits the idea that you can extend only the singles and the doubles to get all palindromes. 
    int countSubstrings(string s) {
        int count = 0; 
        
        for (int i = 0; i < s.size(); ++i) {
            // expand for both as a single and as a couple with it's neighbour
            count += expandFromCenter(s, i, i);
            if (i + 1 >= s.size() || s[i] != s[i+1]) continue; 
            count += expandFromCenter(s, i, i + 1);
        }
        
        return count; 
    }
    
    // end is inclusive
    int expandFromCenter(string& s, int begin, int end) {
        // we already know that the current is a palindrome. We just check for the rest.
        int count = 1; 
        while (begin - 1 >= 0 && end + 1 < s.size() && s[begin-1] == s[end+1]) {
            --begin, ++end, ++count; 
        }
        return count;
    }
};