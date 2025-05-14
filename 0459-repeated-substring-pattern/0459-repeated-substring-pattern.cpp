class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string sub;
        for(int i = 1 ; i <= n/2; i++){
            sub = s.substr(0,i);
            string rep = "";
            while(rep.length() < n){
                rep += sub;
            }
            if(rep == s){
                return true;
            }
        }
          return false;


        
        
    }
};