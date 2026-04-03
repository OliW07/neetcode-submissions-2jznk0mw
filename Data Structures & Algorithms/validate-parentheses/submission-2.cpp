class Solution {
public:
    bool isValid(string s) {
        std::stack<char> char_stack = {};
        std::unordered_map<char,char> brackets_map = {
            {']','['},
            {')','('},
            {'}','{'}
        };

        for(const char &c : s){

            if(c == '[' || c == '(' || c == '{'){

                char_stack.push(c);

            }else if(char_stack.size() == 0){

                return false;

            }else if(char_stack.top() != brackets_map.at(c)){

                return false;

            }else{

                char_stack.pop();
            }
        }

        return char_stack.size() == 0;
    }
};
