//Hard
//dp
//O(NM)

class Solution {
public:

    int cache[1010][1010];

    void init(){
        for(int i=0;i<1010;++i)
            for(int j=0;j<1010;++j)cache[i][j]=-1;
    }

    int dp(int s_idx,int t_idx,string& s,string& t){

        if(cache[s_idx][t_idx]!=-1)
            return cache[s_idx][t_idx];
        
        if(t_idx==t.size())
            return cache[s_idx][t_idx]=1;
        if(s_idx==s.size())
            return cache[s_idx][t_idx]=0;
        

        int ret=0;
        if(s[s_idx]==t[t_idx]){
            ret=dp(s_idx+1,t_idx+1,s,t)+dp(s_idx+1,t_idx,s,t);
        }
        else{
            ret=dp(s_idx+1,t_idx,s,t);
        }

        return cache[s_idx][t_idx]=ret;
    }
    
    int numDistinct(string s, string t) {
        init();
        int ans=dp(0,0,s,t);

        return ans;
    }
};
