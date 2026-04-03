class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> num_stack = {};

        auto isoperator = [](const string& s) -> bool {
            return s == "+" || s == "-" || s == "/" || s == "*";
        };

        for(const string &s : tokens){
            if(isoperator(s)){

                int cur_num = num_stack.top();
                num_stack.pop();

                int next_num = num_stack.top();
                num_stack.pop();
                
                if(s == "+"){
                    num_stack.push(next_num + cur_num);
                }else if(s == "-"){
                    num_stack.push(next_num - cur_num);
                }else if(s == "*"){
                    num_stack.push(next_num * cur_num);
                }else if(s == "/"){
                    num_stack.push(next_num / cur_num);
                }



            }else{
                num_stack.push(stoi(s));
            }
        }

        return num_stack.top();
    }
};
