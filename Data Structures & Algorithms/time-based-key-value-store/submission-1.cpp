#include <bits/stdc++.h>

class TimeMap {
private:
    std::array<unordered_map<string,string>,1001> hashmap = {};
    int maxTime = -1;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        maxTime = max(maxTime, timestamp);
        hashmap[timestamp][key] = value;
        
    }
    
    string get(string key, int timestamp) {

        int start_i = min(maxTime, timestamp);

        for(int i = start_i; i >= 1; i--){
            if(hashmap[i].contains(key)){
                return hashmap[i][key];
            }
        }

        return "";
        
    }
};
