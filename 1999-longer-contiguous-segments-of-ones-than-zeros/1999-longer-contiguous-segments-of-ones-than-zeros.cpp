class Solution {
public:
    bool checkZeroOnes(string s) {
        int left = 0;
        int right = 1;
        int current1 = 0;
        int current0 = 0;
        int max1 = 0;
        int max0 = 0;
        if (s.size() == 1) {
            return s[0] == '1';
        }
        if (s.size() > 0) {
            if (s[0] == '1') {
                current1 = 1;
                max1 = 1;
            } else {
                current0 = 1;
                max0 = 1;
            }
        }
        
        while (right < s.size()) {
            if (s[left] == '1' && s[right] == '1') {
                current1++;
                if (current1 > max1) max1 = current1;
                left++;
                right++;
            }
            else if (s[left] == '0' && s[right] == '0') {
                current0++;
                if (current0 > max0) max0 = current0;
                left++;
                right++;
            }
            else {
                if (s[right] == '1') {
                    current1 = 1;
                    if (current1 > max1) max1 = current1;
                } else {
                    current0 = 1;
                    if (current0 > max0) max0 = current0;
                }
                left = right;
                right++;
            }
        }
        
        return max1 > max0;
    }
};