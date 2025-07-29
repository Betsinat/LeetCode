class Solution(object):
    def uniqueMorseRepresentations(self, words):
        wor = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
               "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
               "u", "v", "w", "x", "y", "z"]
        morses = [".-","-...","-.-.","-..",".","..-.","--.","....","..",
                  ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                  "...","-","..-","...-",".--","-..-","-.--","--.."]
        
        code = dict(zip(wor, morses))
        unique = set()
        
        for word in words:
            trans = ""
            for ch in word:
                trans += code[ch]
            unique.add(trans)
        
        return len(unique)

            


        