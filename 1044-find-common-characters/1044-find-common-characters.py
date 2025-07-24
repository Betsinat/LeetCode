class Solution(object):
    def commonChars(self, words):
        common = Counter(words[0])
        for word in words[1:]:
            common &= Counter(word)
        res = list(common.elements())
        return res
      