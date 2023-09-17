//dp
//O(NM)

#define pii pair<int,int>
#define Y first
#define X second

const pii dir_mask[4]={{-1,0},{0,1},{1,0},{0,-1}};

class Solution {
public:
    int N,M;
    int cache[210][210];

    bool in_range(int y,int x){
        return (y>=0&&y<N&&x>=0&&x<M);
    }

    void init(){
        for(int y=0;y<210;++y)
            for(int x=0;x<210;++x)
                cache[y][x]=-1;
    }

    int dp(int y,int x,vector<vector<int>>& matrix){
        if(cache[y][x]!=-1)
            return cache[y][x];

        int max_val=0;
        for(int d=0;d<4;++d){
            int ny=y+dir_mask[d].Y,nx=x+dir_mask[d].X;
            if(!in_range(ny,nx)||matrix[ny][nx]<=matrix[y][x])continue;
            max_val=max(max_val,dp(ny,nx,matrix));
        }
        return cache[y][x]=max_val+1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=1;
        N=matrix.size(),M=matrix[0].size();
        init();
        for(int y=0;y<N;++y)
            for(int x=0;x<M;++x)
                ans=max(ans,dp(y,x,matrix));

        return ans;
    }
};
