class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s

        start, max_len = 0, 0

        def expand_around_center(left: int, right: int):
            nonlocal start, max_len
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if right - left + 1 > max_len:
                    start = left
                    max_len = right - left + 1
                left -= 1
                right += 1

        for i in range(len(s)):
            expand_around_center(i, i)       # Odd-length palindrome
            expand_around_center(i, i + 1)   # Even-length palindrome

        return s[start:start + max_len]
