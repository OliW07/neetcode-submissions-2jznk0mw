class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res = {};
        stack<int> temp_stack;
        stack<int> idx_stack;

        for(int i = 0; i < temperatures.size(); i++){

            res.push_back(0);

            while(!temp_stack.empty() && temp_stack.top() < temperatures[i]){

                res[idx_stack.top()] = i - idx_stack.top();
                temp_stack.pop();
                idx_stack.pop();

            }
                
            temp_stack.push(temperatures[i]);
            idx_stack.push(i);
        }

        return res;
    }
};
