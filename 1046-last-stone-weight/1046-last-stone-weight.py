import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-s for s in stones]
        heapq.heapify(pq)

        while len(pq) > 1:
            a = -heapq.heappop(pq)
            b = -heapq.heappop(pq)

            if a != b:
                heapq.heappush(pq, -(a - b))

        return -pq[0] if pq else 0