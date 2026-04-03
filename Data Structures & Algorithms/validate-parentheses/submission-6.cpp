class Solution {
public:
    bool isValid(string s) {
        std::string char_stack;

        auto opening_bracket = [](const char &c) -> char {
            if(c == ']') return '[';
            if(c == ')') return '(';
            return '{';
        };

        for(const char &c : s){

            if(c == '[' || c == '(' || c == '{'){

                char_stack += c;

            }else if(char_stack.empty()){

                return false;

            }else if(char_stack.back() != opening_bracket(c)){

                return false;

            }else{

                char_stack.pop_back();
            }
        }

        return char_stack.empty();
    }
};