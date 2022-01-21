class Solution {
public:
    int next_station;
    
    bool can_travel_back(int i, vector<int>& gas, vector<int>& cost) {
        int current_index = i;
        if(gas[i] < cost[i]) {
            next_station = i%gas.size();
            return false;
        }
        int fuel = gas[i];
        fuel = fuel - cost[i%gas.size()];
        i++;
        fuel = fuel+gas[i%gas.size()];
        while(i%gas.size() != current_index) {
            if(fuel < cost[i%gas.size()]) {
                next_station = i%gas.size();
                return false;
            }
            fuel = fuel - cost[i%gas.size()];
            i++;
            fuel = fuel+gas[i%gas.size()];
        }
        
        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i=0; i<gas.size(); i++) {
            if(can_travel_back(i, gas, cost)) return i;
            else {
                if(next_station > i)
                    i = next_station;
            }
        }
        
        return -1;
    }
};