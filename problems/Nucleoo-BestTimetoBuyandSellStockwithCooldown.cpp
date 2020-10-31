class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int buy=INT_MAX; int sell=0;
        int prev_sell=0; int prev_buy;
        for(auto p:prices){
            prev_buy=buy;
            buy=min(buy, p-prev_sell);
            prev_sell=sell;
            sell=max(sell, p-prev_buy);
        }
        return sell;
    }
};
