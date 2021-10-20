class Solution {
public:
    int getStartOfArray(vector<int> &reqGas) {
        int n = reqGas.size();
        int sum = 0;
        int start = 0;
        
        for(int i=0; i<n; i++) {
            sum += reqGas[i];
            if(sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        
        return start;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        
        if(totalCost > totalGas) return -1;
        
        vector<int> reqGas(gas.size());
        for(int i=0; i<gas.size(); i++) {
            reqGas[i] = gas[i] - cost[i];
        }
        
        return getStartOfArray(reqGas);
    }
};