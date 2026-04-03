class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       for(int i = 0; i < numbers.size()-1; i++){
            for(int j = i+1; j < numbers.size(); j++){

                if(target - numbers[i] == numbers[j]){
                    vector<int> res = {i+1,j+1};
                    return res;
                }
            }
       }

    }
};
