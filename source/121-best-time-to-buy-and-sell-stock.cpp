class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int ret = 0;
        int temp = prices[0];
        
        for (int i=1; i<N; i++) {
            if (temp > prices[i]) {
                temp = prices[i];
            }
            if (ret < prices[i] - temp) {
                ret = prices[i] - temp;
            }
        }
        
        /*
        // reduce the prices into local points. (time limit)
        vector<int> v;
        int condition;
        
        v.push_back(prices[0]);
        if (N>1) {
            condition = prices[1] > prices[0];
            v.push_back(prices[1]);
        }
        
        for (int i=1; i<N-1; i++) {
            if (condition == (prices[i+1] < prices[i])) {
                v.push_back(prices[i]);
                condition = !condition;
            }
        }
        
        v.push_back(prices.back());
        
        N = v.size();
        
        // run the naive solution for local max or min
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (v[j] - v[i] > ret) {
                    ret = v[j] - v[i];
                }
            }
        }
        */
        
        return ret;
    }
};
