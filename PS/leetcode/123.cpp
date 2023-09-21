class Solution {
public:
    int cache[100005][5];
    int dp(int day,int transaction,vector<int>& prices){
        if(cache[day][transaction]!=-1)
            return cache[day][transaction];
        if(transaction==0)
            return 0;
        if(day==prices.size())
            return 0;

        int ret=dp(day+1,transaction,prices);
        if(transaction%2==0)
            ret=max(ret,-prices[day]+dp(day+1,transaction-1,prices));
        else
            ret=max(ret,prices[day]+dp(day+1,transaction-1,prices));

        return cache[day][transaction]=ret;
    }
    int maxProfit(vector<int>& prices) {
         
         for(int i=0;i<100005;++i)
            for(int j=0;j<5;++j)cache[i][j]=-1;

        int ans=dp(0,4,prices);

        return ans;
    }
};
