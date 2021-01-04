class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> scores;
        int num1 = 0;
        for(auto tok: tokens){
            if(tok == "-"){
                num1 = scores.back();
                scores.pop_back();
                num1 = scores.back() - num1;
                scores.pop_back();
                scores.push_back(num1);
            }
            else if(tok == "+"){
                num1 = scores.back();
                scores.pop_back();
                num1 += scores.back();
                scores.pop_back();
                scores.push_back(num1);
                
            }
            else if(tok == "*"){
                num1= scores.back();
                scores.pop_back();
                num1 = scores.back() * num1;
                scores.pop_back();
                scores.push_back(num1);
            }
            else if(tok == "/"){
                num1 = scores.back();
                scores.pop_back();
                num1 = scores.back() / num1;
                scores.pop_back();
                scores.push_back(num1);           
            }
            else{
                 scores.push_back(stoi(tok));
            }
        }
        return scores.back();
    }
};
