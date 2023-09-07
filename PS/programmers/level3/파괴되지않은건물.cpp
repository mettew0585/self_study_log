#include <string>
#include <vector>

using namespace std;

//누적합 
//O(K+ NM)

int sum[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int N=board.size(),M=board[0].size();
    for(vector<int> s : skill){
        int type=s[0],r1=s[1],c1=s[2],r2=s[3],c2=s[4],deg=s[5];
        
        
        if(type==1)
            deg*=(-1);
        sum[r1][c1]+=deg;
        sum[r2+1][c2+1]+=deg;
        sum[r1][c2+1]-=deg;
        sum[r2+1][c1]-=deg;
        
    }
    
    for(int y=0;y<N;++y)
        for(int x=1;x<M;++x)
            sum[y][x]+=sum[y][x-1];
    
    for(int x=0;x<M;++x)
        for(int y=1;y<N;++y)
            sum[y][x]+=sum[y-1][x];
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x){
            if(board[y][x]+sum[y][x]>0)
                ++answer;
        }
    
    return answer;
}
