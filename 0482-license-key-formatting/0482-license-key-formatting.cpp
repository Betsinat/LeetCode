class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string nw = "";
        string format ="";
        int count = 0;
         for (char ch : s) {
            if (ch != '-') {
                nw += toupper(ch);
            }
        }
        for(int i = nw.size() - 1 ; i >=0 ; i--){
            format += nw[i];
            count++;
            if(count == k &&  i != 0){
                format += '-';
                count =0;
            }
        }
        reverse(format.begin(), format.end());
        return format;
    }
};