class Solution {
public:
    int minimumChairs(string s) {
        int chairs = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'E') {
                count++;
                if(count > chairs) chairs = count;
            }
            else {
                count--;
            }
        }
        return chairs;
    }
};