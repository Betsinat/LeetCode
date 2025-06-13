class Solution {
public:
    int wordLadderSteps(string startWord, string endWord, vector<string>& dictionary) {
        // Make a quick lookup of all valid words
        unordered_set<string> validWords(dictionary.begin(), dictionary.end());
        // If end word isn't in dictionary, impossible
        if(validWords.count(endWord) == 0) return 0;
        // Queue stores {current word, steps taken}
        queue<pair<string, int>> wordsToTry;
        wordsToTry.push({startWord, 1});
        validWords.erase(startWord); // Don't reuse start word
        while(!wordsToTry.empty()) {
            auto current = wordsToTry.front();
            string currentWord = current.first;
            int currentSteps = current.second;
            wordsToTry.pop();
            // Found our target word!
            if(currentWord == endWord) {
                return currentSteps;
            }
            // Try changing each letter in the word
            for(int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                // Try every possible letter a-z
                for(char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    // If this modified word exists in our dictionary
                    if(validWords.count(currentWord)) {
                        wordsToTry.push({currentWord, currentSteps + 1});
                        validWords.erase(currentWord); // Mark as used
                    }
                }
                // Put back original character
                currentWord[i] = originalChar;
            }
        }
        // If we get here, no path exists
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return wordLadderSteps(beginWord, endWord, wordList);
    }
};