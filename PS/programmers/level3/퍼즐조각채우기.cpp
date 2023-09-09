//230909
//빡구현

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define pii pair<int,int>
#define Y first
#define X second

using namespace std;

const int INF=21e8;
const pii dir_mask[4]={{-1,0},{0,1},{1,0},{0,-1}};

int N,M;
bool vis[55][55];
vector<vector<vector<vector<int>>>> blocks;
vector<vector<vector<int>>> cell_brd;

bool in_range(int y,int x){
    return (x>=0&&x<N&&y>=0&&y<M);
}

void dfs(int sy,int sx,int y,int x,vector<pii>& v,const vector<vector<int>>& table){
    
    v.push_back({y-sy,x-sx});
    vis[y][x]=true;
    
    for (int d=0;d<4;++d){
        int ny=y+dir_mask[d].Y,nx=x+dir_mask[d].X;
        
        if(!in_range(ny,nx)||table[ny][nx]==0||vis[ny][nx])
            continue;
        
        dfs(sy,sx,ny,nx,v,table);
    }
}

vector<vector<int>> pos2block_form(vector<pii>& pos_v){
    
    int min_y=INF,max_y=-INF,min_x=INF,max_x=-INF;
    for(int i=0;i<pos_v.size();++i){
        int y=pos_v[i].Y,x=pos_v[i].X;
        
        min_y=min(min_y,y),max_y=max(max_y,y);
        min_x=min(min_x,x),max_x=max(max_x,x);
    }
    
    for(int i=0;i<pos_v.size();++i){
        int y=pos_v[i].Y,x=pos_v[i].X;
        pos_v[i]={y-min_y,x-min_x};
    }
    
    vector<vector<int>> brd=vector<vector<int>> (max_y-min_y+1,
                                                vector<int> (max_x-min_x+1,0));
    
    for(pii pos:pos_v)
        brd[pos.Y][pos.X]=1;
    
    
    return brd;
}

void make_cell_brd(const vector<vector<int>>& game_board){
    
    int r=game_board.size(),c=game_board[0].size();
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x)
            vis[y][x]=false;
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x){
            if(game_board[y][x]==1&&!vis[y][x]){
                vector<pii> pos_v;
                dfs(y,x,y,x,pos_v,game_board);
                cell_brd.push_back(pos2block_form(pos_v));
            }
        }
}

vector<vector<int>> rotate(vector<vector<int>> brd){
    int r=brd.size(),c=brd[0].size();
    vector<vector<int>> ret=vector<vector<int>> (c,vector<int> (r,0));
    
    for(int y=0;y<r;++y)
        for(int x=0;x<c;++x)
            ret[x][r-1-y]=brd[y][x];
    
    return ret;
}

void make_blocks(const vector<vector<int>>& table){
    
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x){
            vector<pii> pos_v;
            if(table[y][x]==1&&!vis[y][x]){
                dfs(y,x,y,x,pos_v,table);
                vector<vector<int>> brd=pos2block_form(pos_v);
                vector<vector<vector<int>>> block;
                block.push_back(brd);
                for(int i=1;i<=3;++i){
                    vector<vector<int>> to_push=rotate(block[i-1]);
                    block.push_back(to_push);
                }
                blocks.push_back(block);
            }
        }
}

bool same(vector<vector<int>>& a,vector<vector<int>>& b){
    if(a.size()!=b.size() || a[0].size()!=b[0].size())
        return false;
    
    int N=a.size(),M=a[0].size();
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x)
            if(a[y][x]!=b[y][x])
                return false;
    
    return true;
}

int empty_count(vector<vector<int>> brd){
    int ret=0;
    for(int y=0;y<brd.size();++y)
        for(int x=0;x<brd[y].size();++x)
            if(brd[y][x]==1)++ret;
    return ret;
}

int match(){
    
    int ret=0;
    vector<bool> used(blocks.size()+5,false);
    for(vector<vector<int>> to_match : cell_brd){
        
        for(int i=0;i<blocks.size();++i){
            if(used[i])continue;
            
            for(int j=0;j<4;++j){
                if(same(to_match,blocks[i][j])){
                    used[i]=true;
                    ret+=empty_count(to_match);
                    break;
                }
            }
            if(used[i])break;
        }
    }
    
    return ret;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    N=game_board.size(),M=game_board[0].size();
    
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x)
            game_board[y][x]^=1;
    make_blocks(table);
    make_cell_brd(game_board);
    answer=match();
    
    
    return answer;
}
