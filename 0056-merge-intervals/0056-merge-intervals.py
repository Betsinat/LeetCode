class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        intervals.sort(key= lambda x : x[0])
        previous =  intervals[0]
        for interval in intervals[1:]:
            if interval[0] <= previous[1]:
                previous[1] = max(interval[1] , previous[1])
            else:
                merged.append(previous)
                previous = interval
        merged.append(previous)
        return merged

