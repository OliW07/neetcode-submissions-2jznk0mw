class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res = {};
        stack<int> temp_stack;


        for(int i = 0; i < temperatures.size(); i++){

            res.push_back(0);

            while(!temp_stack.empty() && temperatures[temp_stack.top()] < temperatures[i]){

                res[temp_stack.top()] = i - temp_stack.top();
                temp_stack.pop();

            }
                
            temp_stack.push(i);
            
        }

        return res;
    }
};
