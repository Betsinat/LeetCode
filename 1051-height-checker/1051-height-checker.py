class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        sum = 0
        for i in range(len(heights)):
            if expected[i] != heights[i]:
                sum += 1
        return sum
            
        