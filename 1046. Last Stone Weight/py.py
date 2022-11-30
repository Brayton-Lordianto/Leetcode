class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        heap = []
        heapq.heapify(heap)
        # default is min heap so use negative
        for stone in stones: heapq.heappush(heap, -1 * stone)
        while len(heap) > 1: 
            heaviest = -1 * heapq.heappop(heap)
            second = -1 * heapq.heappop(heap)
            if heaviest == second: continue
            heapq.heappush(heap, -1 * (heaviest - second))
        
        return 0 if len(heap) == 0 else -1 * heapq.heappop(heap)