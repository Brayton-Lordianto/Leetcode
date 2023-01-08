class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        mp = defaultdict()
        for i in range(len(s)): 
            mp[s[i]] = i 
        
        res = []
        currFarthest = 0 
        startIdx = 0
        for i in range(len(s)):
            c = s[i]
            currFarthest = max(currFarthest, mp[c])
            if currFarthest != i: 
                continue
            res.append(currFarthest - startIdx + 1)
            currFarthest = 0
            startIdx = i + 1
        return res