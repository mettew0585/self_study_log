//dp
//dungeon game

const int INF=21e8;

class Solution {
public:
    int N,M;
    int cache[210][210];

    void init(){
        for(int i=0;i<N;++i)for(int j=0;j<M;++j)cache[i][j]=-1;
    }

    int dp(int y,int x,vector<vector<int>>& dungeon){

        if(cache[y][x]!=-1)
            return cache[y][x];

        if(y==N-1&&x==M-1){
            if(dungeon[y][x]>0)
                return 1;
            else
                return -dungeon[y][x]+1;
        }

        int ret=INF;
        if(y<N-1){
            if(dp(y+1,x,dungeon)-dungeon[y][x]>0)ret=min(ret,dp(y+1,x,dungeon)-dungeon[y][x]);
            else ret=1;
        }
        if(x<M-1){
            if(dp(y,x+1,dungeon)-dungeon[y][x]>0)ret=min(ret,dp(y,x+1,dungeon)-dungeon[y][x]);
            else ret=1;
        }
        
        return cache[y][x]=ret;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        N=dungeon.size(),M=dungeon[0].size();
        init();
        int answer=dp(0,0,dungeon);

        return answer;
    }
};
