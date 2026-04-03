class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,double>> pos_time = {};

        for(int i = 0; i < position.size(); i++){
            double time = static_cast<double>(target-position[i]) / speed[i];
            pos_time.push_back(std::make_pair(position[i],time));
        }

        std::ranges::sort(pos_time, std::ranges::greater{});

        vector<double> time_stack = {};

        for(int i = 0; i < pos_time.size(); i++){
            time_stack.push_back(pos_time[i].second);

            size_t stack_size = time_stack.size();

            if(stack_size >= 2 && time_stack[stack_size-1] <= time_stack[stack_size-2]){
                time_stack.pop_back();
            }
        }

        return time_stack.size();
    }
};
