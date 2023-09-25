#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

#define pii pair<int,int>
#define Y first
#define X second

using namespace std;

const int INF =21e8;
const pii dir_mask[4]={{-1,0},{0,1},{1,0},{0,-1}};

int dist[30][30][4];
int N;

struct info{
    int cost;
    int y,x,d;
};

struct cmp{
    bool operator()(info a,info b){
        return b.cost<a.cost;
    }
};

bool in_range(int y,int x){
    return (y>=0&&y<N&&x>=0&&x<N);
}

void init(){
    for(int y=0;y<30;++y)
        for(int x=0;x<30;++x)
            for(int d=0;d<4;++d)dist[y][x][d]=INF;
}

int dijkstra(vector<vector<int>>& board){
    init();
    priority_queue<info,vector<info>,cmp> pq;
    pq.push({0,0,0,0});pq.push({0,0,0,1});pq.push({0,0,0,2});pq.push({0,0,0,3});
    dist[0][0][0]=dist[0][0][1]=dist[0][0][2]=dist[0][0][3]=0;
    
    while(!pq.empty()){
        info tmp=pq.top();
        int cost=tmp.cost,y=tmp.y,x=tmp.x,d=tmp.d;
        pq.pop();
        
        if(cost>dist[y][x][d])continue;
        
        for(int dir=0;dir<4;++dir){
            int ny=y+dir_mask[dir].Y,nx=x+dir_mask[dir].X;
            if(!in_range(ny,nx)||board[ny][nx]==1)continue;
            int nxt_cost=0;
            if(dir==d)nxt_cost=100;
            else nxt_cost=600;
            
            if(dist[ny][nx][dir]>cost+nxt_cost){
                dist[ny][nx][dir]=cost+nxt_cost;
                pq.push({cost+nxt_cost,ny,nx,dir});
            }
        }
    }
    
    return min({dist[N-1][N-1][0],dist[N-1][N-1][1],dist[N-1][N-1][2],dist[N-1][N-1][3]});
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    N=board.size();
    answer=dijkstra(board);
      
    return answer;
}
