class Solution {
public:
    int maxPower(string s) {
        int left = 0;
        int right = 1;
        int maxCount = 1;
        int currentCount = 1;
        while(right < s.size()){
            if(s[left] == s[right]){
                currentCount++;
                maxCount = max(currentCount , maxCount);
                right++;
            }
            else{
                currentCount = 1;
                left = right;
                right++;
            }
        }
           return maxCount;
    }
};