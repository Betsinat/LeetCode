class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        int result;
        for(int i = 0 ; i < tokens.size(); i++){
            string token = tokens[i];
            if(tokens[i]!= "+"&& tokens[i]!= "-" && tokens[i]!= "*" && tokens[i]!= "/"){
                 stk.push(stoi(token));
            }
            else{
                 int a = stk.top(); stk.pop();
                 int b = stk.top(); stk.pop();
                 if (token == "+")  result= b + a;
                 else if(token == "*") result = b* a;
                 else if(token == "/") result = b/a;
                 else if(token == "-") result= b-a;
                  stk.push(result);
            }


        }
              return stk.top(); 
        
    }
    

};