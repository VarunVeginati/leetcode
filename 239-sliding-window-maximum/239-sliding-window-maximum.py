class Solution:
    def maxSlidingWindow(self, array: List[int], k: int) -> List[int]:
        heap = []
        result = []
        length = len(array)
        if k >= length:
            result.append(max(array))
            return result
        else:
            for i in range(0,k):
                heapq.heappush(heap,(-array[i],i))
            result.append(-heap[0][0])
            for i in range(k,length):
                # print(result)
                while heap and heap[0][1] <= i - k:
                    heapq.heappop(heap)
                heapq.heappush(heap,(-array[i],i))
                result.append(-heap[0][0])
        return result