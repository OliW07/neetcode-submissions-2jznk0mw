class Solution {
public:
    bool isValid(string s) {
        std::stack<char> char_stack = {};

        auto opening_bracket = [](const char &c) -> char {
            if(c == ']') return '[';
            if(c == ')') return '(';
            return '{';
        };

        for(const char &c : s){

            if(c == '[' || c == '(' || c == '{'){

                char_stack.push(c);

            }else if(char_stack.size() == 0 || char_stack.top() != opening_bracket(c)){

                return false;

            }else{

                char_stack.pop();
            }
        }

        return char_stack.empty();
    }
};
